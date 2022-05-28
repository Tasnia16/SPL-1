#include<bits/stdc++.h>
#include"regression.h"
using namespace std;

vector<string>v;
void k_means(FILE *fp)
{
    int i,j,n,k,l,x,count,flag,size=0;
	double Centx[100][100],Centy[100][100],Graph[100][100],dist,min,Group[100][100],totalx,totaly;
	double *Ax,*Ay;

    char str[1000];
	while(fscanf(fp,"%[^\n]\n",str)!=EOF)
    {

        stringstream DATA(str);
        cout<<str<<endl;

            string VAR;

            while(DATA>>VAR)
            {
                size++;
                v.push_back(VAR);
            }
    }

    int index=0;
    n=size/2;
    Ax = new double[n];
	Ay = new double[n];

	for(i=0;i<v.size();i=i+2)
    {
        double num1;
        num1=std:: stof(v[i]);
        Ax[index]=num1;
        index++;
    }
     int index2=0;
     for(int j=1;j<v.size();j=j+2)
    {
        double num2;
        num2=std:: stof(v[j]);
        Ay[index2]=num2;
        index2++;
    }


    cout<<endl<<"Select the number of clusters to be formed :";
	cin>>k;

	cout<<endl<<"Select the index of objects which are to be selected as \ninitial centroids of clusters :"<<endl<<endl;
	for(i=0;i<n;i++)
	{
		cout<<i<<") ("<<Ax[i]<<" , "<<Ay[i]<<" )"<<endl;
	}
	cout<<endl;
	for(i=0;i<k;i++)
	{
		cin>>x;
		Centx[0][i] = Ax[x];
		Centy[0][i] = Ay[x];
	}
	cout<<endl;
	l=0;
	while(1)
	{
		for(i=0;i<k;i++)
		{
			for(j=0;j<n;j++)
			{
				dist = sqrt(((Ax[j]-Centx[l][i])*(Ax[j]-Centx[l][i]))+((Ay[j]-Centy[l][i])*(Ay[j]-Centy[l][i])));
				Graph[i][j]= dist;
			}
		}

		for(i=0;i<n;i++)
		{
			min=Graph[0][i];
			Group[l][i]=0;
			for(j=0;j<k;j++)
			{
				if(Graph[j][i]<min)
				{
					min = Graph[j][i];
					Group[l][i] = j;
				}
			}
		}
		l+=1;

		for(i=0;i<k;i++)
		{
			totalx=0;
			totaly=0;
			count=0;
			for(j=0;j<n;j++)
			{
				if(Group[l-1][j]==i)
				{
					totalx+=Ax[j];
					totaly+=Ay[j];
					count++;
				}
			}
			Centx[l][i]=totalx/count;
			Centy[l][i]=totaly/count;
		}
		flag=1;
		if(l>1)
		{
			for(i=0;i<n;i++)
			{
				if(Group[l-1][i] == Group[l-2][i])
				{
					flag=0;
				}
				else
				{
					flag=1;
					break;
				}
			}
		}
		if(flag==0)
		{
			break;
		}
	}

	cout<<endl;
	for(i=0;i<k;i++)
	{
		cout<<"The objects in Cluster under the centroid (" <<Centx[l-1][i]<<" , "<<Centy[l-1][i]<<" ) are:"<<endl;
		for(j=0;j<n;j++)
		{
			if(Group[l-1][j]==i)
			{
				cout<<"( "<<Ax[j]<<" , "<<Ay[j]<<" )"<<endl;
			}
		}
	}
}



