#include <stdio.h>
#include <stdlib.h>

int n, *S;
int Top = -1;

void Push();
void Pop();
void show();

int main()
    int choice;
    printf("Enter size of the Stack: ");
    scanf("%d", &n);
    
    // Allocate memory for the stack
    S = (int*)malloc(n * sizeof(int));
    if (S == NULL) {
        printf("Memory allocation failed!\n");
        return 1; // Return an error code
    }

    while (1) {
        printf("\nOperations performed by Stack");
        printf("\n1.Push the element\n2.Pop the element\n3.Show\n4.End");
        printf("\n\nEnter the choice: ");
        scanf("%d", &choice);
        
        switch (choice) {
            case 1: 
                Push();
                break;
            case 2: 
                Pop();
                break;
            case 3: 
                show();
                break;
            case 4:
                free(S);
                exit(0);
            default:
                printf("\nInvalid choice!!");
        }
    }
    
    return 0;
}

void Push() {
    int item;
    printf("Value of n is: %d\n", n);
    if (Top == n - 1) {
        printf("\nOverflow!!");
    } else {
        printf("\nEnter element to be inserted to the stack: ");
        scanf("%d", &item);
        Top = Top + 1;
        S[Top] = item;
        printf("\nElement inserted successfully...\n");
    }
}

void Pop() {
    if (Top == -1) {
        printf("\nUnderflow!!");
    } else {
        printf("\nPopped element: %d", S[Top]);
        Top = Top - 1;
    }
}

void show() {
    int i;
    if (Top == -1) {
        printf("\nUnderflow!!");
    } else {
        printf("\nElements present in the stack: \n");
        for (i = Top; i >= 0; i--) {
            printf("%d\n", S[i]);
        }
    }
}
