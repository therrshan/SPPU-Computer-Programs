//Problem Definition: Write a program to implement subnetting and find the subnet masks.

import java.util.Scanner;

class Subnet
{
	public static void main(String args[])
	{
		Scanner sc = new Scanner(System.in);

		//Accept ip address
		System.out.print("Enter the ip address: ");
		String ip = sc.nextLine();
		
		//**************************************************************************
		
		//Split the string after every .
		/*eg. 192.168.5.71 =>
		 * split_ip[0]=192
		 * split_ip[1]=168
		 * split_ip[2]=5
		 * split_ip[3]=71 
		*/
		String split_ip[] = ip.split("\\.");
		
		//Convert into binary ip
		String split_bip[] = new String[4]; 
		
		String bip = "";
		for(int i=0;i<4;i++)
		{
			 // 18" => 18 => 10010 => 00010010
			split_bip[i] = appendZeros(Integer.toBinaryString(Integer.parseInt(split_ip[i])));
			bip += split_bip[i];
		}
		System.out.println("IP in binary is "+bip);

		//**************************************************************************
		
		System.out.print("Enter the number of addresses: " );
		int n = sc.nextInt();

		//Calculation of mask
		 /*eg if address = 120,
		  *  log 120/log 2 gives log to the base 2 => 6.9068,
		  *   ceil gives us upper integer */
		int bits = (int)Math.ceil(Math.log(n)/Math.log(2));
		System.out.println("Number of bits required for address = "+bits);

		int mask = 32-bits;
		System.out.println("The subnet mask is = "+mask);

		//**************************************************************************
		
		//Calculation of first address and last address
		int fbip[] = new int[32];
		for(int i=0; i<32;i++) 
		{	
			 //convert character 0,1 to integer 0,1
			fbip[i] = (int)bip.charAt(i)-48; 
		}
		
		for(int i=31;i>31-bits;i--)
		{
			//Get first address by ANDing last n bits with 0
			fbip[i] &= 0;
		}
			
		String fip[] = {"","","",""};
		for(int i=0;i<32;i++)
		{
			fip[i/8] = new String(fip[i/8]+fbip[i]);
		}
		System.out.print("First address is = ");
		
		for(int i=0;i<4;i++)
		{
			System.out.print(Integer.parseInt(fip[i],2));
			if(i!=3) System.out.print(".");
		}
		System.out.println();

		//--------------------------------------------
		
		int lbip[] = new int[32];
		for(int i=0; i<32;i++)
		{
			 //convert character 0,1 to integer 0,1
			lbip[i] = (int)bip.charAt(i)-48;
		}
		
		for(int i=31;i>31-bits;i--)
		{
			//Get last address by ORing last n bits with 1
			lbip[i] |= 1;
		}	
		
		String lip[] = {"","","",""};
		for(int i=0;i<32;i++)
				lip[i/8] = new String(lip[i/8]+lbip[i]);
		System.out.print("Last address is = ");

		for(int i=0;i<4;i++)
		{
			System.out.print(Integer.parseInt(lip[i],2));
			if(i!=3) System.out.print(".");
		}
		System.out.println();
	}

	static String appendZeros(String s)
	{
		String temp = new String("00000000");
		return temp.substring(s.length())+ s;
	}
}

/*Output
Enter the ip address: 100.110.150.10
IP in binary is 01100100011011101001011000001010
Enter the number of addresses: 7
Number of bits required for address = 3
The subnet mask is = 29
First address is = 100.110.150.8
Last address is = 100.110.150.15
*/
