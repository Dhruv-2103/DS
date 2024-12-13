#include <stdio.h>
#include <stdlib.h>

// Definition of a node in the doubly linked list
struct Node {
    int data;
    struct Node *prev;
    struct Node *next;
};

// Function prototypes
void insertFront(struct Node** start, int item);
void insertBack(struct Node** start, int item);
void deleteFront(struct Node** start);
void deleteBack(struct Node** start);
void displayList(struct Node* start);

int main() {
    struct Node* start = NULL;  // Pointer to the start of the list
    int choice, item;

    while (1) {
        printf("\nMenu:\n");
        printf("1. Insert at Front\n");
        printf("2. Insert at Back\n");
        printf("3. Delete from Front\n");
        printf("4. Delete from Back\n");
        printf("5. Display List\n");
        printf("6. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                printf("Enter item to insert at front: ");
                scanf("%d", &item);
                insertFront(&start, item);
                break;
            case 2:
                printf("Enter item to insert at back: ");
                scanf("%d", &item);
                insertBack(&start, item);
                break;
            case 3:
                deleteFront(&start);
                break;
            case 4:
                deleteBack(&start);
                break;
            case 5:
                displayList(start);
                break;
            case 6:
                exit(0);
                break;
            default:
                printf("Invalid choice!\n");
        }
    }

    return 0;
}

// Function to insert a node at the front
void insertFront(struct Node** start, int item) {
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    newNode->data = item;
    newNode->prev = NULL;
    newNode->next = *start;

    if (*start != NULL) {
        (*start)->prev = newNode;
    }
    *start = newNode;

    printf("Inserted %d at front.\n", item);
}

// Function to insert a node at the back
void insertBack(struct Node** start, int item) {
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    newNode->data = item;
    newNode->next = NULL;

    if (*start == NULL) {
        newNode->prev = NULL;
        *start = newNode;
    } else {
        struct Node* temp = *start;
        while (temp->next != NULL) {
            temp = temp->next;
        }
        temp->next = newNode;
        newNode->prev = temp;
    }

    printf("Inserted %d at back.\n", item);
}

// Function to delete a node from the front
void deleteFront(struct Node** start) {
    if (*start == NULL) {
        printf("List is empty!\n");
        return;
    }

    struct Node* temp = *start;
    *start = (*start)->next;

    if (*start != NULL) {
        (*start)->prev = NULL;
    }

    printf("Deleted %d from front.\n", temp->data);
    free(temp);
}

// Function to delete a node from the back
void deleteBack(struct Node** start) {
    if (*start == NULL) {
        printf("List is empty!\n");
        return;
    }

    struct Node* temp = *start;
    while (temp->next != NULL) {
        temp = temp->next;
    }

    if (temp->prev != NULL) {
        temp->prev->next = NULL;
    } else {
        *start = NULL;
    }

    printf("Deleted %d from back.\n", temp->data);
    free(temp);
}

// Function to display the doubly linked list
void displayList(struct Node* start) {
    if (start == NULL) {
        printf("List is empty!\n");
        return;
    }

    printf("Doubly Linked List: \n");
    struct Node* temp = start;

    while (temp != NULL) {
        printf("%d <=> ", temp->data);
        temp = temp->next;
    }
    printf("NULL\n");
}