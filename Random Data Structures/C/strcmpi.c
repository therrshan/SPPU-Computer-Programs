#include <stdio.h>
#include <string.h>
int main( )
{
   char str1[10],str2[10];
   int i,j,k;
   printf("Enter the strings:");
   scanf(%s %s,&str1,&str2);
   char str3[]="fresh";
   i = strcmpi ( str1,str3 ) ;
   j = strcmpi ( str1,str2 ) ;
   k = strcmpi ( str3,"FRESH" ) ;
   printf ( "\n%d %d %d", i, j, k ) ;
   return 0;
}

