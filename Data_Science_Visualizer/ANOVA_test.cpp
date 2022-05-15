#include<bits/stdc++.h>
#include"anova_test.h"
using namespace std;

struct group{

string s[100];
int cnt;
double arr[100];
}grp[100];

int maximum=0;

void start_anova_test()
{

    //cout<<"aaaa";

    int line=0;

  fstream newfile;

  newfile.open("aaaa.txt",ios::in);


  if(newfile.is_open())
  {
      string str;
      while(getline(newfile,str))
      {


            stringstream data(str);

            string reg;
            int j=0;

            while(data>>reg)
            {
                grp[line].s[j]=reg;
                //cout<<grp[line].s[j]<<" ";
                j++;
            }
            cout<<endl;

            grp[line].cnt=j;
            //cout<<grp[line].cnt<<endl;
              line++;

      }

  }

  string grp_name[line];

  newfile.close();

  for(int i=0;i<line;i++)

  {
      grp_name[i]=grp[i].s[0];
      //cout<<grp_name[i]<<endl;
  }

  for(int i=0;i<line;i++)

  {
      for(int k=1;k<grp[i].cnt;k++)
      {
          //cout<<grp[i].s[k]<<" ";
          double n;
          n=std:: stof(grp[i].s[k]);
          grp[i].arr[k-1]=n;
          cout<<grp[i].arr[k-1]<<" ";
      }

      cout<<endl;
  }

for(int i=0;i<line;i++)
{
    cout<<setw(20)<<grp_name[i]<<setw(20);
}

cout<<endl;

for(int i=0;i<line;i++)
{
    if((grp[i].cnt-1)>maximum)
        maximum=grp[i].cnt-1;
}
 //cout<<maximum<<endl;

for(int i=0;i<maximum;i++)

  {
      for(int k=0;k<line;k++)
      {

          cout<<grp[k].arr[i]<<setw(20);

      }

      cout<<endl;
  }



}
