#include<stdio.h>
#include<stdlib.h>
#define MAX 100
#define INF 1e18
//in ll we can either put front pointer in the end and delete elements fromm the end and insert at the end 
// or we can put front pointer in the first and delete from the end and insert from beginning
struct node{
    int val;
    struct node *next;

}*front,*rear;                                     
void enqueue(int val)
{
    struct node *temp=(struct node *)malloc(sizeof(struct node));
    temp->val=val;
    temp->next=NULL;
    if(front==NULL)
    {
        front=rear=temp;
    }
    else{
        rear->next=temp;
        rear=rear->next;
    }

}
int dequeue()
{
    struct node *temp=(struct node*)malloc(sizeof(struct node));
    int val;
    if(front==NULL)
    {
        printf("underflow\n");
        val=-999;
    }
    else{
        temp=front;
        front=front->next;
        val=temp->val;
        free(temp);
    }
    return val;
}
int main()
{

}