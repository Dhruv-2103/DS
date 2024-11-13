#include<stdio.h>
#define max 5
int front=-1;
int rear=-1;
int arr[max];

void addqueue(int item)
{
    if(rear==max-1)
    {
        printf("\nqueue is full!");
        return;
    }
    // rear++;
    arr[++rear]=item;
    
    if(front==-1)
    {
        front=0;
    }
    printf("\n%d is inserted",item );
}
int delqueue()
{   
    int data;
    if(front==-1)
    {
        printf("\nqueue is empty!");
        return 0;
    }
    data=arr[front];
    arr[front]=0;
    if (front==rear)
    {
        // front=-1;
        front=rear=-1;
    }
    else
    {
        front++;
    }
    return data;
}
void display()
{
    if(rear==-1)
    {
        printf("queue is empty!");
    }
    else
    {   
        printf("elements in queue \t\t |");
        for(int i=0;i<max;i++)
        {
            printf(" %d |",arr[i]);
        }
        printf("\n");
    }  
}
void main()
{      
    int ch,item,data;
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
                addqueue(item);
                break;
            case 2:
                data=delqueue();
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