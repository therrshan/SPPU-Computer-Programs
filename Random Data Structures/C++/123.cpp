#include<iostream>
using namespace std;
class Example
{
int a,b;
public:
Example(int a1,int b1)
{a=a1;
b=b1;}
Example(const Example &e)
{
a=e.a;

b=e.b;
}
void display()
{
cout<<"Value of a&b";
cout<<a;
}
};






int main()
{
Example e1(100,200);
e1.display();

}
