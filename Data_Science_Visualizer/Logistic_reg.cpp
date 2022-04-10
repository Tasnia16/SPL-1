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
vector<string>y_test_s3;
vector<string>y_test_s4;
vector<double>x_train;
vector<double>binary;
set<string>set1;
set<string>set2;

const double Threshold = 0.001;
const int max_iteration=500;
double cost=0;
double bias;

double pred()
{
  double z;
}

double sigmoid(double z)
 {
     double y;
     y=1/(1+exp(-z));

     return y;
 }

 void matrix_multiplication(int test_count, int factor,const vector<double>&x,double *weight, double bias)
{
    for(int i=0;i<test_count;i++)
    {
        weight[i]=0.0;


    }
}
void Test(const vector<double>&x,const vector<double>&y,double *weight, double bias,int test_count,int factor)
{
   double a[test_count];
   double result_y[test_count];
   double accuracy=0;

   matrix_multiplication(test_count,factor,x,weight,bias);

   for(int i=0;i<test_count;i++)
   {
       result_y[i]=sigmoid(a[i]);

       if(result_y[i]<0.5)
       {
           result_y[i]=0;
       }

       else
       {
           result_y[i]=1;
       }
       accuracy=accuracy+fabs(result_y[i]-y[i]);
   }

   accuracy=100-(accuracy/test_count);
   cout<<"Test accuracy is : "<<accuracy*100<<"%"<<endl;
}

double loss(double expected_result, double actual_result)
{
   double main_result=0;

   if(expected_result==0)
   {
       main_result=-log(1-actual_result);
   }

   else if(expected_result==1)
   {
       main_result=-log(actual_result);
   }

   return main_result;
}


 void initialize_weight(double *weight,int factor)
 {

     for(int i=0;i<factor;i++)
     {
         weight[i]=0.01;
     }
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

    for ( int i=0;i<count;i++)
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

    for (int i=0;i<count;i++)
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

    char split_x_test[1000];
    int count_x_test=0;
    int line2=0;

    while(fscanf(fp_x_test,"%[^\n]\n",split_x_test)!=EOF)
    {
        line2++;
        stringstream data2(split_x_test);
        string x_var_test;

        while(data2>>x_var_test)
            {
                double n;
                 n=std:: stof(x_var_test);
                 x_test.push_back(n);
                 count_x_test++;

            }
    }

    int row_count_x=count_x_test/factor;
    //cout<<"tttttttttttt"<<row_count_x<<endl;

    fclose(fp_x_test);


    FILE *fp_y_test;
    if ((fp_y_test=fopen("y_for_test.txt","r"))==NULL)
    {
        cout<<"Can't open the file";
        cout<<endl;
        exit(1);
    }


    char split_y_test[1000];
    int count_y_test=0;
    while(fscanf(fp_y_test,"%[^\n]\n",split_y_test)!=EOF)
    {
        stringstream data(split_y_test);
        string y_var;

        while(data>>y_var)
            {
                 //cout<<y_var;
                y_test_s3.push_back(y_var);
                count_y_test++;
            }
    }

     for ( int i=0;i<count_y_test;i++)
    {
        set2.insert(y_test_s3[i]);
    }

    set<string>:: iterator itr2;

    for(itr2=set2.begin();itr2!=set2.end();itr2++)
    {
        y_test_s4.push_back(*itr2);
    }



    for (int i=0;i<count_y_test;i++)
    {
        if(y_test_s3[i]==y_test_s4[0])
            y_test.push_back(1);


        else
            y_test.push_back(0);
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

      //Test(x_test,y_test,weight,bias,row_count_x, factor);

}



