#include <stdio.h>
#include <ctype.h>
#define max 15

int top = -1;
char S[max];

void push(char x) {
    S[++top] = x;
}

char pop() { 
    if (top == -1)
        return -1;
    else
        return S[top--];
}

int prcd(char c) { 
    if (c == '(')
        return 0;
    else if (c == '+' || c == '-')
        return 1;
    else if (c == '*' || c == '/')
        return 2;
    return -1; // Added return for invalid character
}

int infixtopostfix(char infix[max], char postfix[max]) {
    char temp, x;
    int i = 0, j = 0;
    while (infix[i] != '\0') {
        temp = infix[i];
        if (isalnum(temp)) {
            postfix[j++] = temp;
        } else if (temp == '(') {
            push(temp);
        } else if (temp == ')') {
            while ((x = pop()) != '(')
                postfix[j++] = x;
        } else { 
            while (prcd(S[top]) >= prcd(temp))
                postfix[j++] = pop();
            push(temp);
        }
        i++;
    }
    while (top != -1)
        postfix[j++] = pop();
    postfix[j] = '\0';
    return 0; // Added return statement
}

int main() {
    char infix[max], postfix[max];
    printf("Enter the infix expression\n");
    scanf("%s", infix);
    printf("The infix expression is %s\n", infix);
    infixtopostfix(infix, postfix);
    printf("The postfix expression is %s\n", postfix);
    return 0; // Added return statement
}
