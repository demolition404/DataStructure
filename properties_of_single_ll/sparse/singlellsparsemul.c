#include<stdio.h>
#include<stdlib.h>
struct node {
    int row;
    int col;
    int val;
    struct node *next;
};
struct head{
    int tr;
    int tc;
    int te;
    struct node *next;
};
transpose(struct head**h)
{
    int t;
    struct node *q;
    t=(*h)->tr;
    (*h)->tr=(*h)->tc;
    (*h)->tc=t;
    q=(*h)->next;
    while(q!=NULL)
    {
        t=q->row;
        q->row=q->col;
        q->col=t;
    }
}
struct head ** sparse_multiplication(struct head*h1,struct head*h2)
{
    struct node *p1,*p2,*p3,*last=NULL;
    if(h1->tc!=h2->tr)
    {
        return;
    }
    struct head *h3=(struct head *)malloc(sizeof (sizeof(struct head)));
    h3->tr=h1->tr;
    h3->tc=h2->tc;
    h3->next=NULL;
    int cnt=0;
    for(p1=h1->next;p1!=NULL;p1=p1->next)
    {
        for(p2=h2->next;p2!=NULL;p2=p2->next)
        {
            if(p1->col==p2->row)
            {
                insert_end(&h3,&last,p1->row,p2->col,p1->val*p2->val);
                cnt++;
            }

        }
    }
    struct node *prev=NULL;
    for(p1=h3->next;p1!=NULL;p1=p1->next)
    {
        prev=p1;
        for(p2=p1->next;p2!=NULL;)
        {
            if(p1->row==p2->row||p1->col==p2->col)
            {
                prev=p2;
                p2=p2->next;

            }
            else{
                p1->val=p1->val*p2->val;
                prev->next=p2->next;
                free(p2);
                p2=prev->next;
                cnt--;
            }
        }
    }
    h3->te=cnt;
    return h3;
}
void insert_end(struct node **start,struct node **last,int row,int col,int val)
{
    struct node * temp;
    temp=(struct node *)malloc (sizeof (struct node ));
    temp->row=row;
    temp->col=col;
    temp->val=val;
    temp->next=NULL;
    if((*start)==NULL)
    {
        *start=temp;
        *last=temp;

    }
    else{

        (*last)->next=temp;
        *last=(*last)->next;

    }
}

void display(struct node *s)
{
    struct node *q;
    q=s;
    while(q!=NULL)
    {
        printf("%d %d %d\n",q->row,q->col,q->val);
        q=q->next;
    }
}
int main()
{
     struct node *sparse1,*sparse2,*last1=NULL,*last2=NULL;
     sparse1=sparse2=NULL;
     printf("enter the no. of elements in sp1:");
     int n1,n2;
     scanf("%d",&n1);
     for (int i = 0; i < n1; i++)
     {
         int row,col,ele;
         scanf("%d%d%d",&row,&col,&ele);
         insert_end(&sparse1,&last1,row,col,ele);
     }
     printf("enter the no. of elements in sp2:");
     scanf("%d",&n2);
     for (int i = 0; i < n2; i++)
     {
         int row,col,ele;
         scanf("%d%d%d",&row,&col,&ele);
         insert_end(&sparse2,&last2,row,col,ele);

     }
     struct node *q=NULL,*p=NULL;
     struct node *ans=NULL;

    for ( q=sparse1;q!=NULL;q=q->next)
    {
        for(p=sparse2;p!=NULL;p=p->next)
        {
           if(q->col==p->row)
           {
               ans->row=q->row;
               ans->col=q->col;
               ans->val=q->val+p->val;
               ans=ans->next;
           }
           else{
               
           }
        }
    }
     
    
     


     
}