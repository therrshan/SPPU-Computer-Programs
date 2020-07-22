#include<iostream>
using namespace std;
class Heap
{
int marks[20];
int maxheap[20];
int minheap[20];
int num;
public:
Heap()
{
maxheap[0]=0;
minheap[0]=0;
}
void getnum()
{
cout<<"\n Enter how many records? ";
cin>>num;
}
void getmarks()
{
 cout<<"\n Enter Marks: ";
for(int i=0;i<num;i++)
cin>>marks[i];
}




void insertm(int x)
{
 int n;
 n=minheap[0];
 minheap[n+1]=x;
 minheap[0]=n+1;
 downadjust(n+1);
}
void downadjust(int i)
{
int temp;
 while(i>0&&minheap[i]<minheap[i/2])
{
 temp=minheap[i];
minheap[i]=minheap[i/2];
minheap[i/2]=temp;
i=i/2;
}
}
void insert(int x)
{
 int n;
 n=maxheap[0];
 n=n+1;
 maxheap[n]=x;
 maxheap[0]=n;
 upadjust(n);
}
void upadjust(int i)
{
int temp;
 while( i>0 && maxheap[i/2]<maxheap[i]&&i/2!=0)
{
temp=maxheap[i];
maxheap[i]=maxheap[i/2];
maxheap[i/2]=temp;
i=i/2;
}
}
void createmaxheap()
{
for(int i=0;i<num;i++)
{
insert(marks[i]);
}
cout<<"\n Maximum Marks are: "<<maxheap[1];

}
void createminheap()
{

for(int i=0;i<num;i++)
insertm(marks[i]);

cout<<"\n Minimum Marks are: "<<minheap[1];
}
};

int main()
{
int ch;
Heap o;
do
{
cout<<"\n ****MENU****\n 1.Input Marks \n 2.Display Maximum Marks \n 3.Display Minimum Marks \n 4.Exit\n ";
cin>>ch;
switch(ch)
{
case 1:
 o.getnum();
 o.getmarks();
break;
case 2:
 o.createmaxheap();
break;
case 3:
 o.createminheap();
break;
case 4:break;
}}while(ch<4);
return 0;
}
