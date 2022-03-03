#include<bits/stdc++.h>
#include<stdlib.h>
#include<vector>
#include<sstream>
#include<string>
#include<math.h>
#include<cstring>
#include"regression.h"
using namespace std;

     double alpha=0.0;
     double beta=0.0;

     double alpha2=0.0;
     double beta2=0.0;

void custom_test(const vector<string>&variable,int button)
{
    if(button==1)
    {
        double custom_variable1,final_pred;
        cout<<"\nEnter any  "<<variable[0]<<" for which you want to predict "<<variable[1]<<" : ";
        cin>>custom_variable1;
        final_pred=alpha+beta*custom_variable1;
        cout<<"\nThe "<<variable[1]<<" for "<<variable[0]<<" is :"<<final_pred;

    }

     if(button==2)
    {
        double custom_variable2,final_pred2;
        cout<<"\n****Enter any  "<<variable[1]<<" for which you want to predict "<<variable[0]<<" : ****";
        cin>>custom_variable2;
        final_pred2=alpha2+beta2*custom_variable2;
        cout<<"\nThe "<<variable[0]<<" for "<<variable[1]<<" is :"<<final_pred2;

    }
}

void correlation_coeeficient_interpretation(double r,const vector<string>&variable)
{
    if(r==0)
        cout<<"There is no linear relationship between "<<variable[0]<<" and "<<variable[1]<<endl;

    else if(r>0)
    {
        cout<<"Trend of the fitted line is upward."<<endl;
        if(r>0.5)
            cout<<"There is a strong positive linear association between "<<variable[0]<<" and "<<variable[1]<<endl;

        else if(r<0.5)
              cout<<"There is a weak positive linear association between "<<variable[0]<<" and "<<variable[1]<<endl;
        else
               cout<<"There is a moderate positive linear association between "<<variable[0]<<" and "<<variable[1]<<endl;
    }

    else if(r<0)
    {
        cout<<"trend of the fitted line is downward ."<<endl;
         if(abs(r)>0.5)
            cout<<"There is a strong positive linear association between "<<variable[0]<<" and "<<variable[1]<<endl;

        else if(abs(r)<0.5)
              cout<<"There is a weak positive linear association between "<<variable[0]<<" and "<<variable[1]<<endl;
        else
               cout<<"There is a moderate positive linear association between "<<variable[0]<<" and "<<variable[1]<<endl;
    }
}

void power_determine_interpretation(double power_determine,const vector<string>&variable, int button)
{
  if(button==1)
    {
        cout<<100*power_determine<<"% of "<<variable[1]<<" can be explained by "<<variable[0]<<endl;
    }

    else if(button==2)
    {
        cout<<100*power_determine<<"% of "<<variable[0]<<" can be explained by "<<variable[1]<<endl;
    }
}

void correlation_coeeficient(double sum_x, double sum_y,double sum_xy,double sum_x_square,double sum_y_square,double n,const vector<string>&variable,int button)
{
    double r;
     double power_determine=0.0;
    r=(sum_xy-((sum_x*sum_y)/n))/sqrt((sum_x_square-(pow(sum_x,2)/n))*(sum_y_square-((pow(sum_y,2))/n)) );

     power_determine=pow(r,2);
    cout<<"\nThe correlation coefficient is: "<<r<<endl;
    cout<<"\nInterpretation by correlation coefficient is :"<<endl;
    correlation_coeeficient_interpretation(r,variable);

    cout<<"\nPower of determination is :" << power_determine<<endl;
    cout<<"\nInterpretation by power of determination is :"<<endl;
    power_determine_interpretation(power_determine,variable,button);

    //giving specific value
    custom_test(variable,button);

}

void regression_line(double alpha,double beta)
{
    cout<<"The best fitted line is :"<<endl;
    cout<<"y = "<<alpha<<" "<<"+"<<" "<<beta<<"x"<<endl;
}

void calculation(const vector<double>&x , const vector<double>&y,const vector<string>&variable,int button)
{
     double sum_x=0.0;
     double sum_y=0.0;
     double sum_x_square=0.0;
     double sum_y_square=0.0;
     double sum_xy=0.00;
     double mean_x=0.0;
     double mean_y=0.0;
    /* double alpha=0.0;
     double beta=0.0;

     double alpha2=0.0;
     double beta2=0.0;*/

     double correlation=0.0;

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

     beta2=(sum_xy-(n*mean_x*mean_y))/(sum_y_square-n*pow(mean_y,2));
     alpha2=mean_x-(beta2*mean_y);

            if(button==1)
             regression_line(alpha,beta);
           else if(button==2)
             regression_line(alpha2,beta2);


     correlation_coeeficient(sum_x,sum_y,sum_xy,sum_x_square,sum_y_square,n,variable,button);

}

void ShowData(FILE *fp)
{
    vector<string>s;
    vector<string>variable;
    vector<double>x;
    vector<double>y;
    char str[1000];
    int line=0;
     while(fscanf(fp,"%[^\n]\n",str)!=EOF)
    {
        //cout<<"____________________________________\n";
        //cout<<"|"<<str<<setw(20)<<"|"<<s<<setw(5)<<endl;
        cout<<str<<endl;
        line++;
        if(line==1)

        {
             stringstream data1(str);

            string var;

            while(data1>>var)
            {
                variable.push_back(var);
            }
        }

         else if(line!=1)
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

    cout<<"The variables are : ";
    for(int i=0;i<variable.size();i++)
    {
        cout<<variable[i]<<endl;
    }
    cout<<endl;

    cout<<"**********Which variable you want to make independent variable : ********"<<endl;
     for(int i=0;i<variable.size();i++)
    {
        cout<<"Press " <<i+1<<" to set variable "<< "'"<<variable[i]<<"'"<<" as independent"<<endl;
    }
    int button;
    cin>>button;


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

    calculation(x,y,variable,button);
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
