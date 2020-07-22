#include<iostream>
#include<cmath>
using namespace std;
class polynomial
{
public:
int a[10],b[10],mul[10],add[10],i,m,n,j,k,z,y,x;

void getdata()
{
cout<<"ENTER THE NUMBER OF TERMS IN POLYNOMIAL 1";
cin>>m;
cout<<"ENTER THE NUMBER OF TERMS IN POLYNOMIAL 2";
cin>>n;
a[0]=m;
b[0]=n;
cout<<"ENTER THE POLYNOMIAL 1"<<"\n";
for(i=1;i<(2*m+1);i++)
{
cin>>a[i];
}
cout<<"ENTER THE POLYNOMIAL 2"<<"\n";
for(i=1;i<(2*n+1);i++)
{
cin>>b[i];
}
}

void evaluate()
{
cout<<"ENTER THE VALUE OF X"<<"\n";
cin>>x;
z=0;
for(i=1;i<(2*m+1);i++)
{
if(i%2!=0)
{
z=z+a[i+1]*pow(x,a[i]);
}
}
cout<<"THE VALUE OF POLYNOMIAL 1 FOR GIVEN VALUE OF X IS "<<z;
y=0;
for(i=1;i<(2*n+1);i++)
{
if(i%2!=0)
{
y=y+b[i+1]*pow(x,b[i]);
}
}
cout<<"THE VALUE OF POLYNOMIAL 2 FOR GIVEN VALUE OF X IS "<<y;
}

void addition()
{
k=1;
j=1;
for(i=1;i<(2*m+1);i+2)
{
if(a[i]==b[j])
{
add[k]=a[i];
add[k+1]=a[i+1]+b[i+1];
k+2;
}
else if(a[i]>b[j])
{
add[k]=a[i];
add[k+1]=a[i+1];
k+2;
j+2;
}
else if(a[i]<b[j])
{
add[k]=b[j];
add[k+1]=b[j+1];
k+2;
}
}
for(i=1;i<(2*(m+n)+2);i++)
{
if(i%2!=0)
{
cout<<add[i+1]<<"X^"<<add[i]<<"+";
}
}
}

};
int main()
{
polynomial p1;
p1.getdata();
p1.evaluate();
p1.addition();
}
