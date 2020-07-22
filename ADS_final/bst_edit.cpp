#include<iostream>
using namespace std;


class bst
{
public:
  struct node
  {
    int data;
    node *left;
    node *right;

  }*temp,*root,*parent;

  void insert();
  void add(node*,node*);
  void disp_inorder();
  void inorder(node*);
  void disp_longest();
  int longest(node*);
  void disp_minimum();
  void minimum(node*);
  void search();
  void init()
  {
  root=NULL;
  }
};

void bst::insert()
{
  int z;
  cout<<"Enter the number of data items you want to insert:"<<endl;
  cin>>z;

  for(int i=0;i<z;i++)
  {
    node *newn;
    newn = new node;
    cout<<"Enter the data:"<<endl;
    cin>>newn->data;
    if(root==NULL)
      root=newn;
    else
      add(root,newn);
  }
}

void bst::add(node*temp, node*new1)
{
  if(new1->data > temp->data)
  {
    if(temp->right == NULL)
      temp->right=new1;
    else
      add(temp->right,new1);
  }

  if(new1->data <temp->data)
  {
    if(temp->left ==NULL)
      temp->left=new1;
    else
      add(temp->left,new1);
  }
}

void bst::disp_inorder()
{
  if(root == NULL)
    cout<<"The tree is empty."<<endl;
  else
    inorder(root);
}

void bst::inorder(node*temp)
{
  if(temp!=NULL)
  {
    inorder(temp->left);
    cout<<temp->data<<"\t";
    inorder(temp->right);
  }
}

void bst::disp_longest()
{
  int n;
  if(root==NULL)
    cout<<"The tree is empty."<<endl;
  else
    {
      n=longest(root);
      cout<<"The number of nodes in the longest path are:"<<n<<endl;
    }
}

int bst::longest(node*temp)
{
  int hl,hr;
  if(temp==NULL || (temp->right==NULL && temp->left==NULL))
    return 0;

  hl=longest(temp->left);
  hr=longest(temp->right);

  if(hl<hr)
    return(hr+1);
  else
    return(hl+1);
}

void bst::disp_minimum()
{
    if(root==NULL)
      cout<<"The tree is empty."<<endl;
    if(root->left==NULL)
      cout<<"The minimun value in the tree is:"<<root->data;
    else
      minimum(root);
}

void bst::minimum(node*temp)
{
  while(temp->left!=NULL)
  {
    temp=temp->left;
  }
  cout<<"The minimum value in the tree is:"<<temp->data;
}

void bst::search()
{
  if(root==NULL)
    cout<<"The tree is empty."<<endl;
  else
  {
    int no,flag;
    cout<<"Enter the data element to be saerched:"<<endl;
    cin>>no;

    if(root->data==no)
      flag=1;
    else
    {
      flag=0;
      temp=root;
      while(temp!=NULL)
      {
        parent=temp;
        if(no<temp->data)
          temp=temp->left;
        if(no>temp->data)
          temp=temp->right;
        if(no==temp->data)
          flag=1;
      }
    }
    if(flag==1)
      cout<<"The search is succesfull"<<endl<<"The element is found"<<endl;
    else
      cout<<"The search is unsucesfull"<<endl<<"The element is not found"<<endl;
  }
}

int main()
{
    bst b;
    b.init();
    int ch;
    char ans;

    cout<<"\n1.Create";
    cout<<"\n2.Display  Inorder";
    cout<<"\n3.Nodes in longest path";
    cout<<"\n4.Search a tree";
    cout<<"\n5.Show minimum element inserted\n";

    do
    {
      cout<<"Enter your choice:"<<endl;
      cin>>ch;
      switch(ch)
      {
        case 1:
        b.insert();
        break;

        case 2:
        b.disp_inorder();
        break;

        case 3:
        b.disp_longest();
        break;

        case 4:
        b.search();
        break;

        case 5:
        b.disp_minimum();
        break;

        default:
        cout<<"Enter valid choice.";
        break;
      }
      cout<<"Do you want to continue?(y/n):";
      cin>>ans;
    }while(ans =='y' || ans == 'Y');

    return 0;
}
