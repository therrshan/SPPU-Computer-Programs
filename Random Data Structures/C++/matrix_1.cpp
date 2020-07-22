#include<iostream>
using namespace std;
int main()
{
int n,i,j;
int a[n][n];
cout<<"enter order of an matrix\n";
cin>>n;
for(i=0;i<n;i++)
{
for(j=0;j<n;j++)
{
cin>>a[i][j];
}
}
for(i=0;i<n;i++)
{
cout<<"\n\n";
for(j=0;j<n;j++)
{
cout<<"\t"<<a[i][j];
}
}
}

