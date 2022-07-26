#include<stdio.h>

#include<stdlib.h>
int stack[100];
int topA=-1,topB=100;
void pushA(int val)
{
    if(topA==topB-1)
    printf("overflow\n");
    else{
        stack[++topA]=val;
    }
}
int popA()
{
    if(topA==-1)
    {
        printf("underflow\n");
        return -1;
    }
    else{
        return stack[topA--];
    }
}
void pushB(int val)
{
    if(topB==99)
    printf("overflow\n");
    else{
        stack[--topB]=val;
    }
}
int popB()
{
    if(topB==100)
    {
        printf("underflow\n");
        return -1;
    }
    else{
        return stack[topB++];
    }
}
void display()
{
    if(topA==-1)
    {
        printf("no elements in A\n");   
    }
    else{
         printf("elements of A:");
        for (int i = 0; i <= topA; i++)
        {
            printf("%d ",stack[i]);
        }
    
    }
    if(topB==100)
    {
        printf("no elements in B\n");
    }
    else{
        printf("elements of B:");
        for (int i = topB; i < 100; i++)
        {
            printf("%d ",stack[i]);
        }
        printf("\n");
    }
    
    
    
}
int main()
{
    
    printf("enter the no. of elements in the 2 stacks\n");
    while(1)
    {
        printf("1.push element in A\n");
        printf("2.pop element from A\n");
        printf("3.push element in B\n");
        printf("4.pop element from B\n");
        printf("5.exit program\n");
        printf("6.display stack\n");
        int n,val,r;
        scanf("%d",&n);
        switch(n)
        {
            case 1:
            val;
            scanf("%d",&val);
            pushA(val);
            break;
            case 2:
            r;
            r=popA();
            break;
            case 3:
            val;
            scanf("%d",&val);
            pushB(val);
            break;
            case 4:
            r;
            r=popB();
            break;
            case 5:return 0;
            case 6:display();
            
        }
    }
    
   return 0;

}