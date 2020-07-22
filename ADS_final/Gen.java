import java.io.*;

interface MathCommand<E>
{
abstract E execute(E operand1,E operand2);
}

class DivideCommand implements MathCommand<Integer>
{
public Integer execute(Integer operand1,Integer operand2)
{
try{
return operand1 / operand2;
}
catch(Exception e){
   System.out.println("Divide by zero issue");
}
return 0;
}
}

class D implements MathCommand<Double>
{
public Double execute(Double operand1,Double operand2){
try{
   if(operand2==0)
{
     throw new ArithmeticException("Divide by zero issue");
}
return operand1 / operand2;
}
catch(ArithmeticException e){
    System.out.println("Divide by zero issue");
}
return 0.0;
}
}

public class Gen
{
  public static void main(String[] args)throws IOException
{
       MathCommand<Integer> command;
command=new DivideCommand();
BufferedReader br= new BufferedReader(new InputStreamReader(System.in));
Integer a,b;
System.out.println("Enter first integer number:");
a=Integer.parseInt(br.readLine());
System.out.println("Enter second Integer number:");
b=Integer.parseInt(br.readLine());
Integer result=command.execute(a,b);
System.out.println("result="+result);

MathCommand<Double> command1;
command1=new D();
Double a1,b1;
System.out.println("Enter first Double number:");
a1=Double.parseDouble(br.readLine());
System.out.println("Enter second Double number:");
b1=Double.parseDouble(br.readLine());
Double result1=command1.execute(a1,b1);
System.out.println("result="+result1);
}
}
