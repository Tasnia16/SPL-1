#include<bits/stdc++.h>
#include<stdlib.h>
#include<vector>
#include<sstream>
#include<string>
#include<math.h>
#include"regression.h"
using namespace std;

void regression_line(double alpha,double beta)
{
    cout<<"The best fitted line is :"<<endl;
    cout<<"y = "<<alpha<<" "<<"+"<<" "<<beta<<"x";
}

void calculation(const vector<double>&x , const vector<double>&y)
{
     double sum_x=0.0;
     double sum_y=0.0;
     double sum_x_square=0.0;
     double sum_y_square=0.0;
     double sum_xy=0.00;
     double mean_x=0.0;
     double mean_y=0.0;
     double alpha=0.0;
     double beta=0.0;
     double correlation=0.0;
     double power_determine=0.0;

     vector<pair<double,double>>xy;

     for(int i=0;i<x.size();i++)
     {
         sum_x=sum_x+x[i];
     }

     double n=x.size();
     mean_x=sum_x/n;

     for(int i=0;i<y.size();i++)
     {
         sum_y=sum_y+y[i];
     }
      double m=x.size();
     mean_y=sum_y/m;
      //cout<<mean_y;
     for(int i=0;i<x.size();i++)
     {
         sum_x_square=sum_x_square+pow(x[i],2);
     }
     for(int i=0;i<y.size();i++)
     {
         sum_y_square=sum_y_square+pow(y[i],2);
     }

      for(int i=0;i<x.size();i++)
     {
         xy.push_back(make_pair(x[i],y[i]));
     }

     for(int i=0;i<xy.size();i++)
     {
         sum_xy=sum_xy+xy[i].first*xy[i].second;
     }
     //cout<<sum_xy;

     beta=(sum_xy-(n*mean_x*mean_y))/(sum_x_square-n*pow(mean_x,2));
     //cout<<beta;
     alpha=mean_y-(beta*mean_x);
     //cout<<alpha;
     correlation=(sum_xy-((sum_x*sum_y)/n))/sqrt((sum_x_square-(pow(sum_x,2)/n))*(sum_y_square-((pow(sum_y,2))/n)) );
     //cout<<correlation;
     power_determine=pow(correlation,2);

     regression_line(alpha,beta);

}

void ShowData(FILE *fp)
{
    vector<string>s;
    vector<double>x;
    vector<double>y;

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

    calculation(x,y);
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
