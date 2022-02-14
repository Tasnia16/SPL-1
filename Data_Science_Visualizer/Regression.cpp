#include<bits/stdc++.h>
#include<stdlib.h>
#include<vector>
#include"regression.h"
using namespace std;
void reg_input()
{
    FILE *fp;
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

}
