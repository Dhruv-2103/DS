#include <stdio.h>
#include <stdlib.h>

// Structure to represent a node in the circular linked list
struct Node {
    int data;
    struct Node *next;
};

// Function prototypes
void insert(int data);
void deleteNode(int data);
void display();
int search(int data);
void deleteList();

struct Node *head = NULL;

int main() {
    int choice, data;

    while (1) {
        printf("\nCircular Linked List Operations:\n");
        printf("1. Insert\n2. Delete\n3. Display\n4. Search\n5. Delete Entire List\n6. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                printf("Enter data to insert: ");
                scanf("%d", &data);
                insert(data);
                break;
            case 2:
                printf("Enter data to delete: ");
                scanf("%d", &data);
                deleteNode(data);
                break;
            case 3:
                display();
                break;
            case 4:
                printf("Enter data to search: ");
                scanf("%d", &data);
                if (search(data)) {
                    printf("Element %d found in the list.\n", data);
                } else {
                    printf("Element %d not found in the list.\n", data);
                }
                break;
            case 5:
                deleteList();
                break;
            case 6:
                printf("Exiting...\n");
                return 0;
            default:
                printf("Invalid choice. Try again.\n");
        }
    }

    return 0;
}

// Function to insert a node at the end of the circular linked list
void insert(int data) {
    struct Node *newNode = (struct Node *)malloc(sizeof(struct Node));
    struct Node *temp = head;

    newNode->data = data;
    newNode->next = head;

    if (head == NULL) {
        head = newNode;
    } else {
        while (temp->next != head) {
            temp = temp->next;
        }
        temp->next = newNode;
    }
}

// Function to delete a node from the circular linked list
void deleteNode(int data) {
    struct Node *temp = head, *prev;

    if (head == NULL) {
        printf("List is empty.\n");
        return;
    }

    // Case when head node itself holds the key to be deleted
    if (head->data == data) {
        while (temp->next != head) {
            temp = temp->next;
        }
        temp->next = head->next;
        free(head);
        head = temp->next;
    } else {
        while (temp->next != head && temp->data != data) {
            prev = temp;
            temp = temp->next;
        }
        if (temp->data == data) {
            prev->next = temp->next;
            free(temp);
        } else {
            printf("Element %d not found.\n", data);
        }
    }
}

// Function to display the circular linked list
void display() {
    struct Node *temp = head;

    if (head == NULL) {
        printf("List is empty.\n");
        return;
    }

    printf("Circular Linked List: ");
    do {
        printf("%d -> ", temp->data);
        temp = temp->next;
    } while (temp != head);
    printf("\n");
}

// Function to search for an element in the circular linked list
int search(int data) {
    struct Node *temp = head;

    if (head == NULL) return 0;

    do {
        if (temp->data == data) {
            return 1;
        }
        temp = temp->next;
    } while (temp != head);

    return 0;
}

// Function to delete the entire circular linked list
void deleteList() {
    struct Node *temp = head;

    if (head == NULL) {
        printf("List is already empty.\n");
        return;
    }

    do {
        struct Node *next = temp->next;
        free(temp);
        temp = next;
    } while (temp != head);

    head = NULL;
    printf("All nodes deleted.\n");
}