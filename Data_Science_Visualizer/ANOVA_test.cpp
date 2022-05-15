#include<bits/stdc++.h>
#include"anova_test.h"
using namespace std;

struct group{

string s[100];
int cnt;
double grp_avg=0.0;
double bss=0;
double wss=0;
double arr[100];
}grp[100];

int maximum=0;
double grand_avg=0.0;
int total_cnt=0;
double grand_sum=0.0;
double BSS=0,WSS,BMS,WMS;
double TS=0;
double alpha;
void calculation_anovaTable(int line)
{
    for(int i=0;i<line;i++)
    {
        double s=0;
        for(int j=0;j<grp[i].cnt-1;j++)
        {
            s+=grp[i].arr[j];
        }

        grp[i].grp_avg=s/(grp[i].cnt-1);
        //cout<<grp[i].grp_avg<<endl;
    }

     for(int i=0;i<line;i++)
    {
        grp[i].bss=(grp[i].cnt-1)*((grand_avg-grp[i].grp_avg)*(grand_avg-grp[i].grp_avg));
    }

    for(int i=0;i<line;i++)
    {
        BSS+=grp[i].bss;
    }

   // cout<<BSS<<endl;
   BMS=BSS/(line-1);
   //cout<<BMS<<endl;

   for(int i=0;i<line;i++)
   {
       for(int j=0;j<grp[i].cnt-1;j++)
       {
           grp[i].wss+=(grp[i].arr[j]-grp[i].grp_avg)*(grp[i].arr[j]-grp[i].grp_avg);
       }

       WSS+=grp[i].wss;
   }

   //cout<<WSS;

   WMS=WSS/(total_cnt-line);
  // cout<<WMS;

  TS=BMS/WMS;
  cout<<TS<<endl;
  cout<<"Enter the significance level  :"<<endl;
  cin>>alpha;
}


void start_anova_test()
{

    //cout<<"aaaa";

    int line=0;

  fstream newfile;

  newfile.open("aaaa.txt",ios::in);


  if(newfile.is_open())
  {
      string str;
      while(getline(newfile,str))
      {


            stringstream data(str);

            string reg;
            int j=0;

            while(data>>reg)
            {
                grp[line].s[j]=reg;
                //cout<<grp[line].s[j]<<" ";
                j++;
            }
            cout<<endl;

            grp[line].cnt=j;
            //cout<<grp[line].cnt<<endl;
              line++;

      }

  }

  string grp_name[line];

  newfile.close();

  for(int i=0;i<line;i++)

  {
      grp_name[i]=grp[i].s[0];
      //cout<<grp_name[i]<<endl;
  }

  for(int i=0;i<line;i++)

  {
      for(int k=1;k<grp[i].cnt;k++)
      {
          //cout<<grp[i].s[k]<<" ";
          double n;
          n=std:: stof(grp[i].s[k]);
          grp[i].arr[k-1]=n;
          total_cnt++;
          grand_sum+=n;
          cout<<grp[i].arr[k-1]<<" ";
      }

      cout<<endl;
  }
//cout<<grand_sum;
//cout<<total_cnt;
grand_avg=grand_sum/total_cnt;

for(int i=0;i<line;i++)
{
    cout<<setw(20)<<grp_name[i]<<setw(20);
}

cout<<endl;

for(int i=0;i<line;i++)
{
    if((grp[i].cnt-1)>maximum)
        maximum=grp[i].cnt-1;
}
 //cout<<maximum<<endl;

for(int i=0;i<maximum;i++)

  {
      for(int k=0;k<line;k++)
      {

          cout<<grp[k].arr[i]<<setw(20);

      }

      cout<<endl;
  }

   calculation_anovaTable(line);


}
