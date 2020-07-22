#include<iostream>
using namespace std;

class node
{
public:
string key;
string mean;
int height;
node *left;
node *right; 
};

class tree
{
node *root;
public:
tree()
{
root=NULL;
}

node* rleft(node *t)
{
node *p;
p=t->right;
t->right=p->left;
p->left=t;
t->height=height(t);
p->height=height(p);
return p;
}

node* rright(node *t)
{
node *p;
p=t->left;
t->left=p->right;
p->right=t;
t->height=height(t);
p->height=height(p);
return p;
}

node* rl(node *t)
{
t->right=rright(t->right);
t=rleft(t);


return t;
}

node* lr(node *t)
{
t->left=rleft(t->left);
t=rright(t);

return t;
}

node* ll(node *t)
{
t=rleft(t);

return t;
}

node* rr(node *t)
{
t=rright(t);

return t;
}

int height(node *t)
{
int hl,hr;
if(t->left==NULL)
hl=0;
else
hl=1+t->left->height;

if(t->right==NULL)
hr=0;
else
hr=1+t->right->height;

if(hl>hr)
return hl;
else return hr;
}

int bh(node *t)
{
int bl,br;
if(t->left==NULL)
bl=0;
else
bl=1+t->left->height;

if(t->right==NULL)
br=0;
else
br=1+t->right->height;

return bl-br;
}


node* create(string k,string m)
{
node *p=new node;
p->left=NULL;
p->right=NULL;
p->key=k;
p->mean=m;
p->height=height(p);
return p;
}

node* insert(node *t,string k,string m)
{
if(t==NULL)
t=create(k,m);
else if(k>t->key)
{
t->right=insert(t->right,k,m);
if(bh(t)==-2)
{
if(k>t->right->key)
t=rr(t);
else 
t=rl(t);

}

}
else
{
t->left=insert(t->left,k,m);
if(bh(t)==2)
{
if(k<t->left->key)
t=ll(t);
else 
t=lr(t);
}
}
t->height=height(t);
return t;
}

node* ndelete(node *t,string k)
{
node *p=NULL;
if(t==NULL)
return NULL;
else if(k>t->key)
{
t->right=ndelete(t->right,k);
if(bh(t)==2)
{
if(bh(t->left)>=0)
t=ll(t);
else
t=lr(t);
}
}
else
if(k<t->key)
{
t->left=ndelete(t->left,k);
if(bh(t)==-2)
{
if(bh(t->right)<=0)
t=rr(t);
else
t=rl(t);
}
}
else
{if(t->right!=NULL)
{
p=t->right;
while(p->left!=NULL)
{
p=p->left;
}
t->key=p->key;
t->mean=p->mean;
t->right=ndelete(t->right,p->key);
if(bh(t)==2)
if(bh(t->left)>=0)
t=ll(t);
else
t= lr(t);
}
else
return(t->left);
}
t->height=height(t);
return t;
}

void dnode()
{
cout<<"\nEnter the key you want to delete";
string k;
cin>>k;
root=ndelete(root,k);

}

void croot()
{
string k,m;
cout<<"Enter the keyword and its meaning";
cin>>k>>m;
root=create(k,m);
}

void cnode()
{
string k,m;
cout<<"Enter the keyword and its meaning";
cin>>k>>m;
root=insert(root,k,m);
}

void inorder(node *t)
{
if(t!=NULL)
{
inorder(t->left);
cout<<(t->key)<<" "<<t->mean<<"\n";
inorder(t->right);
}
}

void pubinorder()
{
cout<<"\nInorder traversal: ";
inorder(root);
cout<<"\n";
}

};

int main()
{
tree t;
int x=0;
while(x!=5)
{cout<<"\nenter the choice\n1.create a tree\n2.insert a node in the tree\n3.display\n4.delete\n5.exit";
int x;
cin>>x;
switch(x)
{
case 1:
t.croot();
break;
case 2:
t.cnode();
break;
case 3:
t.pubinorder();
break;
case 4:
t.dnode();
break;
default:
return 0;
}

}
return 0;
}
