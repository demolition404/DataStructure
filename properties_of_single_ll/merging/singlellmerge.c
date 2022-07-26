#include<stdio.h>
#include<stdlib.h>
struct node{
    int info;
    struct node*next;
};
void insert_sort(struct node **start,int ele)
{
    struct node* q=*start,*temp;
    temp=(struct node*)malloc(sizeof(struct node));
    temp->info=ele;
    temp->next=NULL;
    if(q==NULL)
    {
       (*start)=temp;
       return;
    }
    if(q->info>ele)
    {
        temp->next=*start;
        (*start)=temp;
        return;
    }
    
        while(q->next!=NULL&&q->next->info<=ele)
        {
           
            q=q->next;
        }
        if(q->next!=NULL)
        {
            
            temp->next=q->next;
            q->next=temp;
            return;
        }
    
    
    q->next=temp;
}
void display(struct node *start)
{
   
    while(start!=NULL)
    {
        printf("%d -> ",start->info);
        start=start->next;
    }
    printf("NULL\n");
}
void insert_end(struct node ** start,struct node **last,int val)
{
    struct node * temp=(struct node *)malloc(sizeof(struct node));
    temp->info=val;
    temp->next=NULL;
    if(*start==NULL)
    {
        *start=temp;
        *last=temp;

    }
    else{
        (*last)->next=temp;
        *last=(*last)->next;
    }
}
struct node* merge(struct node *s1,struct node *s2)
{
    struct node * start3=NULL,*last=NULL;
    while(s1!=NULL&&s2!=NULL)
    {
        if(s1->info<s2->info)
        {
            insert_end(&start3,&last,s1->info);
            s1=s1->next;
        }
        else{
            insert_end(&start3,&last,s2->info);
            s2=s2->next;
        }

    }
    if(s1!=NULL)
    {
        for (; s1!=NULL;s1=s1->next)
        {
            insert_end(&start3,&last,s1->info);

        }

        
    }
    else{
        for (;s2!=NULL ;s2=s2->next)
        {
            insert_end(&start3,&last,s2->info);
        }
        
    }
    return start3;
}
int  main()
{
    struct node *start1,*start2,*start3;
    start1=start2=start3=NULL;
    printf("enter the no. of elements in ll 1:");
    int l1;
 
    scanf("%d",&l1);
    int value;
    for (int i = 0; i < l1; i++)
    {
        scanf("%d",&value);
        insert_sort(&start1,value);
    }
    printf("enter the no. of elemets in ll 2:");
    int l2;
    scanf("%d",&l2);
    for (int i = 0; i < l2; i++)
    {
        scanf("%d",&value);
        insert_sort(&start2,value);

    }
    start3=merge(start1,start2);
    display(start1);
    display(start2);
    display(start3);

    
    
}