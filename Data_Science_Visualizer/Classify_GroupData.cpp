#include<bits/stdc++.h>
#include<stdlib.h>
#include"GroupData_Classification.h"
#include"hypothesis_test.h"
using namespace std;
void classification()
{
  // cout<<"Hi";

   FILE *fp;

    if ((fp=fopen("aaaa.txt","r"))==NULL)
    {
        cout<<"Can't open the file";
        cout<<endl;
        exit(1);
    }
char str[2000000];
//string str;
    int line=0;
    while(fscanf(fp,"%[^\n]\n",str)!=EOF)
    {
        line++;
    }
  fclose(fp);
    if(line==2)
    {
        start_hypothesis_test();
    }
}
