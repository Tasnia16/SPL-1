#include<bits/stdc++.h>
#include<stdlib.h>
#include<fstream>
#include"GroupData_Classification.h"
#include"hypothesis_test.h"
#include"anova_test.h"
using namespace std;
void classification()
{
fstream newfile;

    int line=0;


  newfile.open("aaaa.txt",ios::in);
  if(newfile.is_open())
  {
      string str;
      while(getline(newfile,str))
      {
          line++;

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
