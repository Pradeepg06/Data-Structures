#include <stdio.h>
#include <stdlib.h>

// Definition of a node
struct Node {
    int data;
    struct Node* next;
};

// Function to create a new node
struct Node* createNode(int data) {
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    newNode->data = data;
    newNode->next = NULL;
    return newNode;
}

// Function to insert a node at the beginning
void insertAtBeginning(struct Node** head, int data) {
    struct Node* newNode = createNode(data);
    newNode->next = *head;
    *head = newNode;
}

// Function to insert a node at the end
void insertAtEnd(struct Node** head, int data) {
    struct Node* newNode = createNode(data);
    if (*head == NULL) {
        *head = newNode;
        return;
    }
    struct Node* temp = *head;
    while (temp->next != NULL) {
        temp = temp->next;
    }
    temp->next = newNode;
}

// Function to insert a node at a specific position
void insertAtPosition(struct Node** head, int data, int position) {
    if (position == 0) {
        insertAtBeginning(head, data);
        return;
    }
    
    struct Node* newNode = createNode(data);
    struct Node* temp = *head;
    
    for (int i = 0; i < position - 1; i++) {
        if (temp == NULL) {
            printf("The previous node is null. Insertion failed.\n");
            free(newNode);
            return;
        }
        temp = temp->next;
    }
    
    newNode->next = temp->next;
    temp->next = newNode;
}

// Function to display the linked list
void displayList(struct Node* head) {
    struct Node* temp = head;
    while (temp != NULL) {
        printf("%d -> ", temp->data);
        temp = temp->next;
    }
    printf("NULL\n");
}

// Function to create a linked list from user input
void createLinkedList(struct Node** head) {
    int n, data;
    printf("Enter the number of nodes to create: ");
    scanf("%d", &n);

    for (int i = 0; i < n; i++) {
        printf("Enter data for node %d: ", i + 1);
        scanf("%d", &data);
        insertAtEnd(head, data);
    }
}

// Main function
int main() {
    struct Node* head = NULL;

    // Creating the linked list from user input
    createLinkedList(&head);

    printf("\nInitial linked list:\n");
    displayList(head);

    // Inserting nodes
    insertAtBeginning(&head, 5);
    printf("\nAfter inserting 5 at the beginning:\n");
    displayList(head);

    insertAtPosition(&head, 15, 2);
    printf("\nAfter inserting 15 at position 2:\n");
    displayList(head);

    insertAtEnd(&head, 40);
    printf("\nAfter inserting 40 at the end:\n");
    displayList(head);

    return 0;
}
