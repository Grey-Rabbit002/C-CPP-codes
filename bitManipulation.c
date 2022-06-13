#include<stdlib.h>
#include<math.h>
#include<stdio.h>

void main()
{
    // unsigned int a=69;
    // unsigned int b=149;
    // unsigned int  ones =pow(2,32)-1-a;
    // unsigned int  twos =pow(2,32)-a;
    // printf("ones compliment of a is %d\t and two's compliment is %d\t\n",ones,twos);
    // printf("%",~a);

    int arr[]={9,7,11,6,7,9,8,8,11};
    int x=0;
    for(int i=0;i<9;++i)
    {
        x=x^arr[i];//get the non repeated element from the array 
    }
    printf("%d",x);
}