#include<stdio.h>
#include<stdlib.h>
#define INF 1e18
//queue representation
int front=-1;
int rear=-1;
#define MAX 100
int queue[MAX];
void enqueue(int val)
{
    if(rear==MAX-1)
    {
        printf("overflow\n");
    }
    else{
        if(front==-1)front=0;
        queue[++rear]=val;

    }
}
int dequeue()
{
    int val;
    if(front==-1||front>rear)
    {
        printf("underflow\n");
        val = -999;
    }
    else{
        val=queue[front++];
        
    }
    return val;
}
int main()
{

}