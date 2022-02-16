#include<bits/stdc++.h>
#include<stdlib.h>
#include<vector>
#include<sstream>
#include<string>
#include"regression.h"
using namespace std;
void ShowData(FILE *fp)
{
    char str[1000];
     while(fscanf(fp,"%[^\n]\n",str)!=EOF)
    {
        cout<<str<<endl;
    }

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


}
