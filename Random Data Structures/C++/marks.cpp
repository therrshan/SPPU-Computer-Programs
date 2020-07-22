#include<iostream>
using namespace std;

class marks
{
	public:
		char name[10];
		int marks,i,j;
		
	void getdata()
	    {
	    	cout<<"Enter the name of the student:\n";
	    	cin>>name;
	    	cout<<"Enter the marks of "<<name;
	    	cin>>marks;
		}
		
	void result()
	    {
	    	if(marks<8)
	    	{
	    		cout<<name<<" is fail."<<"\n";
			}
			else if(marks>=8 && marks<10)
			{
				cout<<name<<" has passed.\n";
			}
			else if(marks>=10 && marks<15)
			{
				cout<<name<<" has passed with first class.\n";
			}
			else if(marks>=15)
			{
				cout<<name<<" has passed with distimction.\n";
			}
		}	
};

int main()
{
	int i,n;
	marks m[i];
	cout<<"Enter the number of students:"<<"\n";
	cin>>n;
	for(i=0;i<n;i++)
	{
		m[i].getdata();
	}
	for(i=0;i<n;i++)
	{
		m[i].result();
	}
}
