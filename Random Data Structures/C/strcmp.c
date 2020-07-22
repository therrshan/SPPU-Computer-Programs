#include<stdio.h>
#include<string.h>
 
int main()
{ 
     
    char string1[10],string2[10];
    printf("Enter the two strings:");
    scanf("%s %s",&string1,&string2);
    printf("The strings entered are: %s %s",string1,string2);
    
    int a = strcmp(string1,string2);
     
    if (a==0)
        printf("Strings are equal");
    else
        printf("Strings are unequal");
     
    printf("\nValue returned by strcmp() is:  %d" , a);
    return 0;
}
