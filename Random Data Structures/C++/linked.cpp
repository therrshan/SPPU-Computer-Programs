#include<iostream>
using namespace std;

struct node
{
char name[100];
int prn;
struct node *next;
}*node;

class linkedlist
{
public:
int n,i;

void insert()
{
struct node *head,*p;
head=(node)malloc(sizeof(struct node));
head->next=NULL;
p=head;
}

void create()
{
struct node *p;
cout<<"enter the number of the students registered "<<"\n";
cin>>n;

for(i=1;i<=n;i++)
{
p->next=(node)malloc(sizeof(struct node));
p=p->next;
cout<<"enter name of student"<<"\n";
cin>>p->name;
cout<<"enter prn of student"<<"\n";
cin>>p->prn;
p->next=NULL;
}
}
};
int main()
{
linkedlist l1;
l1.create();
l1.insert();
}





























