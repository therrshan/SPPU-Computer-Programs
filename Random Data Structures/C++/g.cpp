#include<iostream>
using namespace std;
struct node
{
 int info;
 node *next;
}*start, *newptr, *save, *ptr;
node*create_new_node(int);
void insert_beg(node*);
void display(node*);
 int main()
{start=NULL;
 int inf; 
char ch='y'; 
{
while(ch=='y'|| ch=='Y')
cout<<"enter info for new node";
cin>>inf; 
newptr=create_new_node(inf);
if (newptr!=NULL)
{ cout<<"new node created successfully";
}
if (newptr=NULL)
{
cout<<"cannot create new node";

}
cout<<"now entering info for president";
insert_beg(newptr);
cout<<"now the list is";
display(start);
cout<<"enter y to continue ";
cin>>ch;
}
return 0;
}
node*create_new_node(int n)
{ ptr=new node;
ptr->info=n;
ptr->next=NULL;
return ptr;
}
void insert_beg(node*np)
{
if(start==NULL)
start=np;
else
{save=start;
start=np;
np->next=save;
}
}
void display(node*np)
{
while(np!=NULL)
{
cout<<np->info<<"->";
np=np->next;
}
}
