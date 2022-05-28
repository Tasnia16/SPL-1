#include<bits/stdc++.h>
#include<stdlib.h>
#include<vector>
#include<string>
#include<math.h>
#include<cstring>
#include "polynomial_reg.h"
using namespace std;

void calculate_poly_reg(const vector<double>&x1 , const vector<double>&y1)
{
  int degree;
  cout << "Enter the degree of Polynomial to fit : \n";
 cin >> degree;
 int i,j,k;

  if (x1.size() <= degree)
  return ;

  double x[x1.size()][2 * degree+ 1], y[x1.size()][degree + 1], a[2*degree+ 1], b[degree+ 1], c[degree + 1][degree + 2], d[degree + 1], matrix;

   for ( i = 0; i < x1.size(); i++)
  {
     x[i][1]=x1[i];
  }


  for (i = 0; i < y1.size(); i++)
 {
   y[i][0]=y1[i];
 }

 for ( i = 0; i <x1.size(); i++)
 {
  x[i][0] = 1;
 }

 for (j = 2; j <= 2 * degree; j++)
 {
  for (i = 0; i <x1.size(); i++)
  {
   x[i][j] = x[i][1] * x[i][j - 1];
  }
 }

 for (j = 1; j <= degree; j++)
 {
  for (i = 0; i < x1.size(); i++)
  {
   y[i][j] = x[i][1] * y[i][j - 1];
  }
 }

 //Printing the Table for x
 /*for (i = 1; i <= 2 * degree; i++)
 {
  cout << "--------";
 }
 cout << endl;
 for (i = 1; i <= 2 * degree; i++)
 {
  cout << "x^(" << i << ")\t";
 }
 cout << endl;
 for (i = 1; i <= 2 * degree; i++)
 {
  cout << "__________";
 }
 for (i = 0; i <x1.size(); i++)
 {
  cout << "\n";
  for (j = 1; j < 2 * degree+ 1; j++)
  {
   cout << x[i][j] << "\t";
  }
 }
 cout << endl;
 for (i = 1; i <= 2 * degree; i++)
 {
  cout << "_________";
 }

 cout << endl;
 //Printing the Table for y
 for (i = 0; i <= degree; i++)
 {
  cout << "_________";
 }
 cout << endl;

 for (i = 0; i <= degree; i++)
 {
  cout << "y*x^(" << i << ")\t\t";
 }
 cout << endl;

 for (i = 0; i <= degree; i++)
 {
  cout << "_________";
 }

 for (i = 0; i < x1.size(); i++)
 {
  cout << "\n";
  for (j = 0; j < degree + 1; j++)
  {
   cout << y[i][j] << "\t\t";
  }
 }
 cout << endl;
 for (i = 0; i <= degree; i++)
 {
  cout << "_________";
 }
*/
 for (j = 0; j <= 2 * degree; j++)
 {
  a[j] = 0;
  for (i = 0;i<x1.size(); i++)
  {
   a[j] += x[i][j];
  }
 }

 for (j = 0; j <= degree; j++)
 {
  b[j] = 0;
  for (i = 0; i < x1.size(); i++)
  {
   b[j] += y[i][j];
  }
 }

 for (i = 0; i <= degree; i++)
 {
  k = 0;
  for (j = i; j <= degree + i; j++)
  {
   c[i][k] = a[j];
   k++;
  }
 }

 for (i = 0; i <= degree; i++)
 {
  c[i][degree + 1] = b[i];
 }

 //Printing the equations in Matrix form
 /*cout << "\n\nThe Equations in Matrix form are :\n";
 for (i = 0; i < degree+ 1; i++)
 {
  //cout <<endl;

  for (j = 0; j < degree+ 2; j++)
  {
   cout << setw(10)<<c[i][j] << "\t"<<setw(10);
  }
  cout<<endl;
 }*/

 //Gauss Elimination methods
 for (k = 0; k < degree; k++)
 {
  for (i = degree; i > k; i--)
  {
   for (j = degree + 1; j >= 0; j--)
   {
    c[i][j] = c[i][j] - (c[k][j] * c[i][k]) / (c[k][k]);
   }
  }
 }


 cout<<endl;
/* cout << "\n\nNew matrix is :";
 for (i = 0; i < degree+ 1; i++)
 {
  cout << endl;

  for (j = 0; j < degree+ 2; j++)
  {
   cout << c[i][j] << "\t\t";
  }
 }*/

 //Steps of Back Substitution
 for (k = degree; k >= 0; k--)
 {
  matrix=0;
  for (j = degree; j > k; j--)
  {
     matrix+= c[k][j] * d[j];
  }
  d[k] = (c[k][degree + 1] - matrix) / c[k][k];
 }

 //Printing the final equation
cout<<endl;
 cout << "\nThe Equation Polynomial is : \n y = ";
 for (i = degree; i > 0; i--)
 {
  cout << "(" << d[i] << ") x^[" << i << "] + ";
 }
 cout << "(" << d[0] << ")" << endl;
}

void poly_reg()
{
    FILE *fp2;
    if ((fp2=fopen("regression.txt","r"))==NULL)
    {
        cout<<"Can't open the file";
        cout<<endl;
        exit(1);
    }

    vector<string>s;
    vector<string>variable;
    vector<double>x;
    vector<double>y;
    char str[1000];

      int line=0;

      while(fscanf(fp2,"%[^\n]\n",str)!=EOF)
    {
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
                s.push_back(reg);
            }
        }
    }

    for(int i=0;i<s.size();i=i+2)
    {
        double n;
        n=std:: stof(s[i]);
        x.push_back(n);
    }

     for(int j=1;j<s.size();j=j+2)
    {
        double m;
        m=std:: stof(s[j]);
        y.push_back(m);
    }


    calculate_poly_reg(x,y);

}
