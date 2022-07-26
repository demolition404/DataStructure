#include<stdio.h>
#include<stdlib.h>
struct node {
    int info;
    struct node*next;

}*last=NULL;
traverse(void)
{
    struct node *q;
    if(last!=NULL)
    {
        q=last->next;

    }
    do{
        printf("%d ",q->info);
        q=q->next;
    }
    while(q!=last->next);
}
insert_beg(int val)
{
    struct node *temp=(struct node *)malloc(sizeof(struct node));
    temp->info=val;
    if(last==NULL)
    {
        last=temp;
        temp->next=NULL;
    }
    else{
        temp->next=last->next;
        last->next=temp;
    }
}
insert_end(int val)
{
    struct node *temp=(struct node*)malloc(sizeof(struct node));
    temp->info=val;
    if(last==NULL)
    {
        last=temp;
        temp->next=temp;
    }
    else{
        temp->next=last->next;
        last->next=temp;
        last=temp;
    }
}
insert_after_node(int val,int after)
{
    if(last==NULL)
    {
        return;

    }
    struct node *q;
    q=last->next;
    while(q->info!=after)
    {
        q=q->next;
        if(q==last->next)
        {
            return;
        }
    }
    struct node *temp=(struct node*)malloc(sizeof(struct node));
    temp->next=q->next;
    q->next=temp;
    if(q==last)
    {
        last=temp;
    }
}
void deletion_beg()
{
    struct node *q;

    if(last==NULL)
    return;
    else if(last->next==last)
    {
        q=last->next;
        last=NULL;
        free(q);

    }
    else{
        q=last->next;
        last->next=last->next->next;
        free(q);

    }
}
void deletion_end()
{
    struct node *q,*temp;
    if(last==NULL)
    {
        return;
    }
    else if(last==last->next)
    {
        q=last;
        last=NULL;
        free(q);
    }
    else{
        q=last->next;
        while(q->next!=last)
        {
            q=q->next;
        }

        q->next=last->next;
        temp=last;
        last=q;
        free(temp);
    }
}
del_node(int val)
{
    struct node *q,*prev;
    if(last==NULL)
    {
        return;
    }
    while(q->info!=val)
    {
        prev=q;
        q=q->next;
    }
    if(q->next==q)
    {
        last=NULL;
        free(q);
    }
    else if(q==last->next){
        last->next=q->next;
        free(q);
    }
    else{
        prev->next=q->next;
        free(q);
    }
}