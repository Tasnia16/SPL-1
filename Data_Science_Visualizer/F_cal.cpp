#include<bits/stdc++.h>
#include"anova_test.h"
using namespace std;


void result_interpretation(double tabulated_value, double TS)
{
    if(TS>tabulated_value)
    {
        cout<<"There is significant difference among the groups"<<endl;
    }

    else
    {
        cout<<"There is no significant difference among the groups"<<endl;
    }

}
void f_table_calc(int a,int b,double c)
{

     FILE *fp;
   double tabulated_value;
    if ((fp=fopen("f_table.txt","r"))==NULL)
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

      if(t1==b && t2==a)
      {
          tabulated_value=t3;
          break;
      }
    }
    fclose(fp);

    cout<<tabulated_value;

    result_interpretation(tabulated_value,c);

}
