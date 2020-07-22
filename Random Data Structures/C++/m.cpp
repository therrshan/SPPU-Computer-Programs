#include<iostream>
using namespace std;
int main()
{
int x[3][3],y[3][3],z[3][3],i,j;
cout<<"ENTER ELEMENTS OF 1st MATRIX\n";
for(i=0;i<3;i++)
{
for(j=0;j<3;j++)
cin>>x[i][j];
}
cout<<"ENTER ELEMENTS OF 2nd MATRIX\n";
for(i=0;i<3;i++)
{
for(j=0;j<3;j++)
cin>>y[i][j];
}
cout<<"MATRIX [X]";
for(i=0;i<3;i++)
{
cout<<"\n\n";
for(j=0;j<3;j++)
cout<<"\t"<<x[i][j];
}
cout<<"\nMATRIX [Y]";
for(i=0;i<3;i++)
{
cout<<"\n\n";
for(j=0;j<3;j++)
cout<<"\t"<<y[i][j];
}
for(i=0;i<3;i++)
{
for(j=0;j<3;j++)
z[i][j]=x[i][j]+y[i][j];
}
cout<<"\nMATRIX [Z]";
for(i=0;i<3;i++)
{
cout<<"\n\n";
for(j=0;j<3;j++)
cout<<"\t"<<z[i][j];
}
}
