#include<bits/stdc++.h>
#include<stdlib.h>
#include"hypothesis_test.h"
using namespace std;

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

    //cout<<SSa;

    for(int i=0;i<m;i++)
    {
        double temp=0;
        temp+=(b[i]-Y);

        sum_diff_b+=pow(temp,2);
    }

    SSb=sum_diff_b/(m-1);

    SSp=((n-1)*SSa+(m-1)*SSb)/(n+m-2);

    TS=(X-Y)/(sqrt(SSp*((1/n)+(1/m))));
    cout<<TS;

   cout<<"Enter the level of significance : ";
   double alpha;
   cin>>alpha;



}

void pair_t_test(const vector<double>&a, const vector<double>&b)
{
    double w=0,mean,TS,n,Sw,ss=0,test, DF;
    n=a.size();

    DF=n-1;

    for(int i=0;i<n;i++)
    {
        ss+=pow((a[i]-b[i]),2);
        w+=(a[i]-b[i]);
    }
    //cout<<w;
    mean=w/n;
    Sw=sqrt((ss-n*mean*mean)/(n-1));
   // cout<<Sw;

   test=(sqrt(n)*mean)/Sw;

   TS=fabs(test);

   cout<<TS;

   //enter the error limit
   cout<<"Enter the level of significance : ";
   double alpha;
   cin>>alpha;

}


void start_hypothesis_test()
{
   // double class1[1000];
   vector<string>class1;
   vector<string>class2;

   vector<double>grp1;
   vector<double>grp2;

   string var[2];
   //FILE *file;
   /*if ((file=fopen("aaaa.txt","r"))==NULL)
    {
        cout<<"Can't open the file";
        cout<<endl;
        exit(1);
    }*/
   int line=0;
   //int p=0;
  // char str[1000];

  fstream newfile;

  newfile.open("aaaa.txt",ios::in);
  if(newfile.is_open())
  {
      string str;
      while(getline(newfile,str))
      {
          line++;
          //cout<<str<<endl;
          if(line==1)
            {
          stringstream data(str);
          string reg;

          while(data>>reg)
            {
                //cout<<reg<<endl;
                 class1.push_back(reg);
            }
          }


           else
        {
            stringstream data(str);

            string reg;

            while(data>>reg)
            {
                //cout<<reg<<" ";
                class2.push_back(reg);
            }
        }

      }





  }
  newfile.close();


  /*
   while(fscanf(file,"%[^\n]\n",str)!=EOF)
    {
        line++;
        if(line==1){

        stringstream data(str);

            string reg;

            while(data>>reg)
            {
                //cout<<reg<<" ";
                class1.push_back(reg);
            }
        }

        else
        {
            stringstream data(str);

            string reg;

            while(data>>reg)
            {
                //cout<<reg<<" ";
                class2.push_back(reg);
            }
        }

    }  */
    //fclose(file);

   /* for(int t=0;t<class1.size();t++)
    {
        cout<<class1[t]<<endl;
    }

    cout<<endl;
     for(int t=0;t<class2.size();t++)
    {
        cout<<class2[t]<<endl;
    }*/

    var[0]=class1[0];
    var[1]=class2[0];

   // cout<<var[0]<<var[1];

   for(int i=1;i<class1.size();i++)
    {
        double n;
        n=std:: stof(class1[i]);
        grp1.push_back(n);
        //cout<<n<<endl;
    }

    for(int i=1;i<class2.size();i++)
    {
        double n;
        n=std:: stof(class2[i]);
        grp2.push_back(n);
        //cout<<n<<endl;
    }

    cout<<"The provided dataset is :\n\n";

    cout<<var[0]<<setw(20)<<var[1]<<endl;
    for(int t=1;t<class1.size();t++)
    {
        cout<<class1[t]<<setw(20)<<class2[t]<<endl;
    }

    transform(var[0].begin(),var[0].end(),var[0].begin(),::tolower);
     transform(var[1].begin(),var[1].end(),var[1].begin(),::tolower);
    //cout<<var[0];

    if(var[0]=="before" && var[1]=="after")
    {
        pair_t_test(grp1,grp2);
    }

    else
     {
        t_z_test(grp1,grp2);
     }


}
