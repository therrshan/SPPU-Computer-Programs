#include <stdio.h>
#include <string.h>
int main( )
{
   char str2[10], str1[10]="darsh";
   str2[10]=strrev(str1);
   printf("The entered string is: %s",str1);
   printf ("The reversed string is : %s",str2) ;
   return 0;
}

