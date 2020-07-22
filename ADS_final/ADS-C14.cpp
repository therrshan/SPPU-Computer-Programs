#include <iostream>
using namespace std;

struct node
{
	int data;
	node* next;
};

class hashtable
{
	node* ht[10];
	int htarr[10];
	int flag[10];
	int n,x,y;
				
				void create(int x,int y)
				{
					node* q;
					node *p=new(struct node);
					p->data=x;
					p->next=NULL;
					if(ht[y]==NULL)
						ht[y]=p;
					else
						{
							q=ht[y];
							while(q->next!=NULL)
								q=q->next;
							q->next=p;
						}
				}
				
				void display(int x)
				{
					if(ht[x]!=NULL)
					{
						cout<<endl;
						cout<<"ht["<<x<<"]";
					}
					node* p;
					p=ht[x];
					while(p!=NULL)
					{
						cout<<p->data<<"->";
						p=p->next;
					}
				}
				
				int sep_search(int key)
				{
					int j=key%10;
					node* p=ht[j];
					while(p!=NULL)
					{
						if(p->data==key)
							return j;
						p=p->next;
					}
					return -1;
				}
				
				bool lp1create(int x,int y)
				{
					if(htarr[y]==-1)
						htarr[y]=x;
					else
						{
							int t=y;
							y++;
							while(htarr[y]!=-1&&t!=y)
							{
									if(y==9)
										y=0;
									else
										y++;
							}
							if(t==y)
								return 0;
							else
								htarr[y]=x;
						}
					return 1;
				}
				
				bool quadcreate(int x,int y)
				{
					for(int i=0;i<10;i++)
					{
						int j=(y+i*i)%10;
						if(htarr[j]==-1)
						{
							htarr[j]=x;
							return 1;
						}
					}
					return 0;
				}
				
				bool doubcreate(int x,int y,int new_y)
				{
							for(int i=0;i<10;i++)
							{
								int j=(y+i*new_y)%10;
								if(htarr[j]==-1)
								{
									htarr[j]=x;
									return 1;
								}
							}
					return 0;	
				}
				
		/*		bool lp2create(int x,int y)
				{
					if(htarr[y]==-1)
						htarr[y]=x;
					else
						{
							int t=y;
							y++;
							while(htarr[y]!=-1&&t!=y)
							{
									if(y==9)
										y=0;
									else
										y++;
							}
							if(t==y)
								return 0;
							else
								{
									htarr[y]=x;
									flag[t]=y;
								}
						}
					return 1;
				}*/
				
				
				int search(int x)
				{
					for(int i=0;i<10;i++)
					{
						if(htarr[i]==x)
							return i;
					}
					return -1;
				}
				
				void display2(int i)
				{
					if(htarr[i]!=-1)
						cout<<htarr[i]<<"->";		
				}
				
	public:
				hashtable()
				{
					for(int i=0;i<10;i++)
					{
						ht[i]=NULL;
						htarr[i]=-1;
						flag[i]=-1;
					}
				}
				
						
				void pub_seperatecreate()
				{
					cout<<"Enter no. of elements : ";
					cin>>n;
					for(int i=0;i<n;i++)
					{
						cout<<"\nEnter data value : ";
						cin>>x;
						y=x%10;
						create(x,y);
					}
				}
				
				void pub_create()
				{
					cout<<"Enter no. of elements : ";
					cin>>n;
					for(int i=0;i<n;i++)
					{
						cout<<"\nEnter data value : ";
						cin>>x;
						y=x%10;
						lp1create(x,y);
					}
				}
			
				void pub_display()
				{
					for(int i=0;i<10;i++)
					{
						display(i);
					}
				}
			
				void pub_display2()
				{
					for(int i=0;i<10;i++)
					{
						display2(i);
					}
				}
				
				void pub_lpwithoutchain_create()
				{
					bool full;
					cout<<"Enter no. of elements : ";
					cin>>n;
					for(int i=0;i<n;i++)
					{
						cout<<"\nEnter data value : ";
						cin>>x;
						y=x%10;
						full=lp1create(x,y);
						if(full==0)
						{
							cout<<"\nHash table is full,cannot insert more elements.";
							break;
						}
					}
				}
				
				void pub_quadratic_create()
				{
					bool full;
					cout<<"Enter no. of elements : ";
					cin>>n;
					for(int i=0;i<n;i++)
					{
						cout<<"\nEnter data value : ";
						cin>>x;
						y=x%10;
						full=quadcreate(x,y);
						if(full==0)
						{
							cout<<"\nHash table is full,cannot insert more elements.";
							break;
						}
					}
				}
				
				int hash2(int key)
				{
					int k;
					k=7-(key%7);
					return k;
				}
				
				void pub_double_create()
				{
					bool full;
					cout<<"Enter no. of elements : ";
					cin>>n;
					for(int i=0;i<n;i++)
					{
						cout<<"\nEnter data value : ";
						cin>>x;
						y=x%10;
						int new_y=hash2(x);
						full=doubcreate(x,y,new_y);
						if(full==0)
						{
							cout<<"\nHash table is full,cannot insert more elements.";
							break;
						}
					}
				}
				
					
				void pub_sepsearch()
				{
					int c;
					cout<<"\nEnter number to be searched : ";
					cin>>x;
					c=sep_search(x);
					if(c==-1)
						cout<<"\nNumber not found.\n";
					else
						cout<<"\nNumber "<<x<<" found at "<<c<<" position of hashtable.\n";
				}
				
				void pub_search()
				{
					int c;
					cout<<"\nEnter number to be searched : ";
					cin>>x;
					c=search(x);
					if(c==-1)
						cout<<"\nNumber not found.\n";
					else
						cout<<"\nNumber "<<x<<" found at "<<c<<" position of hashtable.\n";
				}
				
		/*		void pub_lpwithoutreplace_create()
				{
					bool full;
					cout<<"Enter no. of elements : ";
					cin>>n;
					for(int i=0;i<n;i++)
					{
						cout<<"\nEnter data value : ";
						cin>>x;
						y=x%10;
						full=lp2create(x,y);
						if(full==0)
						{
							cout<<"\nHash table is full,cannot insert more elements.";
							break;
						}
					}
				}
				
				void pub_lpwithoutreplace_display()
				{
					for(int i=0;i<10;i++)
					{
						lp2display(i);
					}
				}*/
				
				
				
};

int main()
{
	hashtable h;
	int ch,x=1;
	do
	{
		cout<<"********************** Hash Table Implementation Methods **********************\n";
		cout<<"1.Seperate Chaining Method\n2.Linear Probing(without chaining)\n3.Quadratic Probing\n4.Double Hashing\n5.Exit\nEnter your choice :";
		cin>>ch;
		switch(ch)
		{
			case 1: h.pub_seperatecreate();
					h.pub_display();
					h.pub_sepsearch();
					break;
			case 2: h.pub_lpwithoutchain_create();
					h.pub_display2();
					h.pub_search();
					break;
			case 3: h.pub_quadratic_create();
					h.pub_display2();
					h.pub_search();
					break;
			case 4: h.pub_double_create();
					h.pub_display2();
					h.pub_search();
					break;
			case 5: x=0;
					break;	
		}
	}while(x==1);
	

	return 0;
}
