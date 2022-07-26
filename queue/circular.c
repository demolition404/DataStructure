#include<stdio.h>
#include<stdlib.h>
#include<ctype.h>
#define M 100
int queue[M];
int front = -1;
int rear = -1;
//circular queue;
void enqueue_circular(int val)
{
    if(front==-1&&rear==M-1||(front==rear+1))
    {
        printf("overflow\n");

    }
    else if(front==-1)
    front=rear=0;
    else if(rear==M-1)
    rear=0;
    else rear++;
    queue[rear]=val;

}
int dequeue_circular()
{
    int val;
    if(front==-1)
    {
        val=-999;
        printf("underflow\n");
    }
    else if(front==rear)
    {
        val=queue[front];
    }
    else if(front==M-1)
    {
        val=queue[front];
        front=0;
    }
    else{

        val=queue[front++];
    }
    return val;
}
void display()
{
    for (int i = front; i <= rear; i++)
    {
        printf("%d ",queue[i]);
    }
    
}

int main()
{
    printf("enter size::\n");
    int n;
    int d;
    scanf("%d",&n);
    while(1)
    { 
        int c;
        printf("1.enqueue\n2.dequeue\n3.display");
        scanf("%d",&c);
        switch(c)
        {
            case 1:
            printf("enter no. of elements you want to enqueue:");
            int m;
            scanf("%d",&m);
            printf("enter the elements:\n");
            for (int i = 0; i < m; i++)
            {
                int p;
                scanf("%d",&p);
                enqueue_circular(p);
            }
            break;
            case 2:
            d=dequeue_circular();
            break;
            case 3:
            display();
            break;
            case 4:exit(1);
            default:printf("wrong choice\n");

            
        }
    }
}