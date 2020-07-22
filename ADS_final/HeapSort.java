import java.io.*;
import java.util.*;
class heap
{
void upadjust(int heap[],int i)
{
while(i>1&&heap[i]>heap[i/2])
{
int temp;
temp=heap[i/2];
heap[i/2]=heap[i];
heap[i]=temp;
i=i/2;
}
}
void insert(int heap[],int x)
{
int n;
n=heap[0];
heap[n+1]=x;
heap[0]=n+1;
upadjust(heap,n+1);
}
void downadjust(int heap[],int i)
{
int j,n,flag=1;
n=heap[0];
while(2*i<=n&&flag==1)
{
j=2*i;
if(j+1<=n&&heap[j]<heap[j+1])
{
j=j+1;
}
if(heap[i]>heap[j])
{
flag=0;
}
else
{
int temp;
temp=heap[i];
heap[i]=heap[j];
heap[j]=temp;
i=j;
}
}
}
int delmax(int heap[])
{
int x,n,i;
x=heap[1];
n=heap[0];
heap[1]=heap[n];
heap[0]=n-1;
downadjust(heap,1);
return x;
}
}
public class HeapSort
{
public static void main(String args[])
{
heap h=new heap();
int heap[];
int x,n,i;
heap=new int[50];
Scanner s=new Scanner(System.in);
System.out.println("enter no of data you want");
n=s.nextInt();
heap[0]=0;
for(i=0;i<n;i++)
{
System.out.println("enter the data");
x=s.nextInt();
h.insert(heap,x);
}
System.out.println("max heap:"+"");
for(i=0;i<n+1;i++)
{
System.out.println(heap[i]+"\t");
}
System.out.println("after sorting data is:");
heap[0]=n;
while(heap[0]>=1)
{
x=h.delmax(heap);
heap[n+1]=x;
System.out.println(heap[n+1]+" ");
n--;
}
}
}
