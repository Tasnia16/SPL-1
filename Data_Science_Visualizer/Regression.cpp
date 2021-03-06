#include<bits/stdc++.h>
#include<stdlib.h>
#include<vector>
#include<string>
#include<math.h>
#include<cstring>
#include<windows.h>
#include"regression.h"
#include"polynomial_reg.h"
using namespace std;
int sample_size;
const int ALPHABET = 26;
struct TrieNode
{
    struct TrieNode *children[ALPHABET];
    bool end_flow;
};

struct TrieNode *getNode(void)
{
    struct TrieNode *pNode =  new TrieNode;

    pNode->end_flow = false;

      for(int i=0;i<ALPHABET; i++)
        {
           pNode->children[i] = NULL;
        }
    return pNode;
}

void insert(struct TrieNode *root, string key)
{
    struct TrieNode *pCrawl = root;

    for (int i = 0; i < key.length(); i++)
    {
        int index = key[i] - 'a';
        if (!pCrawl->children[index])
            pCrawl->children[index] = getNode();

        pCrawl = pCrawl->children[index];
    }
    pCrawl->end_flow = true;
}

bool search(struct TrieNode *root, string key)
{
    struct TrieNode *pCrawl = root;

    for (int i = 0; i < key.length(); i++)
    {
        int index = key[i] - 'a';

        if (!pCrawl->children[index])
        {
            return false;

        }

        pCrawl = pCrawl->children[index];
    }

    return (pCrawl->end_flow);
}

COORD coord= {0,0}; // this is global variable
COORD co={0};

void gotox(int x)
{
    coord.X=x;
    SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE),co);
}

void gotoxy(int x,int y)
{
    coord.X=x;
    coord.Y=y;
    SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE),coord);
}

     double alpha=0.0;
     double beta=0.0;
     //for 2nd
     double alpha2=0.0;
     double beta2=0.0;

void custom_test(const vector<string>&variable,int button)
{
    if(button==1)
    {
        double custom_variable1,final_pred;
        cout<<endl;
        cout<<"Enter any  "<<variable[0]<<" for which you want to predict "<<variable[1]<<" : ";
        cin>>custom_variable1;
        final_pred=alpha+beta*custom_variable1;
        cout<<"\nThe "<<variable[1]<<" for "<<variable[0]<<" is :"<<final_pred;
        cout<<endl;
        int round_final_pred;
        round_final_pred=final_pred;
        double fp=round_final_pred;

        if(fp==final_pred)
        {
            cout<<"The approx : "<<round_final_pred;
            cout<<endl;
        }
        else
        {
            cout<<"The approx : "<<round_final_pred+1;
            cout<<endl;
        }
    }

     if(button==2)
    {
        double custom_variable2,final_pred2;
        cout<<endl;
        cout<<"\n****Enter any  "<<variable[1]<<" for which you want to predict "<<variable[0]<<" : ****";
        cin>>custom_variable2;
        final_pred2=alpha2+beta2*custom_variable2;
        cout<<endl;
        cout<<"The "<<variable[0]<<" for "<<variable[1]<<" is :"<<final_pred2<<endl;
        int round_final_pred2;
        round_final_pred2=final_pred2;
        double fp2=round_final_pred2;
        if(fp2==final_pred2)
        {
            cout<<"The approx : "<<round_final_pred2;
            cout<<endl;
        }
        else
        {
            cout<<"The approx : "<<round_final_pred2+1;
            cout<<endl;
        }
      // rounding

    }

    poly_reg(button);
}

void correlation_coeeficient_interpretation(double r,const vector<string>&variable)
{
    if(r==0)
    {
        cout<<"There is no linear relationship between "<<variable[0]<<" and "<<variable[1];
        cout<<endl;
    }

    else if(r>0)
    {
        cout<<"Trend of the fitted line is upward."<<endl;
        cout<<variable[1]<<" will be increasing with the increment of " <<variable[0]<<endl;
        if(r>0.5)
            {
            cout<<"There is a strong positive linear association between "<<variable[0]<<" and "<<variable[1]<<endl;
            }

        else if(r<0.5)
             {
                 cout<<"There is a weak positive linear association between "<<variable[0]<<" and "<<variable[1]<<endl;
             }
        else
        {
               cout<<"There is a moderate positive linear association between "<<variable[0]<<" and "<<variable[1]<<endl;
        }
    }

    else if(r<0)
    {
        cout<<"trend of the fitted line is downward ."<<endl;
        cout<<variable[1]<<" will be decreasing with the decrement of " <<variable[0]<<endl;

         if(abs(r)>0.5)
            {
                cout<<"There is a strong positive linear association between "<<variable[0]<<" and "<<variable[1]<<endl;
            }

        else if(abs(r)<0.5)
             {
                 cout<<"There is a weak positive linear association between "<<variable[0]<<" and "<<variable[1]<<endl;
             }
        else
        {
               cout<<"There is a moderate positive linear association between "<<variable[0]<<" and "<<variable[1]<<endl;
        }
    }
}

void power_determine_interpretation(double power_determine,const vector<string>&variable, int button)
{
    double round=100*power_determine;
    int extract_int=round;
    double extract_float;
    int approax;
    extract_float=round-extract_int;
    if(extract_float<0.5)
    {
        approax=extract_int;
    }
    else
    {
        approax=extract_int+1;
    }

  if(button==1)
    {
        cout<<"  "<< 100*power_determine<<"% of "<<variable[1]<<" can be explained by "<<variable[0]<<endl;
        cout<<"  Approx : "<<approax<<"%"<<endl;
    }

    else if(button==2)
    {
        cout<<"  "<<100*power_determine<<"% of "<<variable[0]<<" can be explained by "<<variable[1]<<endl;
        cout<<"   Approx : "<<approax<<"%"<<endl;
    }
}

void correlation_coeeficient(double sum_x, double sum_y,double sum_xy,double sum_x_square,double sum_y_square,double n,const vector<string>&variable,int button)
{
    double r;
     double power_determine=0.0;
    r=(sum_xy-((sum_x*sum_y)/n))/sqrt((sum_x_square-(pow(sum_x,2)/n))*(sum_y_square-((pow(sum_y,2))/n)) );

     power_determine=pow(r,2);
   //  gotox(20);
    cout<<"\n      The correlation coefficient is: "<<r<<endl;
    cout<<"      ---------------------------------\n";
    cout<<endl;
    cout<<"\n********Interpretation by correlation coefficient is :********"<<endl;

    correlation_coeeficient_interpretation(r,variable);

    cout<<"\nPower of determination is :" << power_determine<<endl;
    cout<<"\n  Interpretation by power of determination is :"<<endl;
    cout<<"  ---------------------------------------------"<<endl;
    power_determine_interpretation(power_determine,variable,button);

    //giving specific value
    custom_test(variable,button);

}

void regression_line(double alpha,double beta)
{
    cout<<endl;
    //gotoxy(20,1000);
    cout<<"                 -----------------------------------------"<<endl;
    cout<<"                 | The best fitted line is :             |"<<endl;
    //gotoxy(20,1002);
    cout<<"                 |                                       |"<<endl;
    cout<<"                 | y = "<<alpha<<" "<<"+"<<" "<<beta<<"x"<<"               |"<<endl;
    cout<<"                 -----------------------------------------"<<endl;

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
     beta=(sum_xy-(n*mean_x*mean_y))/(sum_x_square-n*pow(mean_x,2));
     alpha=mean_y-(beta*mean_x);

     beta2=(sum_xy-(n*mean_x*mean_y))/(sum_y_square-n*pow(mean_y,2));
     alpha2=mean_x-(beta2*mean_y);

            if(button==1)
             regression_line(alpha,beta);
           else if(button==2)
             regression_line(alpha2,beta2);


     correlation_coeeficient(sum_x,sum_y,sum_xy,sum_x_square,sum_y_square,n,variable,button);

}

bool IS_NUM(const string& str)
{
    for (char const &c : str)
        {
          if (std::isdigit(c) == 0)
           return false;
        }
    return true;
}

void ShowData(FILE *fp)
{
    vector<string>s;
    vector<string>variable;
    vector<double>x;
    vector<double>y;
    char str[1000];
    int line=0;
    long long int k=21;
     while(fscanf(fp,"%[^\n]\n",str)!=EOF)
    {

        stringstream DATA(str);

            string VAR;

        //cout<<"____________________________________\n";
        //cout<<"|"<<str<<setw(20)<<"|"<<s<<setw(5)<<endl;

        /*gotoxy(20,k);
        cout<<"|"<<endl;
        gotoxy(30,k);*/
        cout<<str<<endl;
        line++;

       /* gotoxy(60,k);
        cout<<"|"<<endl;*/

         k=k+1;

        if(line==1)

        {
             stringstream data1(str);

            string var;

            while(data1>>var)
            {
                variable.push_back(var);

                int BOOL;
                      BOOL=IS_NUM(var);
                      cout<<BOOL;
                      if(BOOL==1)
                      {
                          k_means(fp);
                          fclose(fp);
                          return;
                      }
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

  //  gotoxy(20,k);
   // cout<<"|";


   /* for(long long int t=20;t<=60;t++)
    {
        gotoxy(t,k);
        cout<<"-";
    }
    cout<<endl;
    k=k+2;
    gotoxy(20,k);
*/
    cout<<"The variables are : "<<endl;
    // gotoxy(20,k+1);
    cout<<"--------------------"<<endl;;
    for(long long int i=0;i<variable.size();i++)
    {
      //  gotoxy(20,k+2);
        cout<<i+1<<".";
        k=k+2;
        cout<<variable[i]<<endl;
    }
    cout<<endl;



    for(long long int i=0;i<s.size();i=i+2)
    {
        double n;
        n=std:: stof(s[i]);
        x.push_back(n);
        //cout<<n<<endl;
    }

     for(long long int j=1;j<s.size();j=j+2)
    {
        double m;
        m=std:: stof(s[j]);
        y.push_back(m);
        //cout<<n<<endl;
    }

    sample_size=x.size();
    cout<<endl;
    cout<<"        The sample size is : "<< sample_size <<endl;
    cout<<endl;

    if(sample_size>25000)
    {
        system("Color 7C");
         cout<<"Warning !! Too large data "<<endl;
         cout<<"Choose 1st 5000 data as a sample "<<endl;
    }
    /*cout<<"\n**********Which variable you want to make independent variable : ********"<<endl;
    cout<<"___________________________________________________________________________"<<endl;
     for(long long int i=0;i<variable.size();i++)
    {
        cout<<"Press " <<i+1<<" to set variable "<< "'"<<variable[i]<<"'"<<" as independent"<<endl;
    }*/


    int button;

    string keys[]={"age", "gender", "experience","country", "height", "study","temperature", "drug","medicine","x" };

    vector<string>vs;
    vs.push_back(variable[0]);
    vs.push_back(variable[1]);

    transform(vs[0].begin(),vs[0].end(),vs[0].begin(),::tolower);
    transform(vs[1].begin(),vs[1].end(),vs[1].begin(),::tolower);

    int n = sizeof(keys)/sizeof(keys[0]);

    struct TrieNode *root = getNode();

    // Construct trie
    for (int i = 0; i < n; i++)
        {
             insert(root, keys[i]);
        }

    int p,q;

    search(root, vs[0])? p=1 :p=0;
    search(root, vs[1])? q=1 :q=0;

     if(p==0 && q==0)
     {
         button=1;
     }

     else
        {

        if(p==1 && q==0)
        button=1;

         else
         button=2;

     }

    fclose(fp);

    calculation(x,y,variable,button);

}

void reg_input()
{
    FILE *fp;

    if ((fp=fopen("regression.txt","r"))==NULL)
    {
        cout<<"Can't open the file";
        cout<<endl;
        exit(1);
    }
    int c=0;
    cout<<endl;
   // gotoxy(20,18);
    cout<<"The dataset of the provided file is  : " <<endl ;
   // gotoxy(20,19);
    cout<<"__________________________________________";
    cout<<endl;
   // gotoxy(20,20);
    cout<<"------------------------------------------";
    cout<<endl;
    // function for showing text file
    ShowData(fp);

}
