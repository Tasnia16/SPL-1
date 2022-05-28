#include<bits/stdc++.h>
#include<stdlib.h>
#include"hypothesis_test.h"
using namespace std;

void interpretation(double TS,double tabulated_value)
 {
     if(TS>tabulated_value)
     {
         cout<<"There is significant difference before and after experiment"<<endl;
     }

     else
         cout<<"There is no significant difference before and after experiment"<<endl;
 }

 void z_table(double alpha, double TS)
 {
     fstream newfile1;
  newfile1.open("z_table.txt",ios::in);
  int line=0;
  alpha=1-alpha;
  double tabulated_value;
  cout<<"Significance is :"<<alpha<<endl;
  if(newfile1.is_open())
  {
      string str;
      int i=0;
      while(getline(newfile1,str))
      {
            line++;
            stringstream data(str);

            string reg;
            double store[100];
            int x=0;
            int a=0;
            double temp;
            int flag=0;
            while(data>>reg)
                {
                      a++;
                      if(line==1)
                      {
                          double nn=std:: stod(reg);
                          store[x]=nn;
                          x++;
                      }


                  else
                  {
                      double nn=std:: stod(reg);
                      if(a==1)
                          {
                              temp=nn;
                          }

                          else
                            {

                                if(nn==alpha)
                                 {
                                   tabulated_value=temp+store[a-2];
                                   flag=1;
                                   break;
                                 }
                             }
                  }
                }

            if(flag==1)
                    break;

      }

}

newfile1.close();

cout<<"\n"<<tabulated_value;

interpretation(TS,tabulated_value);



 }

void t_table(double alpha, int DF,double TS)
{

   FILE *fp;
   double tabulated_value;
    if ((fp=fopen("t_table.txt","r"))==NULL)
    {
        cout<<"Can't open the file";
        cout<<endl;
        exit(1);
    }

    char s1[50],s2[50],s3[50];
    int t1;
    double t2,t3;
    fscanf(fp,"%*[^\n]\n");

    while(!feof(fp))
    {
        fscanf(fp,"%s %s  %s", s1,s2,s3);
        t2=std::stod(s2);
        t1=std::stoi(s1);
        t3=std::stod(s3);

      if(t1==DF && t2==alpha)
      {
          tabulated_value=t3;
          break;
      }
    }
    fclose(fp);

    cout<<tabulated_value;

     interpretation(TS,tabulated_value);

}


void  t_z_test(const vector<double>&a, const vector<double>&b)
{
    double Ua=0, Ub=0, TS,n,m,SSa,SSb,SSp,DF,X,Y,sum_diff_a=0,sum_diff_b=0;
     n=a.size();
     m=b.size();
    DF=n+m-2;

     for(int i=0;i<n;i++)
    {
        Ua+=a[i];
    }

    X=Ua/n;

    for(int i=0;i<m;i++)
    {
        Ub+=b[i];
    }

    Y=Ub/m;

    for(int i=0;i<n;i++)
    {
        double temp=0;
        temp+=(a[i]-X);

        sum_diff_a+=pow(temp,2);
    }

    SSa=sum_diff_a/(n-1);

    for(int i=0;i<m;i++)
    {
        double temp=0;
        temp+=(b[i]-Y);

        sum_diff_b+=pow(temp,2);
    }

    SSb=sum_diff_b/(m-1);

    SSp=((n-1)*SSa+(m-1)*SSb)/(n+m-2);

    TS=fabs((X-Y)/(sqrt(SSp*((1/n)+(1/m)))));
    cout<<TS;

   cout<<"Enter the level of significance : ";
   double alpha;
   cin>>alpha;
   alpha=(alpha/2)/100;

   if(DF<30)
   {
       t_table(alpha, DF,TS);
   }

   else
   {
      z_table(alpha,TS);

   }

}


void pair_t_test(const vector<double>&a, const vector<double>&b)
{
    double w=0,mean,TS,n,Sw,ss=0,test, DF, tabulated_value;
    n=a.size();

    DF=n-1;

    for(int i=0;i<n;i++)
    {
        ss+=pow((a[i]-b[i]),2);
        w+=(a[i]-b[i]);
    }

    mean=w/n;
    Sw=sqrt((ss-n*mean*mean)/(n-1));


   test=(sqrt(n)*mean)/Sw;

   TS=fabs(test);

   cout<<TS<<endl;

   //enter the error limit
   cout<<"Enter the level of significance (error limit from 1% to 20%):\n";
   double alpha;
   cin>>alpha;

   alpha=(alpha/2)/100;

   FILE *fp;

    if ((fp=fopen("t_table.txt","r"))==NULL)
    {
        cout<<"Can't open the file";
        cout<<endl;
        exit(1);
    }

    char s1[50],s2[50],s3[50];
    int t1;
    double t2,t3;
    fscanf(fp,"%*[^\n]\n");

    while(!feof(fp))
    {
        fscanf(fp,"%s %s  %s", s1,s2,s3);
        t2=std::stod(s2);
        t1=std::stoi(s1);
        t3=std::stod(s3);

      if(t1==DF && t2==alpha)
      {
          tabulated_value=t3;
          break;
      }

    }
    fclose(fp);

    cout<<tabulated_value;

     interpretation(TS,tabulated_value);

}

void start_hypothesis_test()
{

   vector<string>class1;
   vector<string>class2;

   vector<double>grp1;
   vector<double>grp2;

   string var[2];

   int line=0;

  fstream newfile;

  newfile.open("aaaa.txt",ios::in);
  if(newfile.is_open())
  {
      string str;
      while(getline(newfile,str))
      {
          line++;
          if(line==1)
            {
          stringstream data(str);
          string reg;

          while(data>>reg)
            {
                 class1.push_back(reg);
            }
          }


           else
        {
            stringstream data(str);

            string reg;

            while(data>>reg)
            {
                class2.push_back(reg);
            }
        }

      }

  }

  newfile.close();

    var[0]=class1[0];
    var[1]=class2[0];

   for(int i=1;i<class1.size();i++)
    {
        double n;
        n=std:: stof(class1[i]);
        grp1.push_back(n);
    }

    for(int i=1;i<class2.size();i++)
    {
        double n;
        n=std:: stof(class2[i]);
        grp2.push_back(n);

    }

    cout<<"The provided dataset is :\n\n";

    cout<<var[0]<<setw(20)<<var[1]<<endl;
    for(int t=1;t<class1.size();t++)
    {
        cout<<class1[t]<<setw(20)<<class2[t]<<endl;
    }

    transform(var[0].begin(),var[0].end(),var[0].begin(),::tolower);
     transform(var[1].begin(),var[1].end(),var[1].begin(),::tolower);

    if(var[0]=="before" && var[1]=="after")
    {
        pair_t_test(grp1,grp2);
    }

    else
     {
        t_z_test(grp1,grp2);
     }

}
