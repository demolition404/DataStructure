#include<stdio.h>
#include<stdlib.h>
struct node {
    int row;
    int col;
    int val;
    struct node *next;
};
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
     // add the two sparse
     // join the two sparse & similar row col add
     join(&sparse1,sparse2);
     struct node *p1,*p2,*prev=NULL;
     p1=p2=NULL;
     for ( p1=sparse1;p1!=NULL;p1=p1->next)
     {
         prev=p1;
         for(p2=p1->next;p2!=NULL;)
         {
             if(p1->row!=p2->row||p1->col!=p2->col)
             {
                 prev=p2;
                 p2=p2->next;
             }
             else if(p2->row==p1->row&&p2->col==p1->col)
             {
                 p1->val=p2->val+p1->val;
                 prev->next=p2->next;
                 free(p2);
                 p2=prev->next;
             }
         }
     }
     display(sparse1);


     
}