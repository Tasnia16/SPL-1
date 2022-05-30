#include<bits/stdc++.h>
#include"anova_test.h"
using namespace std;


void result_interpretation(double tabulated_value, double TS,string s)
{
    if(fabs(TS)>tabulated_value)
    {
        cout<<endl<<"          Test statistic "<<fabs(TS)<<">"<<"Tabulated value  " <<tabulated_value<<endl;
        cout<<"                There is significant difference among the "<<s<<"  variables"<<endl;

    }

    else
    {
        cout<<endl<<"           Test statistic "<<fabs(TS)<<"<"<<"Tabulated value  " <<tabulated_value<<endl;
        cout<<"                 There is no significant difference among the "<<s<<" variables"<<endl;
    }

}
void f_table_calc(int a,int b,double c,string s)
{//cout<<a<<" "<<b<<" "<<c;

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

      if(t1==a && t2==b)
      {
          tabulated_value=t3;
          break;
      }
    }
    fclose(fp);

   // cout<<tabulated_value;

    result_interpretation(tabulated_value,c,s);

}
