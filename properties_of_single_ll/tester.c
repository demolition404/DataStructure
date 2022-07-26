#include<stdio.h>
#include<stdlib.h>
struct node
{
    int data;
    struct node* next;
};

void insertSortedly(struct node **head,int ele)
{
    struct node* dhead=*head;
    struct node* temp=(struct node *)malloc(sizeof(struct node));
    temp->data=ele;
    temp->next=NULL;


    if (dhead==NULL)
    {
        *head=temp;
        return;
    }

    if(dhead->data>ele)
    {
        temp->next=*head;
        *head=temp;
        return;
    }

    while (dhead->next!=NULL && dhead->next->data<=ele)
    {
        dhead=dhead->next;
    }
    
    if(dhead->next!=NULL)
    {
        temp->next=dhead->next;
        dhead->next=temp;
        return;
    }

    dhead->next=temp;
}

void display(struct node* head)
{
    while (head!=NULL)
    {
        printf("%d -> ",head->data);
        head=head->next;
    }
    printf("NULL");
}

int main()
{
    struct node* head=NULL;

    int n;
    printf("Enter the number of nodes\n");
    scanf("%d",&n);
   
    for (int i = 0; i < n; i++)
    {
        printf("Enter the element\n");
        int p;
        scanf("%d",&p);
        insertSortedly(&head,p);
    }

    display(head);
}