#include<iostream>
#include<cstdlib>  
using namespace std;

struct node
  {
    char name[20];
    int time;
    node *next;
  };	

 class list
  {
    public:
    int n,i,x,cnt=0;
    node *head, *tail,*temp;
    list()
    {
      head=NULL;
      tail=NULL;
    }


 void createnode()
   {
   	int slot[n],q;
   	cout<<"enter the number of slots"<<"\n";
   	cin>>q;
   	for(i=1;i<=q;i++)
   		{
   			slot[i]=i;
	    }
label1:
    cout<<"if you want to book an appointment"<<"\n";
    cout<<"1.yes"<<"\n"<<"2.no"<<"\n";
    cin>>n;
    if(n==1)
    {
    	cout<<"available slots are:"<<"\n";
    	for(i=1;i<=q;i++)
		cout<<slot[i];
        node *temp=new node;
        cout<<"enter the name of the patient"<<"\n";
        cin>>temp->name;
        cout<<"enter the slot no"<<"\n";
        cin>>temp->time;
        	for(i=1;i<=q;i++)
        	{
        		while(temp->time!=slot[i])
			}
      temp->next=NULL;
      if(head==NULL)
      {
        head=temp;
        tail=temp;
        temp=NULL;
      }
      else
      {	
        tail->next=temp;
        tail=temp;
      }
      goto label1;
         }
   }

void display()
  {
    node *temp=new node;
    temp=head;
    while(temp!=NULL)
    {
      cout<<"the appointment for "<<temp->name<<" is confirmed for time slot "<<temp->time<<"\n";
      temp=temp->next;    
    }
  } 

void deletelist()
  {
    int pos;
    cout<<"do you want to delete an appointment? \n 1.yes \n 2.no"<<"\n";
    cin>>x;
    if(x==1)
    {
    cout<<"enter the time slot you want to cancel \n";
    cin>>pos;
    node *current=new node;
    node *previous=new node;
    current=head;
    for(int i=1;i<pos;i++)
    {
      previous=current;
      current=current->next;
    }
    previous->next=current->next;
    }
  }

  };	

int main()
{
list  l1;
l1.createnode();
l1.deletelist();
l1.display();
}













