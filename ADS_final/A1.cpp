#include<iostream>
using namespace std;

class node
{
public:
string data;
node *right;
node *left;
};

class stack1
{
public:
int flag;
node *a;

};

class stack
{
int top;
int top1;
stack1 st[10];
node *a[20];
public:
stack()
{
top=-1;
top1=-1;
}

int empty()
{
if(top==-1)
{
return 0;
}
else 
{
return 1;
}
}

int empty1()
{
if(top1==-1)
{
return 0;
}
else 
{
return 1;
}
}


void push(node *t)
{
top++;
a[top]=t;
}

void push1(stack1 s1)
{
top1++;
st[top1]=s1;
}


node* pop()
{
node *p;
p=a[top];
top--;
return p;
}

stack1 pop1()
{
stack1 q;
q=st[top1];
top1--;
return q;
}

};

class queue
{
node *a[10];
int f;
int r;
public:
queue()
{
f=-1;
r=-1;
}

int empty()
{
if(f==-1&&r==-1)
{
return 0;
}
else 
{
return 1;
}
}
void enq(node *t)
{
if(f==-1&&r==-1)
f=r=0;
else
r++;
a[r]=t;
}

node* deq()
{
node *t;
t=a[f];
if(r==f)
r=f=-1;
else
f++;
return t;
}

};




class tree
{
stack s;
queue q;
node *root;
public:
node* create()
{
node *p;
string x;
p=new node;
cout<<"\nEnter data or enter -1 for NULL";
cin>>x;
if(x=="-1")
return NULL;
p->data=x;
cout<<"\nEnter left node of "<<x;
p->left=create();
cout<<"\nEnter right node of "<<x;
p->right=create();
return p;
}
void pubcreate()
{
root=create();
}

void nonrecpreorder(node *t)
{
while(t!=NULL)
{
cout<<t->data<<" ";
s.push(t);
t=t->left;
}
while(s.empty()!=0)
{
t=s.pop();
t=t->right;
while(t!=NULL)
{
cout<<t->data<<" ";
s.push(t);
t=t->left;
}
}
}

void nonrecinorder(node *t)
{
while(t!=NULL)
{
s.push(t);
t=t->left;
}
while(s.empty()!=0)
{
t=s.pop();
cout<<t->data<<" ";
t=t->right;
while(t!=NULL)
{
s.push(t);
t=t->left;
}
}
}

void nonrecpostorder(node *t)
{stack1 s2;
while(t!=NULL)
{
s2.a=t;
s2.flag=0;
s.push1(s2);
t=t->left;
}
while(s.empty1()!=0)
{
s2=s.pop1();
if(s2.flag==0)
{
t=s2.a;
s2.flag=1;
s.push1(s2);
t=t->right;
while(t!=NULL)
{
s2.a=t;
s2.flag=0;
s.push1(s2);
t=t->left;
}
}
else
{
cout<<s2.a->data<<" ";
}
}
}

void npubpre()
{
cout<<"\nNonrecurssive preorder : ";
nonrecpreorder(root);
}

void npubin()
{cout<<"\nNonrecurssive inorder : ";
nonrecinorder(root);
}

void npubpost()
{

cout<<"\nNonrecurssive postorder : ";
nonrecpostorder(root);
}


void inorder(node *t)
{
if(t!=NULL)
{
inorder(t->left);
cout<<(t->data)<<" ";
inorder(t->right);
}
}

void postorder(node *t)
{
if(t!=NULL)
{
postorder(t->left);
postorder(t->right);
cout<<(t->data)<<" ";
}
}


void preorder(node *t)
{
if(t!=NULL)
{
cout<<(t->data)<<" ";
preorder(t->left);
preorder(t->right);
}
}

void pubinorder()
{
cout<<"\nInorder traversal: ";
inorder(root);
cout<<"\n";
}

void pubpreorder()
{
cout<<"\nPreorder traversal: ";
preorder(root);
cout<<"\n";
}

void pubpostorder()
{
cout<<"\nPostorder traversal: ";
postorder(root);
cout<<"\n";
}

void bfs(node *t)
{int c;
queue q1;
node *p;
cout<<t->data<<endl;
q1.enq(t);
while(q1.empty()!=0)
{
queue q2;
while(q1.empty()!=0)
{
p=q1.deq();
if(p->left!=NULL)
{
q2.enq(p->left);
cout<<p->left->data<<" ";
}
if(p->right!=NULL)
{
q2.enq(p->right);
cout<<p->right->data<<" ";
}
}
cout<<"\n";
q1=q2;
c=c+1;
}
cout<<"\nHeight of the tree is : "<<c;
}

void pubbfs()
{
cout<<"\nBFS : ";
bfs(root);
}
};

int main()
{
tree t;
t.pubcreate();
t.pubinorder();
t.pubpostorder();
t.pubpreorder();
t.npubpre();
t.npubin();
t.npubpost();
t.pubbfs();
}
