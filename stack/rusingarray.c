#include<stdio.h>
#include<stdlib.h>
int stack[100];
int top=-1;
void push(int val)
{
    stack[++top]=val;
}
int pop()
{
    if(top==-1)
    return -1;
    else{
        return stack[top--];
    }
}
int main()
{
    int n;
    scanf("%d",&n);
    for(int t=0;t<n;t++)
    {
        int a;
        scanf("%d",&a);
        push(a);

    }
    for(int t=0;t<n;t++)
    {
        int b;
        b=pop();
        printf("%d ",b);

    }
    return 0;
}