#include<bits/stdc++.h>
#include<stdlib.h>
#include<fstream>
#include"GroupData_Classification.h"
#include"hypothesis_test.h"
#include"anova_test.h"
using namespace std;
void classification()
{
  // cout<<"Hi";

  // FILE *fp;
fstream newfile;


    /*if ((fp=fopen("aaaa.txt","r"))==NULL)
    {
        cout<<"Can't open the file";
        cout<<endl;
        exit(1);
    }*/


//char str[2000000];
//string str;
    int line=0;

   /* while(fscanf(fp,"%[^\n]\n",str)!=EOF)
    {
        line++;
    }
  fclose(fp);*/

  newfile.open("aaaa.txt",ios::in);
  if(newfile.is_open())
  {
      string str;
      while(getline(newfile,str))
      {
          line++;
          //cout<<str<<endl;

         /* stringstream data(str);
          string reg;

          while(data>>reg)
            {
                cout<<reg<<endl;

            }*/
      }
  }
  newfile.close();
    if(line==2)
    {
        start_hypothesis_test();
    }

    else
        {
          start_anova_test();
        }
}
