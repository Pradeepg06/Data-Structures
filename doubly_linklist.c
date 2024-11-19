#include <stdio.h>
#include <stdlib.h>

// node creation
struct Node {
  int data;
  struct Node* next;
  struct Node* prev;
};

// insert node at the front
void insertFront(struct Node** head, int data) {
  struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));  // allocate memory for newNode

  newNode->data = data; // assign data to newNode
  newNode->next = (*head); // make newNode as a head
  newNode->prev = NULL; // assign null to prev

  // previous of head (now head is the second node) is newNode
  if ((*head) != NULL) {
    (*head)->prev = newNode;
  }
  (*head) = newNode;  // head points to newNode
}

// delete the first node (helper function for deleteAtPosition)
void deleteAtBeginning(struct Node** head) {
  if (*head == NULL) {
    printf("The list is already empty.\n");
    return;
  }
  struct Node* temp = *head;  // store the current head
  *head = (*head)->next;      // move head to the next node
  if (*head != NULL) {
    (*head)->prev = NULL;     // update the prev of new head to NULL
  }
  free(temp);                 // free the old head
}

// Function to delete a node from a specified position
void deleteAtPosition(struct Node** head, int position) 
{
  if (*head == NULL) 
  {
    printf("The list is already empty.\n");
    return;
  }

  struct Node* temp = *head;

  // If the position is the first node
  if (position == 1) 
  {
    deleteAtBeginning(head);
    return;
  }

  // Traverse to the node at the given position
  for (int i = 1; temp != NULL && i < position; i++) 
  {
    temp = temp->next;
  }

  // If the position is invalid
  if (temp == NULL) 
  {
    printf("Position is greater than the number of nodes.\n");
    return;
  }

  // Update pointers and free the node
  if (temp->next != NULL) 
  {
    temp->next->prev = temp->prev;
  }
  if (temp->prev != NULL) 
  {
    temp->prev->next = temp->next;
  }
  free(temp);
}

// print the doubly linked list
void displayList(struct Node* node) 
{
  while (node != NULL) 
  {
    printf("%d->", node->data);
    node = node->next;
  }
  printf("NULL\n");
}

int main() {
  // initialize an empty node
  struct Node* head = NULL;
  
  printf("\nDoubly_linklist :- \n");
  
  // insertion of nodes at Beginning / Front
  printf("\nInsertion of Nodes at front: \n");
  insertFront(&head, 10);
  insertFront(&head, 20);
  insertFront(&head, 30);
  insertFront(&head, 40);
  insertFront(&head, 50);
  insertFront(&head, 60);
  displayList(head);

  // delete the node at specified position
  printf("\nDeletion of Nodes at position 4 is: \n");
  deleteAtPosition(&head, 4);
  displayList(head);

  return 0;
}