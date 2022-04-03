#include<bits/stdc++.h>
#include"logictic_reg.h"
using namespace std;

vector<string>s1;
vector<string>s2;
vector<int>binary;
set<string>set1;

void logistic_regression()
{
   FILE *fp;

   if ((fp=fopen("y_variable.txt","r"))==NULL)
    {
        cout<<"Can't open the file";
        cout<<endl;
        exit(1);
    }


    int count=0;

    char split[1000];
    while(fscanf(fp,"%[^\n]\n",split)!=EOF)
    {
        stringstream data(split);
        string y_var;

        while(data>>y_var)
            {
                 //cout<<y_var;
                s1.push_back(y_var);
                count++;
            }
    }
   /* for(int i=0;i<count;i++)
        cout<<s1[i]<<endl;*/

    for (long long int i=0;i<count;i++)
    {
        set1.insert(s1[i]);
    }

    /*for(long long int i=0;i<count;i++)
    {
       if(s1[i]==set1[0]);
         binary[i]=1;

       else if(s1[i]==set1[1])
        binary[i]=0;

    }*/

    set<string>:: iterator itr;

    for(itr=set1.begin();itr!=set1.end();itr++)
    {
        s2.push_back(*itr);
    }

   // cout<<s2[0]<<" "<<s2[1]<<endl;





}

