#include<iostream>
using namespace std;
#define MAX 10
class airport
{
	string city[10];
	int distance[10][10];

	public :
			int n;
			airport();
			void getdata();
			void showdata();
};

airport :: airport()
{
	n = 0;
	for(int i=0 ; i<MAX ; i++)
	{
		for(int j=0 ; j<MAX ; j++)
			distance[i][j] = 0;
	}
}

void airport :: getdata()
{
	int k;

	cout << "\nEnter the no. of cities: " ;
	cin >> n;
	cout<<"Enter city name:";
	for(int k=0;k<n;k++)
		cin>>city[k];

	for(int i=0 ; i<n ; i++)
	{
		for(int j=i+1 ; j<n ; j++)
		{

			cout << "\nEnter Distance between "
			<<city[i]<< "to" <<city[j]<<":\n";
			cin >> distance[i][j];

			distance[j][i] = distance[i][j];

		}

	}

}

void airport :: showdata()
{
	cout<<"\t";
		for(int k=0;k<n;k++)
		{
		cout<<city[k]<<"\t";

		}
			cout << "\n";
		for(int i=0 ; i<n ; i++)
		{		cout <<city[i] <<"\t";
				for(int j=0 ; j<n ; j++)
				{
					cout << distance[i][j] << "\t";
				}
				cout << "\t";

				cout << "\n";
		}

}

int main()
{
	airport a;
	a.getdata();
	a.showdata();
}
