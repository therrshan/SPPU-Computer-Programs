#include<iostream>
using namespace std;
int main()
{
int i,j;
char op,ch,Y,y;
int add,sub,multi,divide;
do
{
cout<<"Enter value for i,j";
cin>>i>>j;
cout<<"+ Addition;- subtarction;* Multiplication;/ Division";
cout<<"Select an option";
cin>>op;
  switch(op)
{
case '+' :
add=i+j;       
cout<<i<<"+"<<j<<"="<<add;break;


case '-' :
sub=i-j;
cout<<i<<"-"<<j<<"="<<sub;break;

case '*' :
multi=i*j;
cout<<i<<"*"<<j<<"="<<multi;break;

case '/' :


divide=i/j;
cout<<i<<"/"<<j<<"="<<divide;
break;
}
cout<<"Do u want any other operation(Y/N)";
cin>>ch;
}while(ch=='Y'||ch=='y');
return(0);
}
