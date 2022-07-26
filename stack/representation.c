#include<stdio.h>
#include<stdlib.h>
//linked list reperesentation
struct node{
    int info;
    struct node *next;
};
struct node *top;


void push(int val)
{
    struct node *temp=(struct node *)malloc(sizeof(struct node));
    temp->info=val;
    temp->next=top;
    top=temp;

}
int* pop(void)
{
    struct  node*temp=top;
    if(top==NULL)
    {
        printf("underflow");
        return -999;

    }
    else{
        free(temp);
        return top->info;
    }
}
void display(struct node *start)
{
    while(start!=NULL)
    {
        printf("%d ",start->info);
        start=start->next;
    }

}

int main()
{
    struct node*start;
    start=NULL;
    int n;
    top=start;
    scanf("%d",&n);
    for(int t=0;t<n;t++)
    {
        int val;
        scanf("%d",&val);
        push(val);

    }
    
    for(int t=0;t<n;t++){
        int *a;
        a=pop();
        
        printf("%d ",*a);
    }
    return 0;
}