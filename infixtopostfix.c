#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#define MAX_SIZE 100

char stack[MAX_SIZE];
int top = -1;

void push(char c) {
    if (top == MAX_SIZE - 1) {
        printf("Stack overflow!!\n");
        return;
    }
    stack[++top] = c;  // Increment top before assignment
}

char pop() {
    if (top == -1) {
        printf("\nStack underflow\n");
        return '\0';  // Use '\0' instead of '/0'
    }
    return stack[top--];
}

int precedence(char c) {
    switch (c) {
        case '+':
        case '-':
            return 1;
        case '*':
        case '/':
            return 2;
        case '^':
            return 3;
        default:
            return 0;
    }
}

void display() {
    printf("Stack: ");
    for (int i = 0; i <= top; i++) {
        printf("%c", stack[i]);
    }
    printf("\n");
}

void infixtopostfix(char *infix, char *postfix) {
    int i = 0, j = 0;
    while (infix[i] != '\0') {
        if (isalnum(infix[i])) {
            postfix[j++] = infix[i++];
        } else if (infix[i] == '(') {
            push(infix[i++]);
        } else if (infix[i] == ')') {
            while (top != -1 && stack[top] != '(') {  // Check if stack is not empty
                postfix[j++] = pop();
            }
            pop();  // Pop the '('
            i++;
        } else {
            while (top != -1 && precedence(infix[i]) <= precedence(stack[top])) {
                postfix[j++] = pop();
            }
            push(infix[i++]);
        }
    }
    while (top != -1) {
        postfix[j++] = pop();
    }
    postfix[j] = '\0';  // Null terminate the postfix string
}

int main() {
    char infix[100], postfix[100];
    printf("Enter Infix Expression: ");
    gets(infix);
    infixtopostfix(infix, postfix);
    printf("Postfix Expression: %s\n", postfix);
    return 0;
}
