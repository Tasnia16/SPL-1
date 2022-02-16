#include<bits/stdc++.h>
#include<stdlib.h>
#include<vector>
#include<sstream>
#include<string>
#include"regression.h"
using namespace std;
void ShowData(FILE *fp)
{
    vector<string>s;
    vector<double>x;
    vector<double>y;
    vector<pair<double,double>>xy;

    char str[1000];
    int line=0;
     while(fscanf(fp,"%[^\n]\n",str)!=EOF)
    {
        cout<<str<<endl;

        line++;
        if(line!=1)
        {
            stringstream data(str);

            string reg;

            while(data>>reg)
            {
                //cout<<reg<<" ";
                s.push_back(reg);
            }
        }
    }

    for(int i=0;i<s.size();i=i+2)
    {
        double n;
        n=std:: stof(s[i]);
        x.push_back(n);
        //cout<<n<<endl;
    }

     for(int j=1;j<s.size();j=j+2)
    {
        double m;
        m=std:: stof(s[j]);
        y.push_back(m);
        //cout<<n<<endl;
    }
    /*for(int i=0;i<x.size();i++)
        cout<<x[i]<<" ";

        for(int i=0;i<y.size();i++)
        cout<<y[i]<<" ";*/

}

void reg_input()
{
    FILE *fp;
    //string str;
    /*fp=fopen("regression.txt","w");
    if(fp!=NULL)
    {
        cout<<"successfully created file" ;
    }*/

    if ((fp=fopen("regression.txt","r"))==NULL)
    {
        cout<<"Can't open the file";
        exit(1);
    }
    int c=0;
    cout<<"The dataset of the provided file is  : " <<endl ;

    ShowData(fp);
   /* while(fscanf(fp,"%[^\n]\n"str)!=EOF)
    {

    }*/
    //split_data(fp);

}
