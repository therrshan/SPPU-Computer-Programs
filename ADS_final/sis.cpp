//============================================================================
// Name : ADS10FILE.cpp
// Author :
// Version :
// Copyright : Your copyright notice
// Description : Hello World in C++, Ansi-style
//============================================================================
#include<iostream>
#include<fstream>
#include<string.h>
#include<stdlib.h>
#include<stdio.h>
using namespace std;
class Student
{
char name[10];
int rno;
int div;
char add[30];
friend class fileOperations;
};
class fileOperations{public:
void Create();
void Display();
void Update();
int Delete();
int Search();
};
void fileOperations::Create()
{
Student temp;
char ch='y';
fstream seqfile;
seqfile.open("STU.txt",ios::out|ios::binary|ios::app);
do
{
cout<<"\n Enter Name: ";
cin>>temp.name;
cout<<"\n Enter Roll No: ";
cin>>temp.rno;
cout<<"\n Enter Division: ";
cin>>temp.div;
cout<<"\n Enter Address: ";
cin>>(temp.add);
seqfile.write((char*)&temp,sizeof(temp));cout<<"\nDo you want to add more this?";
cin>>ch;
}while(ch=='y');
seqfile.close();
}
void fileOperations::Display()
{
Student temp;
fstream seqfile;
seqfile.open("STU.txt",ios::in|ios::binary);
cout<<"\n The Contents of file are ..."<<endl;
while(seqfile.read((char*)&temp,sizeof(temp)))
{
cout<<"\nName: "<<temp.name;
cout<<"\nrno: "<<temp.rno;
cout<<"\ndiv: "<<temp.div;
cout<<"\nAdd:"<<temp.add;
cout<<"\n";
}
seqfile.close();
}void fileOperations::Update()
{Student temp;
int temp_roll;
cout<<"\n Enter the Roll Number :";
cin>>temp_roll;
fstream seqfile;
seqfile.open("STU.txt",ios::in|ios::out|ios::binary);
seqfile.seekg(0,ios::beg);
while(seqfile.read((char*)&temp,sizeof(temp)))
{
if(temp.rno==temp_roll){
seqfile.seekp(-sizeof(temp),ios::cur);
cout<<"\n Enter the values for updation...";
cout<<"\n Name: ";cin>>temp.name;
cout<<"\n rno: ";cin>>temp.rno;
cout<<"\n div: ";cin>>temp.div;
cout<<"\n Address: ";cin>>temp.add;
seqfile.write((char*)&temp,sizeof(temp));
break;
}
}seqfile.close();
}
int fileOperations::Delete()
{
Student temp;
int temp_roll,i = 0;
cout<<"\n Enter the Roll Number :";
cin>>temp_roll;
fstream seqfile;
fstream seqfile2;
seqfile.open("STU.txt",ios::in|ios::app|ios::binary);
seqfile2.open("STU1.txt",ios::binary|ios::out);
while(seqfile.read((char*)&temp,sizeof(temp)))
{
if(temp.rno!=temp_roll){
seqfile2.write((char*)&temp,sizeof(temp));
}if (temp.rno == temp_roll)
{
i++;
}
}
seqfile.close();
seqfile2.close();
remove("STU.txt");
rename("STU1.txt","STU.txt");
return i;
}
int fileOperations::Search()
{
Student temp;
fstream seqfile;
int id,pos;
cout<<"\n Enter the rno for searching the record ";
cin>>id;
seqfile.open("STU.txt",ios::app|ios::in|ios::binary);
seqfile.seekg(0,ios::beg);
pos=-1;int i=0;
while(seqfile.read((char *)&temp,sizeof(temp)))
{
if(id==temp.rno)
{
pos=i;
break;
}
i++;
}
return pos;
}
int main()
{
fileOperations List;
char ans='y';
int choice,key,key_del;
do
{
cout<<"\nMain Menu";
cout<<"\n 1.Create";
cout<<"\n 2.Display";
cout<<"\n 3.Update";
cout<<"\n 4.Delete";
cout<<"\n5.Search";
cout<<"\n 6.Exit";
cout<<"\n Enter your choice ";
cin>>choice;
switch(choice)
{
case 1:List.Create();
break;
case 2:List.Display();
break;
case 3:List.Update();
break;
case 4:key_del=List.Delete();
if (key_del==0)
{
cout<<"\nRecord Not Present";
}
break;
case 5:key=List.Search();
if(key<0)
cout<<"\n Record is not present in the file";
else
cout<<"\n Record is present in the file";
break;
}cout<<"\n\t Do you want to go back to Main Menu?";
cin>>ans;
}while(ans=='y'||ans=='Y');
return 0;
}
/*
Main Menu
1.Create
2.Display
3.Update
4.Delete
5.Search
6.Exit
Enter your choice 1
Enter Name: chinmay
Enter Roll No: 202045
Enter Division: 1
Enter Address: puneDo you want to add more this?y
Enter Name: pophale
Enter Roll No: 204012
Enter Division: 2
Enter Address: Pune
Do you want to add more this?n
Do you want to go back to Main Menu?y
Main Menu
1.Create
2.Display
3.Update
4.Delete
5.Search
6.Exit
Enter your choice 2
The Contents of file are ...Name: sunil
rno: 202041
div: 2
Add:mumbai
Name: chinmay
rno: 202045
div: 1
Add:pune
Name: pophale
rno: 204012
div: 2
Add:Pune
Do you want to go back to Main Menu?y
Main Menu
1.Create
2.Display
3.Update
4.Delete
5.Search6.Exit
Enter your choice 3
Enter the Roll Number :202045
Enter the values for updation...
Name: raj
rno: 202010
div: 2
Address: mumbai
Do you want to go back to Main Menu?y
Main Menu
1.Create
2.Display
3.Update
4.Delete
5.Search
6.Exit
Enter your choice 2The Contents of file are ...
Name: sunil
rno: 202041
div: 2
Add:mumbai
Name: raj
rno: 202010
div: 2
Add:mumbai
Name: pophale
rno: 204012
div: 2
Add:Pune
Do you want to go back to Main Menu?4
*/
