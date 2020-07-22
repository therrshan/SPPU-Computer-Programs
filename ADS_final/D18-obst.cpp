#include<iostream>

using namespace std;
#define MAX 10
int find(int i,int j);
void print(int,int);
int p[MAX],q[MAX],w[10][10],c[10][10],r[10][10],i,j,k,n,m;
char idnt[7][10];
 class obst
{
public:
 void form()
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
       cout <<"\n";
       print(0,n);
}


int find(int i,int j)
 {
        int min=2000,m,l;
	for(m=i+1;m<=j;m++)
	if(c[i][m-1]+c[m][j]<min)
		{
			min=c[i][m-1]+c[m][j];
			l=m;
		}
return l;
}


void print(int i,int j)
{
	if(i<j)
		cout<<"\n"<<idnt[r[i][j]];
	else
		return;
	print(i,r[i][j]-1);
	print(r[i][j],j);
}

};

int main()
{

obst a;
int i,j;
	cout << "enter the no, of identifiers";
	cin >>n;
	cout <<"enter identifiers";
	for(i=1;i<=n;i++)
        cin>>idnt[i];
	cout <<"enter success propability for identifiers";
	for(i=1;i<=n;i++)
		cin >>p[i];
	cout << "enter failure propability for identifiers";
	for(i=0;i<=n;i++)
		cin >> q[i];
	a.form();
	a.print( i,j);
return 0;
	}
