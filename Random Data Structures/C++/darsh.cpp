#include<iostream>
using namespace std;
class students
{
public:
int student[100],count,n,i,e,total,max,min,j,counta,high;
float avg;
void getmarks()
{
total=0;
counta=0;
high=0;
cout<<"Enter the number of students for DATA STRUCTURE test"<<"\n";
cin>>n;
for(i=0;i<n;i++)
{
cout<<"Enter the marks obtained by roll no "<<i<<"\n";
cin>>student[i];
cout<<"the marks obtained by roll no"<<i<<"is:"<<student[i]<<"\n";
if(student[i]>=0)
{
total=total+student[i];
}
else
{
counta=counta+1;
}
}
}
void average()
{
avg=total/n;
cout<<"The average marks obtained by the students in DATA STRUCTURE are:"<<avg<<"\n";

}
void absent()
{
cout<<"the number of absent students are"<<counta<<"\n";
}
void highest()
{
int high;

for(i=0;i<n;i++)
{
if(student[0]>student[i])
{
high=student[0];
}
else
{
student[0]=student[i];
}
high=student[0];

}
cout<<"the highest marks obtained are"<<high<<"\n";
}
void minimum()
{
int min;

for(i=0;i<n;i++)
{
if(student[0]<student[i])
{
min=student[0];
}
else
{
student[0]=student[i];
}
min=student[0];

}
cout<<"the minimum marks obtained are"<<min<<"\n";
}
void more()
{
for(i=0;i<n;i++)
{
for(j=0;j<n;j++)
{
if(student[i]==student[j])
{
count=count+1;
}
}
cout<<"the occurence of "<<student[i]<<" is "<<count<<"\n";
count=0;
}

}

void display()
{
getmarks();
average();
absent();
highest();
minimum();
more();
}
};
int main()
{  
students s1;
s1.display();
}
