#include<stdio.h>
#include<stdlib.h>
#define size 5
int stack[size];
int top=-1;

void push()
{   int item;
    printf("\n enter a item for  insert in stack:");
    scanf("%d",&item);

    if(top==size-1)
    {
        printf("\noverflow");
    }
    else
    {
        // stack[++top]=++item;
        top++;
        stack[top]=item;   
    }
    
}
void pop()
{   int item;
    if(top==-1)
    {
        printf("\nunderflow");
    }
    else
    {
        // item=stack[top--];
        item=stack[top];
        top--;
        printf("\n popped item %d",item );
    }
}
void display()
{   if(top==-1)
    {
        printf("\nstack is empty!");
    }
    else
    {
        int i;  
        printf("\nelements are:\n");
        for(i=top;i>=0;i--)
        // for(int i=0;i<=top;i++)
        {
            printf("  %d   ",stack[i]);
        }
    }
   
}

void main()
{
    int ch;
    while(1)
    {   
         printf("\n stack operation\n");
         printf( "press :\n 1. push \n 2. pop \n 3. display\n 4. EXIT \n enter your choice:");
         scanf("%d",&ch);
    
        switch(ch)
        {
            case 1:
                push();
                break;
            case 2:
                pop();
                break;
            case 3:
                display();
                break;
            case 4:
                exit(0);
            default:
                printf("invalid choice!");
                break;

        }
    }
}
