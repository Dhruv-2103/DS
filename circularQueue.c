#include<stdio.h>
#define max 5
int CQ[max];
int front=-1;
int rear=-1;

void insert(int item)
{
    if((rear==max-1 && front==0)||(rear+1==front)) 
    {
        printf("\nqueue is full!");
        return;   
    }
    if(rear==max-1)
    {
        rear=0;
    }
    else{
        rear++;
    }
    CQ[rear]=item;
    if(front==-1)
        front=0;
}
int delete()
{   int data;
    if(front==-1)
    {
        printf("\n queue is empty!");
    }
    data=CQ[front];
    CQ[front]=0;

    if(front==rear)
        front=rear=-1;
    else
    {
        if(front==max-1)
            front=0;
        else
            front++;
    }
    return data;
}
void display()
{
    if(rear==-1)
    {
        printf("empty!");
    }
    else
    {
        
        printf("elements in queue \t\t |");
        for(int i=0;i<max;i++)
        {
            printf(" %d |",CQ[i]);
        }
        printf("\n\n");
    }
}
void main()
{
    int item,ch,data;
     do{
        printf("\n \t insert item in queue press 1.");
        printf("\n \t delete item from queue press 2.");
        printf("\n \t display element of queue press 3.");
        printf("\n \t for exit press 4.");
        printf("\n \t enter your choice:");
        scanf("%d",&ch);

        switch(ch)
        {
            case 1:
                printf("\n enter item for insert:");
                scanf("%d",&item);
                insert(item);
                break;
            case 2:
                data=delete();
                printf("\n %d is deleted",data);
                break;
            case 3:
                display();
                break;
            case 4:
                break;
            default:
                printf("\n invalid choice!");
        }
    }while(ch!=4);
}