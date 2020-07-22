#include<iostream>
#include<graphics.h>
#include<cmath>
using namespace std;
class transformation
{
public:

float a[4][3];
float t[3][3];
int i,j,k,l,m,n;

void getdata()
{
//a[4][3]={100,100,1,100,200,1,150,200,1,50,200,1};
//t[3][3]={100,100,1,150,186.6,1,50,186.6,1};
a[0][0]=100;
a[0][1]=100;
a[0][2]=1;
a[1][0]=200;
a[1][1]=100;
a[1][2]=1;
a[2][0]=150;
a[2][1]=200;
a[2][2]=1;
a[3][0]=50;
a[3][1]=200;
a[3][2]=1;

t[0][0]=100;
t[0][1]=100;
t[0][2]=1;
t[1][0]=150;
t[1][1]=186.6;
t[1][2]=1;
t[2][0]=50;
t[2][1]=186.6;
t[2][2]=1;

}

void display()
{
cout<<"\ndisplay";
for(i=0;i<4;i++)
{
if(n==4)
cout<<"\n"<<a[i][0]<<" "<<a[i][1]<<" "<<a[i][2];
else
cout<<"\n"<<t[i][0]<<" "<<t[i][1]<<" "<<t[i][2];
}
}


void dda(float x1,float y1,float x2,float y2)
{
float dx,dy,m,xinc,yinc;
int steps;
dx=x2-x1;
dy=y2-y1;
m=dy/dx;
if(abs(dx)>abs(dy))
{steps=abs(dx);
}else
steps=abs(dy);
xinc=dx/steps;
yinc=dy/steps;
int x;
for(int i=1;i<=steps;i++)
{
putpixel(x1,y1,5);
x1=x1+xinc;
y1=y1+yinc;
}

}

void rdraw()
{
dda(a[0][0],a[0][1],a[1][0],a[1][1]);
dda(a[1][0],a[1][1],a[2][0],a[2][1]);
dda(a[2][0],a[2][1],a[3][0],a[3][1]);
dda(a[3][0],a[3][1],a[0][0],a[0][1]);
}

void tdraw()
{
dda(t[0][0],t[0][1],t[1][0],t[1][1]);
dda(t[1][0],t[1][1],t[2][0],t[2][1]);
dda(t[0][0],t[0][1],t[2][0],t[2][1]);
}


void tscale()
{
float s[4][3];
float sx,sy;
cout<<"\nEnter the scalimg factors sx and sy";
cin>>sx>>sy;
float b[3][3]={sx,0,0,0,sy,0,0,0,1};

for(i=0;i<3;i++)
{
for(j=0;j<3;j++)
{s[i][j]=0;
for(k=0;k<3;k++)
{
s[i][j]=s[i][j]+(t[i][k]*b[k][j]);

}
}
}

for(i=0;i<3;i++)
{
cout<<"\n"<<s[i][0]<<" "<<s[i][1]<<" "<<s[i][2];
}

for(i=0;i<3;i++)
{
t[i][0]=s[i][0];
t[i][1]=s[i][1];
}
tdraw();
}

void rscale()
{
float s[4][3];
float sx,sy;
cout<<"\nEnter the scalimg factors sx and sy";
cin>>sx>>sy;
float b[3][3]={sx,0,0,0,sy,0,0,0,1};

for(i=0;i<4;i++)
{
for(j=0;j<3;j++)
{s[i][j]=0;
for(k=0;k<3;k++)
{
s[i][j]=s[i][j]+(a[i][k]*b[k][j]);
}
}
}

for(i=0;i<4;i++)
{
cout<<"\n"<<s[i][0]<<" "<<s[i][1]<<" "<<s[i][2];
}

for(i=0;i<4;i++)
{
a[i][0]=s[i][0];
a[i][1]=s[i][1];
}
rdraw();
}

void ttranslation()
{
float tr[4][3];
float tx,ty;
cout<<"\nEnter the translation factors tx and ty";
cin>>tx>>ty;
float b[3][3]={1,0,0,0,1,0,tx,ty,1};

for(i=0;i<3;i++)
{
for(j=0;j<3;j++)
{tr[i][j]=0;
for(k=0;k<3;k++)
{
tr[i][j]=tr[i][j]+(t[i][k]*b[k][j]);
}
}
}

for(i=0;i<3;i++)
{
cout<<"\n"<<tr[i][0]<<" "<<tr[i][1]<<" "<<tr[i][2];
}

for(i=0;i<3;i++)
{

t[i][0]=tr[i][0];
t[i][1]=tr[i][1];
}

tdraw();

}

void rtranslation()
{
float tr[4][3];
float tx,ty;
cout<<"\nEnter the translation factors tx and ty";
cin>>tx>>ty;
float b[3][3]={1,0,0,0,1,0,tx,ty,1};

for(i=0;i<4;i++)
{
for(j=0;j<3;j++)
{tr[i][j]=0;
for(k=0;k<3;k++)
{
tr[i][j]=tr[i][j]+(a[i][k]*b[k][j]);
}
}
}

for(i=0;i<4;i++)
{
cout<<"\n"<<tr[i][0]<<" "<<tr[i][1]<<" "<<tr[i][2];
}

for(i=0;i<4;i++)
{
a[i][0]=tr[i][0];
a[i][1]=tr[i][1];

}

rdraw();
}

void trotation()
{
/*
float tx,ty;
tx=t[0][0];
ty=t[0][1];
float tr[3][3];
float e[3][3]={1,0,0,0,1,0,-tx,-ty,1};

for(i=0;i<3;i++)
{
for(j=0;j<3;j++)
{tr[i][j]=0;
for(k=0;k<3;k++)
{
tr[i][j]=tr[i][j]+(t[i][k]*e[k][j]);
}
}
}


for(i=0;i<3;i++)
{
t[i][0]=tr[i][0];
t[i][1]=tr[i][1];
}
*/
float ro[3][3];
float r;
cout<<"\nEnter the angle of rotation";
cin>>r;
r=(r*3.14)/180;
float c[3][3]={cos(r),sin(r),0,-sin(r),cos(r),0,0,0,1};

for(i=0;i<3;i++)
{
for(j=0;j<3;j++)
{ro[i][j]=0;
for(k=0;k<3;k++)
{
ro[i][j]=ro[i][j]+(t[i][k]*c[k][j]);
}
}
}

for(i=0;i<3;i++)
{
cout<<"\n"<<ro[i][0]<<" "<<ro[i][1]<<" "<<ro[i][2];
}

for(i=0;i<3;i++)
{
t[i][0]=ro[i][0];
t[i][1]=ro[i][1];
}
/*
float d[3][3]={1,0,0,0,1,0,tx,ty,1};

for(i=0;i<3;i++)
{
for(j=0;j<3;j++)
{tr[i][j]=0;
for(k=0;k<3;k++)
{
tr[i][j]=tr[i][j]+(t[i][k]*d[k][j]);
}
}
}


for(i=0;i<3;i++)
{
t[i][0]=t[i][0];
t[i][1]=t[i][1];
}
*/
tdraw();
}


void rrotation()
{

/*float tx,ty;
tx=a[0][1];
ty=a[0][2];

float tr[4][3];
float e[3][3]={1,0,0,0,1,0,-tx,-ty,1};

for(i=0;i<4;i++)
{
for(j=0;j<3;j++)
{tr[i][j]=0;
for(k=0;k<3;k++)
{
tr[i][j]=tr[i][j]+(a[i][k]*e[k][j]);
}
}
}


for(i=0;i<4;i++)
{
a[i][0]=tr[i][0];
a[i][1]=tr[i][1];
}
*/
float ro[4][3];
float r;
cout<<"\nEnter the angle of rotation";
cin>>r;
r=(r*3.14)/180;
float c[3][3]={cos(r),sin(r),0,-sin(r),cos(r),0,0,0,1};

for(i=0;i<4;i++)
{
for(j=0;j<3;j++)
{ro[i][j]=0;
for(k=0;k<3;k++)
{
ro[i][j]=ro[i][j]+(a[i][k]*c[k][j]);
}
}
}

for(i=0;i<4;i++)
{
cout<<"\n"<<ro[i][0]<<" "<<ro[i][1]<<" "<<ro[i][2];
}

for(i=0;i<4;i++)
{
a[i][0]=ro[i][0];
a[i][1]=ro[i][1];

}
/*
float d[3][3]={1,0,0,0,1,0,tx,ty,1};

for(i=0;i<4;i++)
{
for(j=0;j<3;j++)
{tr[i][j]=0;
for(k=0;k<3;k++)
{
tr[i][j]=tr[i][j]+(a[i][k]*d[k][j]);
}
}
}


for(i=0;i<4;i++)
{
a[i][0]=t[i][0];
a[i][1]=t[i][1];
}
*/
rdraw();
}
};

int main()
{
transformation tra;
int q;
int y;
cout<<"\nEnter your choice\n1.Rhombus\n2.Triangle\n3.Exit";
cin>>q;
if(q==1)
{
tra.getdata();
tra.display();
}
else if(q==2)
{

tra.getdata();
tra.display();
}
else if(q==3)
return 0;
int x=0;
int gd=DETECT,gm;
initgraph(&gd,&gm,NULL);
if(q==1)
{
tra.rdraw();
while(x!=4)
{
cout<<"\nEnter the operation\n1.Scaling\n2.Rotation\n3.Translation\n4.Exit";

cin>>x;
switch(x)
{
case 1:
tra.rscale();
break;
case 2:
tra.rrotation();
break;
case 3:
tra.rtranslation();
break;
default:
return 0;
}
}
}
if(q==2)
{tra.tdraw();
while(x!=4)
{
cout<<"\nEnter the operation\n1.Scaling\n2.Rotation\n3.Translation\n4.Exit";

cin>>x;
switch(x)
{
case 1:
tra.tscale();
break;
case 2:
tra.trotation();
break;
case 3:
tra.ttranslation();
break;
default:
return 0;
}
}
}
getch();
}
