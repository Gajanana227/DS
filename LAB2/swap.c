#include<stdio.h>
void swap(int*, int*);
void main()
{
    int a,b;
    printf("Enter two numbers:\n");
    scanf("%d%d",&a,&b);
    printf("Before swapping, values of a and b are:%d%d",a,b);
    swap(&a,&b);

}
void swap(int *p,int *q)
{
    int temp;
    temp=*p;
    *p=*q;
    *q=temp;
    printf("After swapping,values of a and b are:%d%d",*p,*q);

}
