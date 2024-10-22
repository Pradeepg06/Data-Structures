#include <stdio.h>
#include <stdlib.h>
#define SIZE 4

int top = -1, inp_array[SIZE];

void push();
void pop();
void display();

int main() {
    int choice;
    while (1) {
        printf("\n\nPerform operations on the stack: ");
        printf("\n1.Push the element(s)\n2.Pop the element\n3.Diplay\n4.Exit");
        printf("\n\nEnter the choice: ");
        scanf("%d", &choice);

        switch (choice) {
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
            printf("\nInvalid choice!!");
        }
    }
}

void push() {
    int x;

    if (top == SIZE - 1 ){
        printf("\nOverflow!!");
        return;
    }
    else
    {
    printf("Enter element to be added on to the stack: ");
    for (int i = 0; i < SIZE; i++) 
    {
        scanf("%d", &x);
        top++;
        inp_array[top] = x;
    }
    }
}

void pop() {
    if (top == -1) {
        printf("\nUnderflow!!");
    } else {
        printf("\nPopped element: %d", inp_array[top]);
        top--;
    }
}

void display() {
    if (top == -1) {
        printf("\nUnderflow!!");
    } else {
        printf("\nElements present in the stack: \n");
        for (int i = top; i >= 0; --i)
            printf("%d\n", inp_array[i]);
    }
}
