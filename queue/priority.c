//priority queue
# include<stdio.h>  
# include<malloc.h>  
  
struct node  
    {  
    int priority;  
    int info;  
    struct node *link;  
}*front = NULL;  
  
// insert method  
void insert(int data,int priority)  
{  
    struct node *temp,*q;  
  
    temp = (struct node *)malloc(sizeof(struct node));  
    temp->info = data;  
    temp->priority = priority;  
    // condition to check whether the first element is empty or the element to be inserted has more priority than the first element  
    if( front == NULL || priority < front->priority )  
    {  
        temp->link = front;  
        front = temp;  
    }  
    else  
    {  
        q = front;  
        while( q->link != NULL && q->link->priority <= priority )  
            q=q->link;  
        temp->link = q->link;  
        q->link = temp;  
    }  
}  
  
// delete method  
  
void del()  
{  
    struct node *temp;  
        // condition to check whether the Queue is empty or not  
    if(front == NULL)  
        printf("Queue Underflow\n");  
    else  
    {  
        temp = front;  
        printf("Deleted item is %d\n", temp->info);  
        front = front->link;  
        free(temp);  
    }  
}  
// display method  
void display()  
{  
    struct node *ptr;  
    ptr = front;  
    if(front == NULL)  
        printf("Queue is empty\n");  
    else  
    {     
        printf("Queue is :\n");  
        printf("Priority       Item\n");  
        while(ptr != NULL)  
        {  
            printf("%5d        %5d\n",ptr->priority,ptr->info);  
            ptr = ptr->link;  
        }  
    }  
}  
/*End of display*/  
  
// main method  
int main()  
{  
    int choice, data, priority;  
    do  
    {  
        printf("1.Insert\n");  
        printf("2.Delete\n");  
        printf("3.Display\n");  
        printf("4.Quit\n");  
        printf("Enter your choice : ");  
        scanf("%d", &choice);  
        switch(choice)  
        {  
            case 1:  
                printf("Enter the data which is to be added in the queue : ");  
                scanf("%d",&data);  
                printf("Enter its priority : ");  
                scanf("%d",&priority);  
                insert(data,priority);  
                break;  
            case 2:  
                del();  
                break;  
            case 3:  
                display();  
                break;  
            case 4:  
            break;  
                default :  
                printf("Wrong choice\n");  
        }  
    }while(choice!=4);  
  
    return 0;  
}