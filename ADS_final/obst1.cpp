#include<iostream>
using namespace std;
class obst
{
public:
int w[10][10],c[10][10],r[10][10];
int i,j,k,n,m;
float p[10],q[10];
string id[10];

void getdata()
{
cout<<"\nEnter no of identifiers";
cin>>n;
cout<<"\nEnter the identifiers";
for(i=1;i<=n;i++)
{
cin>>id[i];
}

cout<<"\nEnter success probabilities for identifiers";
for(i=1;i<=n;i++)
{
cin>>p[i];
}


cout<<"\nEnter failure probabilities for identifiers";
for(i=0;i<=n;i++)
{
cin>>q[i];
}
create();
}

void create()
{
for(i=0;i<=n;i++)
{
w[i][i]=q[i];
c[i][i]=r[i][i]=0;
w[i][i+1]=q[i]+q[i+1]+p[i+1];
r[i][i+1]=i+1;
c[i][i+1]=q[i]+q[i+1]+p[i+1];
}
w[n][n]=q[n];
r[n][n]=c[n][n]=0;
for(m=2;m<=n;m++)
{
for(i=0;i<=n-m;i++)
{
j=i+m;
w[i][j]=w[i][j-1]+p[j]+q[j];
k=find(i,j);
r[i][j]=k;
c[i][j]=w[i][j]+c[i][k-1]+c[k][j];
}
}
}

int find(int i,int j)
{
int min=2000,m,l;
for(m=i+1;m<=j;m++)
{
if(c[i][m-1]+c[m][j]<min)
{
min=c[i][m-1]+c[m][j];
l=m;
}
}
return l;
}

void print(int i,int j)
{
if(i<j)
cout<<"\n"<<id[r[i][j]];
else
return;
print(i,r[i][j]-1);
print(r[i][j],j);
}

void display()
{
cout<<"\nRoot of the OBST: "<<id[n];
cout<<"\nCost of OBST: "<<c[0][n];
cout<<"\nIN preorder:\n";
print(0,n);
}


};

int main()
{
obst o;
o.getdata();
o.display();
return 0;
}

