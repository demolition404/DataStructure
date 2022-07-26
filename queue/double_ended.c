#include<stdio.h>
#include<stdlib.h>
#define M 100
int left =-1;//basically front we change it here to maintain consistancy
int right =-1;
int Dqueue[M];
void insert_right(int val)
{
    if(left==-1 && right==M-1||left==right+1)
    {
        printf("overflow\n");
        return;
    }
    else if(left==-1)
    left=right=0;
    else if(right==M-1)
    right=0;
    else right++;
    Dqueue[right]=val;

}
void insert_left(int val)
{
    if(left==-1&&right==M-1||left==right+1)
    {
        printf("overflow\n");
        return;
    }
    else if(left==-1)
    left=right=0;
    else if(left==0)
    left=M-1;
    else left--;
    Dqueue[left]=val;
}
int delete_left()
{
    int val;
    if(left==-1)
    {
        printf("underflow\n");
        val=-999;
    }
    else if(left==right)
    {
        val=Dqueue[left];
        left=right=-1;
    }
    else if(left==M-1)
    {
        val=Dqueue[left];
        left=0;
    }
    else {
        val=Dqueue[left];
        left++;
    }
return val;
}
int delete_right()
{
    int val;
    if(left==-1)
    {
        printf("underflow\n");
        val=-999;
    }
    else if(left==right)
    {
        val=Dqueue[right];
        left=right=-1;
    }
    else if(right==0)
    {
        val=Dqueue[right];
        right=M-1;
    }
    else{
        val=Dqueue[right];
        right--;
    }
    return val;
}
void display()
{
    for (int i = left; i <= right; i++)
    {
        printf("%d ",Dqueue[i]);
    }
    
}
int main()
{
    while(1)
    {
        printf("1.insert right\n2.insert left\n3.delete right\n4.delete left\n5.display\n6.exit");
        int c;
        int p,e;
        scanf("%d",&c);
        switch(c)
        {
            case 1:
            printf("enter element:");
            
            scanf("%d",&e);
            insert_right(e);
            break;
            case 2:
            printf("enter element:");
            
            scanf("%d",&e);
            insert_left(e);
            break;
            case 3:
            p=delete_right();
            printf("element deleted:%d",p);
            break;
            case 4:
            p=delete_left();
            printf("element deleted:%d",p);
            break;
            case 5:
            display();
            break;
            case 6:exit(1);
            break;
            default:printf("wrong choice\n");


        }
    }
}