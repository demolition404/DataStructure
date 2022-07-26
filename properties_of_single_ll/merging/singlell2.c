#include<stdio.h>
#include<stdlib.h>
struct node{
    int val;
    struct node * next;

}*start;

void insert_end(int val)
{
    if(start==NULL)
    {
        start->val=val;
        start->next=NULL;
    }
    else{
        struct node * temp = (struct node*)malloc(sizeof(struct node)) ;
        temp=start;
        while(temp->next!=NULL)
        {
            temp=temp->next;
        }
        temp->val=val;
        temp->next=NULL;

    }

}
void print(struct node* start)
{
    while(start!=NULL)
    {
        printf("%d->",start->val);
        start=start->next;
    }
}
int main()
{
    struct node * start;
    int n;
    printf("enter the no. of nodes : ");
    scanf("%d",&n);
    for(int i=0;i<n;i++)
    {
        int val;
        scanf("%d",&val);
        insert_end(val);
    }
    print(start);
    return 0;
}