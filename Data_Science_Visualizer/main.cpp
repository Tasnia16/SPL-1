#include <bits/stdc++.h>
#include"regression.h"
#include"polynomial_reg.h"
#include"logictic_reg.h"
#include "GroupData_Classification.h"
using namespace std;
int main()
{
 string name1="               DATA  TYPE                     ";
 string name2="  Dataset with dependent independent variable ";
 string press="Press";
 string name3="Dataset without dependent independent variable";

 int pre1=1;
 int pre2=2;

 int button;
 cout<<"Which type of dataset you want to take ?\n\n";
 cout<<"                     ***********COMMAND TABLE**********\n";
 cout<<"_____________________________________________________________________________\n";
 cout << "|" << name1 << setw(20)<<"   |   " <<setw(5)<<press << setw(5)<<"   |"<<endl;
 cout<<"_____________________________________________________________________________\n";
 cout << "|" << name2 << setw(20)<<"   |   " <<setw(5)<<pre1 << setw(5)<<"   |"<<endl;
 cout<<"_____________________________________________________________________________\n";
 cout << "|" << name3 << setw(20)<<"   |   " <<setw(5)<<pre2 << setw(5)<<"   |"<<endl;
 cout<<"_____________________________________________________________________________\n";
 cin>>button;
    if(button ==1)
    {
        reg_input();
        poly_reg();
        cout<<"Do you want to test any dataset containing binary output?"<<endl;
        cout<<"Press 1 to continue :"<<endl;
        cout<<"Press 0 to exit program:"<<endl;
        int press2;
        cin>>press2;
        if (press2==1)
        {
          logistic_regression();
        }

        else if(press2==0)
            exit(0);
    }

    if(button==2)
    {
        classification();
    }

}
