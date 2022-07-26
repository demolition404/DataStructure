#include <stdio.h>
#include <stdlib.h>
#define TRUE 0
#define FALSE 1
struct node{
    int info;
    struct node *next;


}*start;
void delete_beg()
{
    struct node*q;
    q=start;

    if(start==NULL)
    {
        printf("nothing to delete\n");
        return;
    }
    else if(start->next==NULL)
    {
        start=start->next;
        free(q);
    }
    else{
        start=q->next;
        free(q);
    }
}
void delete_end()
{
    struct node *q,*p;
    q=start;
    p=q;
    if(start==NULL)
    {
        printf("no element to delete\n");
        return;
    }
    else if(q->next==NULL){
        start=NULL;
        free(q);

    }
    else{
        while(q->next!=NULL)
        {
            p=q;
            q=q->next;
        }
        free(q);
        p->next=NULL;
    }
}
void delete_from_pos(int pos)
{
    
    struct node *q,*temp,*p;
    q=start;
    if(start==NULL)
    {
        printf("nothing to delete\n");
        return;
    }
    else{
        for (int i=1;i<pos&&q!=NULL; i++,p=q,q=q->next);
        if(q==NULL)
        {
            printf("invalid position .. nothing to delete\n");
            return;
        }
        else{
            
            p->next=q->next;
            free(q);
        }
        
    }

}
int search(int ele)
{
    struct node *q;
    int f=0;
    q=start;
    while(q!=NULL)
    {
        if(q->info==ele)
        {
            f=1;
            return 1;

        }
        q=q->next;
    }
    if(f==0)
    {
        return 0;
    }

}
void delete_ele(int ele)
{// 1 2 3 4 5 5 6
//5
//1 2 3 4 6
    struct node *q,*p;
    q=start;
    if(start==NULL)
    {
        printf("no elements to be deleted\n");
        return;
    }

    for (int i = 1; q!=NULL; i++,p=q,q=q->next)
    {
        if(q->info==ele)
        {
           
           delete_from_pos(i);
           q=p;
        }
        
    }
    

}
void total()
{
    struct node *q;
    int  sum=0;
    q=start;
    while(q!=NULL)
    {
        sum+=q->info;
        q=q->next;

    }
    printf("%d\n",sum);
}
void count()
{
    int cnt=0;
    struct node *q;
    q=start;
    while(q!=NULL)
    {
        cnt++;
        q=q->next;
    }
    printf("%d\n",cnt);
}
void insert_after(int ele,int after_ele)
{
    struct node *temp,*q;
    temp=(struct node*)malloc(sizeof (struct node));
    temp->info=ele;
    if(start==NULL)
    {
        printf("invalid input\n");
        return;
    }
    else{
        q=start;
        while(q->info!=after_ele&&q!=NULL)
        {
            q=q->next;
        }
        if(q!=NULL)
        {
            temp->next=q->next;
            q->next=temp;
        }
        else if(q==NULL)
        {
            printf("invalid input\n");
            return;
        }
    }

}
void insert_before(int ele,int before_ele)
{
    struct node * temp,*q;
    temp=(struct node*)malloc(sizeof(struct node));
    temp->info=ele;
    if(start==NULL)
    {
        printf("invalid input\n");
        return;
    }
    else{
        q=start;
        if(q->info==before_ele)
        {
            start=temp;
            temp->next=q;
        }
        else{
            while(q->next->info!=before_ele&&q!=NULL)
            {
                q=q->next;
            } 
            if(q==NULL)
            {
             printf("invalid input\n");
             return;

            }
            else{
                temp->next=q->next;
                q->next=temp;
            }
           
       
        }
    }
}
void insert_beg(int ele)
{
    struct node *temp;
    temp=(struct node*)malloc(sizeof(struct node));
    temp->info=ele;
    if(start==NULL)
    {
        start=temp;
        temp->next=NULL;

    }
    else{
        temp->next=start;
        start=temp;


    }
}
void insert_end(int ele)
{
    struct node* temp,*q;
  
    temp=(struct node*)malloc(sizeof(struct node));
    temp->info=ele;
    temp->next=NULL;
    if(start==NULL)
    {
        start=temp;
       
    }
    else{
        q=start;
        while(q->next!=NULL)
        {
            q=q->next;
        }
        q->next=temp;
        
        

    }
}
void sort()
{
    struct node*p,*q;
    struct node *temp;
    int t;
    temp=(struct node*)malloc(sizeof (struct node));
    for ( q = start; q->next!=NULL ; q=q->next)
    {
        for (p=q->next; p!=NULL ; p=p->next)
        {
            if(p->info>q->info)
            {
                t=q->info;
                q->info=p->info;
                p->info=t;
            }
        }
        
    }
    
}
void reverse()
{
    
    struct node *p1,*p2,*p3;
    p1=start;
    p2=p1->next;
    p3=p2->next;
    p1->next=NULL;
    p2->next=p1;
    if(start==NULL)
    return;
    
    while(p3!=NULL)
    {
        p1=p2;
        p2=p3;
        p3=p3->next;
        p2->next=p1;
    }
    start=p2;
}
void display()
{
    struct node *q;
    q=start;
    while(q!=NULL)
    {
        printf("%d\n",q->info);
        q=q->next;
    }
}
void insert_sort(int ele)
{
    struct node *q=start,*prev=q,*temp;
    temp=(struct node*)malloc(sizeof(struct node));
    temp->info=ele;
    if(start==NULL||start->info>ele)
    {
        temp->next=start;
        start=temp;
    }
    else{
        while(q!=NULL&&q->info<ele)
        {
            prev=q; 
            q=q->next;
        }
        
    temp->next=q;
    prev->next=temp;
    }
}

int main()
{
    struct node *start;
    
    
    int n;
    scanf("%d",&n);
    if(n==0)
    {
        start=NULL;
    }
    else{
        start=(struct node *)malloc(sizeof(struct node));
    }
    
    for (int i = 0; i < n; i++)
    {
        int p;
        scanf("%d",&p);
        insert_sort(p);
    }
    delete_from_pos(2);
   display();
}
  