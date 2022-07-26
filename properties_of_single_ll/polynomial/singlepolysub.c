#include<stdio.h>
#include<stdlib.h>
struct node {
    int coef;
    int exponent;
    struct node * next;

};
void insert_end(struct node **start,struct node ** last,int coef, int exponent)
{
    struct node *temp=NULL;
    temp=(struct node *)malloc(sizeof (struct node));
    temp->coef=coef;
    temp->exponent=exponent;
    temp->next=NULL;
    if(*start==NULL)
    {
        *start=temp;
        *last=temp;
    }
    else{
        (*last)->next=temp;
        (*last)=(*last)->next;
    }
}
void join(struct node **start1,struct node *start2)
{
    if(*start1==NULL)
    {
        *start1=start2;
    }
    else{
        struct node *q;
        for(q=*start1;q->next!=NULL;q=q->next);
        q->next=start2;
    }
}
void display(struct node *start)
{
    struct node *q=start;
    while(q!=NULL)
    {
        printf("%d %d\n",q->coef,q->exponent);
        q=q->next;
    }
}
int main()
{
    struct node * start1,*start2,*start3,*last1,*last2,*p1,*p2,*prev;
    start1=start2=start3=last1=last2=p1=p2=prev=NULL;
    int n1;
    printf("enter the no. of elements in ll1:");
    scanf("%d",&n1);
    for (int i = 0; i < n1; i++)
    {
        int coef,exponent;
        scanf("%d%d",&coef,&exponent);
        insert_end(&start1,&last1,coef,exponent);
    }
    printf("enter the no. of elements of ll2:");
    int n2;
    scanf("%d",&n2);
    for (int i = 0; i < n2; i++)
    {
        int coef,exponent;
        scanf("%d%d",&coef,&exponent);
        insert_end(&start2,&last2,coef,exponent);

    }
    join(&start1,start2);
    for ( p1=start1;p1!=NULL;p1=p1->next)
    {
        prev=p1;
        for (p2=p1->next;p2!=NULL;)
        {
            if(p1->exponent!=p2->exponent)
            {
                prev=p2;
                p2=p2->next;
            }
            else{
                p1->coef=p1->coef-p2->coef;
                prev->next=p2->next;
                free(p2);
                p2=prev->next;
            }
        }
           
    }
     display(start1);
    
    
}