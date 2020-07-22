#include<iostream>
using namespace std;
class calculator
{
public:

int a,b;
int add,sub,mul,div;


void addition();
void subtraction();
void multiplication();
void division();
void getdata()

{
cout<< "ENter a,b";
cin>>a>>b;
}
};
void calculator::addition()
{add=a+b;
cout<<a<<b<<add;}
 void calculator::subtraction()
{sub=a-b;
cout<<a<<b<<sub;}
void calculator::multiplication()
{mul=a*b;
cout<<a<<b<<mul;}
void calculator::division()
{ div=a/b;
cout<<a<<b<<div; }

int main()
{
char ch,op;

calculator z;
do{
z.getdata();

cout<<"adddittion subtraction multiplication division"<<"select an option";
switch(op)
{
case '+' :
z.addition();
break;
case'-' :
z.subtraction();
break;
case'*' :
z.multiplication();
break;
case'/' :
z.division();
break;
}




cout<<"DO YOU WANT TO PRINT ATHER OPERATIPON";

}
while(ch=='y'||ch=='Y');
 
}


























