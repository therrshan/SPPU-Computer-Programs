import java.lang.*;
import java.util.Scanner;

class A
{
float p,c,m;
protected float count;
private float e,h;

public void getdata()
{
System.out.println("In class A");
System.out.println("Enter marks in physics,math,chem,eng,hindi");
Scanner sc=new Scanner(System.in);
p=sc.nextInt();
m=sc.nextInt();
c=sc.nextInt();
e=sc.nextInt();
h=sc.nextInt();
sc.close();
count=5;
float avg;
avg=(p+c+m+e+h)/count;
System.out.println("Marks in physics: "+p);
System.out.println("Marks in maths: "+m);
System.out.println("Marks in chemistry: "+c);
System.out.println("Marks in english: "+e);
System.out.println("Marks in hindi: "+h);
System.out.println("Avg marks: "+avg);
}

};

class B extends A
{
void display()
{
float avg;
avg=(p+c+m)/(count-2);
System.out.println("In class B ");
System.out.println("Avg Marks in physics,maths,chem: "+avg);
}
};


public class C
{
public static void main(String args[])
{
System.out.println("In class C calling functions");
A as=new A();
B bs=new B();
bs.getdata();
bs.display();
}
};
