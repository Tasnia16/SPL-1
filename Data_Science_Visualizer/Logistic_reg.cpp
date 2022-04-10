#include<bits/stdc++.h>
#include"logictic_reg.h"
using namespace std;


double pred();
void Test();

vector<string>s1_y;
vector<string>s2_y;
vector<string>s1_x;
vector<double>x_test;
vector<double>y_test;
vector<double>x_train;
vector<double>binary;
set<string>set1;

const double Threshold = 0.001;
const int max_iteration=500;
double cost=0;
double bias;

double pred()
{

}

void Test()
{

}


 void initialize_weight(double *weight,int factor)
 {

     for(int i=0;i<factor;i++)
     {
         weight[i]=0.01;
     }
 }


 double sigmoid(double z)
 {
     double y;
     y=1/(1+exp(-z));

     return y;
 }



void logistic_regression()
{
   FILE *fp_y;

   if ((fp_y=fopen("y_variable.txt","r"))==NULL)
    {
        cout<<"Can't open the file";
        cout<<endl;
        exit(1);
    }


    int count=0;

    char split_y[1000];
    while(fscanf(fp_y,"%[^\n]\n",split_y)!=EOF)
    {
        stringstream data(split_y);
        string y_var;

        while(data>>y_var)
            {
                 //cout<<y_var;
                s1_y.push_back(y_var);
                count++;
            }
    }
    for(int i=0;i<count;i++)
        cout<<s1_y[i]<<endl;

    for (long long int i=0;i<count;i++)
    {
        set1.insert(s1_y[i]);
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
        s2_y.push_back(*itr);
    }

   // cout<<s2[0]<<" "<<s2[1]<<endl;

    for (long long int i=0;i<count;i++)
    {
        if(s1_y[i]==s2_y[0])
            binary.push_back(1);


        else
            binary.push_back(0);
    }

    /* for (long long int i=0;i<count;i++)
    {
        cout<<binary[i]<<" ";
    }*/

    fclose(fp_y);


//reading from x_variable
    FILE *fp_x;
    if ((fp_x=fopen("x_variable.txt","r"))==NULL)
    {
        cout<<"Can't open the file";
        cout<<endl;
        exit(1);
    }

    int factor=0,count_x=0;   //counting factors

    char split_x[1000];
    int line=0;

    while(fscanf(fp_x,"%[^\n]\n",split_x)!=EOF)
    {
        line++;
        stringstream data2(split_x);
        string x_var;

        while(data2>>x_var)
            {
                 //cout<<y_var;
                s1_x.push_back(x_var);
                count_x++;
            }
    }

     factor=count_x/line;
   //cout<<count_x/line;

   for(long long int i=0;i<s1_x.size();i++)
    {
        double n;
        n=std:: stof(s1_x[i]);
        x_train.push_back(n);
        //cout<<n<<endl;
    }

     /*for(long long int i=0;i<x_train.size();i++)
    {
        cout<<x_train[i]<<endl;
    }*/


    fclose(fp_x);
    FILE *fp_x_test;

     if ((fp_x_test=fopen("x_for_test.txt","r"))==NULL)
    {
        cout<<"Can't open the file";
        cout<<endl;
        exit(1);
    }



   double weight[factor];


   initialize_weight(weight,factor);

   for(int i=0;i<max_iteration;i++)
   {
      cost=pred();

      if(i%10==0)
      {
          cout<<"Cost and iteration : "<<cost<<" "<<i<<endl;
      }

   }

      Test();

}



