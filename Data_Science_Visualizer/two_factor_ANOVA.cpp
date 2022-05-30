#include<bits/stdc++.h>
#include"anova_test.h"
using namespace std;
int grand_count=0;
int row,column=0,line=0;
double all[10000];
double array_2d[1000][1000];
double grand_total=0, ssc=0, msc,dfc,ssr=0,msr,dfr, DF, sse, mse, sst,ra;
double correction_factor;
double fr,fc;
bool isNumber1(const string& str)
{
    for (char const &c : str)
        {
          if (std::isdigit(c) == 0)
           return false;
        }
    return true;
}


void calculation_part()
{
    string s1="column", s2="row";
    correction_factor=(grand_total*grand_total)/grand_count;
    double row_sum[row],col_sum[column];

    for(int i=0;i<row;i++)
    {
        double s=0;
        for(int j=0;j<column;j++)
        {
            s+=array_2d[i][j];
        }
        row_sum[i]=s;
    }

    for(int i=0;i<column;i++)
    {
        double s=0;
        for(int j=0;j<row;j++)
        {
            s+=array_2d[j][i];
        }
        col_sum[i]=s;
    }

     double temp=0;
    for(int i=0;i<column;i++)
    {

        temp+=(col_sum[i]*col_sum[i])/row;
    }

    ssc=temp-correction_factor;
    dfc=column-1;
    msc=ssc/dfc;

    double temp1=0;
    for(int i=0;i<row;i++)
    {

        temp1+=(col_sum[i]*row_sum[i])/column;
    }

    ssr=temp1-correction_factor;
    dfr=row-1;
    msr=ssr/dfr;

   for(int i=0;i<row;i++)
    {

        for(int j=0;j<column;j++)
        {
            sst+=(array_2d[i][j]*array_2d[i][j]);
        }
    }

    sst=sst-correction_factor;

    sse=sst-(ssc+ssr);

    DF=(row-1)*(column-1);

    mse=sse/DF;

    fc=msc/mse;
    fr=msr/mse;

    f_table_calc(DF,dfc,fc,s1);
    f_table_calc(DF,dfr,fr,s2);



}

void two_factor_anova()
{
    cout<<"Work started successfully !"<<endl;

    fstream newfile;

  newfile.open("aaaa.txt",ios::in);

  if(newfile.is_open())
  {
      string str;
      int i=0;
      while(getline(newfile,str))
      {
            line++;
            stringstream data(str);

            string reg;
            cout<<str<<endl;

            while(data>>reg)
                  {
                      if(line==1)
                      {
                          column++;
                      }
                      int bool1;
                      bool1=isNumber1(reg);
                      if(bool1!=0)
                      {
                          double nn=std:: stof(reg);
                          all[i]=nn;
                          i++;
                      }
                  }


      }

      int cnt=i,c=0;
      row=line-1;


      for(int i=0;i<row;i++)
      {
          for(int j=0;j<column;j++)
          {
              array_2d[i][j]=all[c];
              c++;
          }
      }


      grand_count=row*column;

        calculation_part();

  }
}


