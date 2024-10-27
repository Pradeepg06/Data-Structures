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

// Function to delete a node at the beginning
void deleteAtBeginning(struct Node** head) {
    if (*head == NULL) {
        printf("List is empty. Deletion failed.\n");
        return;
    }
    struct Node* temp = *head;
    *head = (*head)->next;
    free(temp);
}

// Function to delete a node at the end
void deleteAtEnd(struct Node** head) {
    if (*head == NULL) {
        printf("List is empty. Deletion failed.\n");
        return;
    }
    struct Node* temp = *head;
    if (temp->next == NULL) {
        free(temp);
        *head = NULL;
        return;
    }
    while (temp->next->next != NULL) {
        temp = temp->next;
    }
    free(temp->next);
    temp->next = NULL;
}

// Function to delete a node at a specific position
void deleteAtPosition(struct Node** head, int position) {
    if (*head == NULL) {
        printf("List is empty. Deletion failed.\n");
        return;
    }
    if (position == 0) {
        deleteAtBeginning(head);
        return;
    }

    struct Node* temp = *head;
    for (int i = 0; i < position - 1; i++) {
        if (temp == NULL || temp->next == NULL) {
            printf("Position does not exist. Deletion failed.\n");
            return;
        }
        temp = temp->next;
    }

    struct Node* toDelete = temp->next;
    if (toDelete == NULL) {
        printf("Position does not exist. Deletion failed.\n");
        return;
    }
    temp->next = toDelete->next;
    free(toDelete);
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

    // Deleting nodes
    deleteAtBeginning(&head);
    printf("\nAfter deleting at the beginning:\n");
    displayList(head);

    deleteAtEnd(&head);
    printf("\nAfter deleting at the end:\n");
    displayList(head);

    deleteAtPosition(&head, 1);
    printf("\nAfter deleting at position 1:\n");
    displayList(head);

    return 0;
}
