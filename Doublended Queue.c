#include <stdio.h>
#define MAX 5

int deque[MAX];
int front = -1, rear = -1;

// Function prototypes
void insert_front();
void insert_rear();
void delete_front();
void delete_rear();
void display();

int main() {
    int choice;

    do {
        printf("\nDeque Operations Menu:\n");
        printf("1. Insert at Front\n");
        printf("2. Insert at Rear\n");
        printf("3. Delete from Front\n");
        printf("4. Delete from Rear\n");
        printf("5. Display\n");
        printf("6. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1: insert_front(); break;
            case 2: insert_rear(); break;
            case 3: delete_front(); break;
            case 4: delete_rear(); break;
            case 5: display(); break;
            case 6: printf("Exiting...\n"); break;
            default: printf("Invalid choice! Try again.\n");
        }
    } while (choice != 6);

    return 0;
}

// Insert at front
void insert_front() {
    int value;
    if ((front == 0 && rear == MAX - 1) || (front == rear + 1)) {
        printf("Deque Overflow\n");
    } else {
        printf("Enter the value to insert at front: ");
        scanf("%d", &value);
        if (front == -1) { // Initialize deque
            front = rear = 0;
        } else if (front == 0) {
            front = MAX - 1;
        } else {
            front--;
        }
        deque[front] = value;
        printf("%d inserted at the front\n", value);
    }
}

// Insert at rear
void insert_rear() {
    int value;
    if ((front == 0 && rear == MAX - 1) || (front == rear + 1)) {
        printf("Deque Overflow\n");
    } else {
        printf("Enter the value to insert at rear: ");
        scanf("%d", &value);
        if (front == -1) { // Initialize deque
            front = rear = 0;
        } else if (rear == MAX - 1) {
            rear = 0;
        } else {
            rear++;
        }
        deque[rear] = value;
        printf("%d inserted at the rear\n", value);
    }
}

// Delete from front
void delete_front() {
    if (front == -1) {
        printf("Deque Underflow\n");
    } else {
        printf("%d deleted from the front\n", deque[front]);
        if (front == rear) { // Deque becomes empty
            front = rear = -1;
        } else if (front == MAX - 1) {
            front = 0;
        } else {
            front++;
        }
    }
}

// Delete from rear
void delete_rear() {
    if (front == -1) {
        printf("Deque Underflow\n");
    } else {
        printf("%d deleted from the rear\n", deque[rear]);
        if (front == rear) { // Deque becomes empty
            front = rear = -1;
        } else if (rear == 0) {
            rear = MAX - 1;
        } else {
            rear--;
        }
    }
}

// Display the deque
void display() {
    if (front == -1) {
        printf("Deque is empty\n");
    } else {
        printf("Deque elements: ");
        int i = front;
        while (1) {
            printf("%d ", deque[i]);
            if (i == rear) break;
            i = (i + 1) % MAX;
        }
        printf("\n");
    }
}