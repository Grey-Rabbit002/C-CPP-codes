#include<stdio.h>
#include<stdlib.h>
void main()
{
    char x[]="arjun";
    int d=sizeof(x)/sizeof(x[0]);
    printf("%d",d);
}