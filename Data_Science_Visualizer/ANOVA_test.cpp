#include<bits/stdc++.h>
#include"anova_test.h"
using namespace std;

struct group
{

string s[100];
int cnt;
double grp_avg=0.0;
double bss=0;
double wss=0;
double arr[100];
}
grp[100];

int maximum=0;
double grand_avg=0.0;
int total_cnt=0;
double grand_sum=0.0;
double BSS=0,WSS,BMS,WMS;
double TS=0;
double alpha1;
int string_cnt=0;
int numirator,denominator;

bool isNumber(const string& str)
{
    for (char const &c : str)
        {
          if (std::isdigit(c) == 0)
           return false;
        }
    return true;
}


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

    }

     for(int i=0;i<line;i++)
    {
        grp[i].bss=(grp[i].cnt-1)*((grand_avg-grp[i].grp_avg)*(grand_avg-grp[i].grp_avg));
    }

    for(int i=0;i<line;i++)
    {
        BSS+=grp[i].bss;
    }
   BMS=BSS/(line-1);
   numirator=line-1;
   for(int i=0;i<line;i++)
   {
       for(int j=0;j<grp[i].cnt-1;j++)
       {
           grp[i].wss+=(grp[i].arr[j]-grp[i].grp_avg)*(grp[i].arr[j]-grp[i].grp_avg);
       }

       WSS+=grp[i].wss;
   }

   WMS=WSS/(total_cnt-line);
  denominator=total_cnt-line;
  TS=BMS/WMS;
  cout<<TS<<endl;
  string s3="group";
  f_table_calc(numirator,denominator,TS,s3);
}


void start_anova_test()
{
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
                j++;
            }
            cout<<endl;

            grp[line].cnt=j;

              line++;

              if(line==1)
              {
                  stringstream data(str);

                  string reg;

                  while(data>>reg)
                  {
                      int bool1;
                      bool1=isNumber(reg);
                      if(bool1==0)
                      {
                          string_cnt++;
                      }
                  }

                  if(string_cnt>1)
                    {
                        newfile.close();
                        two_factor_anova();
                        return;
                    }
              }

      }

  }

  string grp_name[line];

  newfile.close();

  for(int i=0;i<line;i++)

  {
      grp_name[i]=grp[i].s[0];
  }


  for(int i=0;i<line;i++)

  {
      for(int k=1;k<grp[i].cnt;k++)
      {
          double n;
          n=std:: stof(grp[i].s[k]);
          grp[i].arr[k-1]=n;
          total_cnt++;
          grand_sum+=n;
          cout<<grp[i].arr[k-1]<<" ";
      }

      cout<<endl;
  }

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
