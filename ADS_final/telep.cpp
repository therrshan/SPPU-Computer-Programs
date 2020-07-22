
#include <iostream>
#include<iomanip>
using namespace std;
const int MAX=10;
class EdgeList;
class Edge
{
int u,v,w;
public:
Edge()
{}
Edge(int a,int b,int weight)
{
u=a;  v=b;  w=weight;
}
friend class EdgeList;
friend class PhoneGraph;};
class EdgeList
{
Edge data[MAX];
int n;
public:
friend class PhoneGraph;
EdgeList()
{
n=0;
}
void sort();
void print();
};

void EdgeList::sort()
{
Edge temp;
for(int i=1;i<n;i++)
for(int j=0;j<n-1;j++)
if(data[j].w>data[j+1].w)
{
temp=data[j];
data[j]=data[j+1];
data[j+1]=temp;
}
}
void EdgeList::print()
{
int cost=0;
for(int i=0;i<n;i++)
{
cout<<"\n"<<i+1<<" "<<data[i].u<<"--"<<data[i].v<<" = "<<data[i].w;
cost=cost+data[i].w;
}
cout<<"\nMinimum cost of Telephone Graph = "<<cost;
}
class PhoneGraph
{
int data[MAX][MAX];
int n;
public:
PhoneGraph(int num)
{
n=num;
}
void readgraph();
void printGraph();
int mincost(int cost[],bool visited[]);
int prim();
void kruskal(EdgeList &spanlist);
int find(int belongs[], int vertexno);
void unionComp(int belongs[], int c1,int c2);
};
void PhoneGraph::readgraph()
{
cout<<"Enter Adjacency(Cost) Matrix: \n";
for(int i=0;i<n;i++)
{
for(int j=0;j<n; j++)
cin>>data[i][j];
}
}
void PhoneGraph::printGraph()
{
cout<<"\nAdjacency (COST) Matrix: \n";
for(int i=0;i<n;i++)
{
for(int j=0;j<n;j++)
{
cout<<setw(3)<<data[i][j];
}
cout<<endl;
}
}

int PhoneGraph::mincost(int cost[],bool visited[])
{
int min=9999,min_index; //initialize min to MAX value(ANY) as temporary
for(int i=0;i<n;i++)
{
if(visited[i]==0 && cost[i]<min)
{   min=cost[i];
min_index=i;
}
}
return min_index;
}

int PhoneGraph::prim()
{
bool visited[MAX];
int parents[MAX];
int cost[MAX];
for(int i=0;i<n;i++)
{
cost[i]=9999;
visited[i]=0;
}
cost[0]=0;
parents[0]=-1;
for(int i=0;i<n-1;i++)
{
int k=mincost(cost,visited);
visited[k]=1;
for(int j=0;j<n;j++)
{
if(data[k][j] && visited[j]==0 && data[k][j] < cost[j])
{
parents[j]=k;
cost[j]=data[k][j];
}
}
}
cout<<"Minimum Cost Telephone Map:\n";
for(int i=1;i<n;i++)
{
cout<<i<<" -- "<<parents[i]<<" = "<<cost[i]<<endl;
}
int mincost=0;
for (int i = 1; i < n; i++)
mincost+=cost[i];
return mincost;
}

int PhoneGraph::find(int belongs[],int vertexno)
{
return belongs[vertexno];
}

int main()
{
int vertices,choice;
EdgeList spantree;
cout<<"Enter Number of cities: ";
cin>>vertices;
PhoneGraph p1(vertices);
p1.readgraph();
do
{
cout<<"\n1.Find Minimum Total Cost(By Prim's Algorithm)"
<<"\n3.Re-Read Graph(INPUT)"
<<"\n4.Print Graph"
<<"\n0. Exit"
<<"\nEnter your choice: ";
cin>>choice;
switch(choice)
{
case 1:
cout<<" Minimum cost of Phone Line to cities is: "<<p1.prim();
break;

case 3:
p1.readgraph();
break;
case 4:
p1.printGraph();
break;
default:
cout<<"\nWrong Choice!!!";
}
}
while(choice!=0);
return 0;
}
