#include<iostream>
using namespace std;
int main()
{
int a[10][10],b[10][10],mul[10][10],m,n,i,j,k;

cout<<"ENTER THE NUMBER OF ROWS AND COLOUMNS OF MATRIX "<<"\n";
cin>>m>>n;

cout<<"ENTER THE ELEMENTS OF MATRIX A"<<"\n";
for(i=0;i<m;i++)
{
for (j=0;j<n;j++)
{
cin>>a[i][j];

}
}
cout<<"ENTER THE ELEMENTS OF MATRIX B"<<"\n";
for(i=0;i<m;i++)
{
for (j=0;j<n;j++)
{
cin>>b[k][l];

}
}

for(i=0;i<m;i++)
{
for (j=0;j<n;j++)
{
mul[i][j]=0;
for(k=0;k<n;k++)
{
mul[i][j+=a[i][k]*b[k][j];
}
}
}
for(i=0;i<m;i++)
{
cout<<endl;
for (k=0;k<n;k++)
{
cout<<mul[i][j]<<"/n";
}
}
}


