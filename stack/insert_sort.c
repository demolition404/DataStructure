#include<stdio.h>
#include<stdlib.h>
#include<ctype.h>
#define m 100
int stack[m];
int top=-1;
void push(int val)
{
    if(top==m-1)
    {
        printf("stack overflow\n");
        return;
    }
    else{
        stack[++top]=val;
    }
}
int pop()
{
    if(top==-1)
    {
        printf("stack underflow\n");
        return -1;
    }
    else{
        int x=stack[top--];
        return x;
    }
}
void insert_sort(int val)
{
    int x;
    if(top==-1)
    push(val);
    else if(val>stack[top])
    {
        push(val);
        return;
    }
    else{
        x=pop();
        insert_sort(val);
        push(x);
    }
}
void display(int stack[])
{
    while(top!=-1)
    {
        int x=pop();
        printf("%d ",x);

    }
    printf("\n");
}



int main()
{
    int n;
    scanf("%d",&n);
    for (int i = 0; i < n; i++)
    {
        int x;
        scanf("%d",&x);
        insert_sort(x);
    }
    display(stack);

}