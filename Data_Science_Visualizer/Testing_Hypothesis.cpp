#include<bits/stdc++.h>
#include<stdlib.h>
#include"hypothesis_test.h"
using namespace std;

void pair_t_test()
{

}


void start_hypothesis_test()
{
   // double class1[1000];
   vector<string>class1;
   vector<string>class2;

   vector<double>grp1;
   vector<double>grp2;

   string var[2];
   FILE *file;
   if ((file=fopen("aaaa.txt","r"))==NULL)
    {
        cout<<"Can't open the file";
        cout<<endl;
        exit(1);
    }
   int line=0;
   //int p=0;
   char str[1000];
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

    }
    fclose(file);

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
        pair_t_test();
    }


}
