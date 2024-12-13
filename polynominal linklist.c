#include <stdio.h>
#include <stdlib.h>

// Structure to represent a term of a polynomial
struct Term {
    int coefficient;
    int exponent;
    struct Term *next;
};

// Function prototypes
void insertTerm(int coefficient, int exponent);
void displayPolynomial();
void addPolynomials(struct Term *poly1, struct Term *poly2);

struct Term *start = NULL;

int main() {
    int choice, coefficient, exponent;

    while (1) {
        printf("\nPolynomial Linked List Operations:\n");
        printf("1. Insert Term\n2. Display Polynomial\n3. Add Polynomials\n4. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                printf("Enter coefficient and exponent: ");
                scanf("%d %d", &coefficient, &exponent);
                insertTerm(coefficient, exponent);
                break;
            case 2:
                printf("Polynomial: ");
                displayPolynomial();
                break;
            case 3:
                // Create a second polynomial for addition
                struct Term *poly2 = NULL;
                insertTerm(3, 2);
                insertTerm(5, 1);
                insertTerm(7, 0);
                printf("\nSecond Polynomial: ");
                displayPolynomial(poly2);
                printf("\nAdding Polynomials: \n");
                addPolynomials(start, poly2);
                break;
            case 4:
                printf("Exiting...\n");
                return 0;
            default:
                printf("Invalid choice. Try again.\n");
        }
    }
    return 0;
}

// Function to insert a term into the polynomial linked list
void insertTerm(int coefficient, int exponent) {
    struct Term *newTerm = (struct Term *)malloc(sizeof(struct Term));
    newTerm->coefficient = coefficient;
    newTerm->exponent = exponent;
    newTerm->next = NULL;

    if (start == NULL || start->exponent < exponent) {
        newTerm->next = start;
        start = newTerm;
    } else {
        struct Term *temp = start;
        while (temp->next != NULL && temp->next->exponent > exponent) {
            temp = temp->next;
        }
        if (temp->next != NULL && temp->next->exponent == exponent) {
            temp->next->coefficient += coefficient;
            free(newTerm);
        } else {
            newTerm->next = temp->next;
            temp->next = newTerm;
        }
    }
}

// Function to display the polynomial
void displayPolynomial() {
    struct Term *temp = start;
    while (temp != NULL) {
        printf("%dX^%d", temp->coefficient, temp->exponent);
        if (temp->next != NULL)
            printf(" + ");
        temp = temp->next;
    }
    printf("\n");
}

// Function to add two polynomials
void addPolynomials(struct Term *poly1, struct Term *poly2) {
    struct Term *result = NULL;

    while (poly1 != NULL || poly2 != NULL) {
        int coeff, exp;
        if (poly1 == NULL) {
            coeff = poly2->coefficient;
            exp = poly2->exponent;
            poly2 = poly2->next;
        } else if (poly2 == NULL) {
            coeff = poly1->coefficient;
            exp = poly1->exponent;
            poly1 = poly1->next;
        } else if (poly1->exponent > poly2->exponent) {
            coeff = poly1->coefficient;
            exp = poly1->exponent;
            poly1 = poly1->next;
        } else if (poly1->exponent < poly2->exponent) {
            coeff = poly2->coefficient;
            exp = poly2->exponent;
            poly2 = poly2->next;
        } else {
            coeff = poly1->coefficient + poly2->coefficient;
            exp = poly1->exponent;
            poly1 = poly1->next;
            poly2 = poly2->next;
        }

        insertTerm(coeff, exp);
    }

    displayPolynomial();
}