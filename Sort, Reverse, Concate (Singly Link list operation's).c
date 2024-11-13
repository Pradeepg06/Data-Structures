#include <stdio.h>
#include <stdlib.h>

typedef struct Node
{
    int data;
    struct Node* next;
} Node;

// Function to create a new node
Node* createNode(int data)
{
    Node* newNode = (Node*)malloc(sizeof(Node));
    if (newNode == NULL)
    {
      printf("Memory allocation failed.\n");
      exit(1);
    }
    newNode->data = data;
    newNode->next = NULL;
    return newNode;
}

// Function to insert a new node at the beginning of the linked list
Node *insertAtBeginning(Node *head, int data)
{
     Node *newNode = createNode(data);
     newNode->next = head;
     return newNode;
}

// Concatenation
Node *concatLists(Node *head1, Node *head2)
{
    Node* temp = head1;
    while (temp->next != NULL)
    {
        temp = temp->next;
    }
    temp->next = head2;
    return head1;
}

// Sorting
Node *sortList(Node *head) {
    if (head == NULL) return NULL;

    Node *i = head;
    while (i != NULL)
    {
        Node *j = i->next;
        while (j != NULL)
        {
            if (i->data > j->data)
            {
                int temp = i->data;
                i->data = j->data;
                j->data = temp;
            }
            j = j->next;
        }
        i = i->next;
    }
    return head;
}


// Reversing
Node *reverseList(Node *head)
{
    Node *prev = NULL;
    Node *current = head;
    Node *next = NULL;
    while (current != NULL)
    {
        next = current->next;
        current->next = prev;
        prev = current;
        current = next;
    }
    return prev;
}

// Display

// Function to display a only one list
void displayList2(Node* head)
{
    while (head != NULL)
    {
        printf("%d -> ", head->data);
        head = head->next;
    }
    printf("NULL\n");
}
// Function to display both lists
void displayList1(Node* head1, Node* head2)
{
    printf("List 1: ");
    displayList2(head1);
    printf("List 2: ");
    displayList2(head2);
}


int main() {
    Node *list1 = NULL;
    Node *list2 = NULL;

    // Insert elements into list1
    list1 = insertAtBeginning(list1, 1);
    list1 = insertAtBeginning(list1, 2);
    list1 = insertAtBeginning(list1, 3);

    // Insert elements into list2
    list2 = insertAtBeginning(list2, 4);
    list2 = insertAtBeginning(list2, 5);

    printf("\nAfter Sorting:\n");
    list1 = sortList(list1);
    list2 = sortList(list2);
    displayList1(list1, list2);

    printf("\nAfter concatenation:\n");
    printf("List: ");
    list1 = concatLists(list1, list2);
    displayList2(list1);

    printf("\nAfter reversing:\n");
    printf("List: ");
    list1 = reverseList(list1);
    displayList2(list1);
    return 0;
}
