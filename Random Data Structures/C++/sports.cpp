#include<iostream>
using namespace std;

class students
{
public:
int a[100],b[100],m[100],i,j,k,l,n;

void getdata()
{
cout<<"enter no. of students"<<"\n";
cin>>n;
cout<<"enter the no of students playing cricket"<<"\n";
cin>>k;
cout<<"enter the no of students playing badminton"<<"\n";
cin>>l;
cout<<"the students playing cricket are"<<"\n"; 

for(i=0;i<k;i++)
{
cin>>a[i];
}
cout<<"the students playing badminton are"<<"\n"; 
for(j=0;j<l;j++)
{
cin>>b[j];
}
}

void common()
{
cout<<"the students playing both sports are";
for(i=0;i<k;i++)
{
for(j=0;j<l;j++)
{
if(a[i]==b[j])
{
cout<<a[i]<<"\n";
}
}
}
}
void only()
{
cout<<"the students playing only cricket are";
for(i=0;i<k;i++)
{
for(j=0;j<l;j++)
{
if(a[i]==b[j])
{
break;
}
else
{
cout<<a[i]<<"\n";
}
}
}
}
};

int main()
{
students s1;
s1.getdata();
s1.common();
s1.only();
}



















