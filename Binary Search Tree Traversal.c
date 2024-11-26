#include <stdio.h>
#include <stdlib.h>

// Define the structure of a tree node
struct Node 
{
    int data;
    struct Node *left, *right; //pointers for child nodes
};

// Function to create a new node with the given value
struct Node* newnode(int value) 
{
    struct Node* temp = (struct Node*)malloc(sizeof(struct Node));
    temp->data = value;
    temp->left = temp->right = NULL;
    return temp;
}

// Function to insert a new value into the binary search tree
struct Node* insertNode(struct Node* node, int value) 
{
    // If the tree is empty, create a new node
    if (node == NULL) 
    {
        return newnode(value);
    }
    // If the value is smaller, go to the left subtree
    if (value < node->data) 
    {
        node->left = insertNode(node->left, value);
    }
    // If the value is greater, go to the right subtree
    else if (value > node->data) 
    {
        node->right = insertNode(node->right, value);
    }
    return node;
}

// Function for postorder traversal (Left -> Right -> Root)
void postOrder(struct Node* root) 
{
    if(root == NULL)
        return;
        
    else if (root != NULL) 
    {
        postOrder(root->left); // Traverse the left subtree
        postOrder(root->right); // Traverse the right subtree
        printf(" %d ", root->data); // Visit the root node
    }
}

// Function for inorder traversal (Left -> Root -> Right)
void inOrder(struct Node* root) 
{
    if(root == NULL)
        return;
        
    else if (root != NULL) 
    {
        inOrder(root->left); // Traverse the left subtree
        printf(" %d ", root->data); // Visit the root node
        inOrder(root->right); // Traverse the right subtree
    }
}

// Function for preorder traversal (Root -> Left -> Right)
void preOrder(struct Node* root) 
{
    if(root == NULL)
        return;
        
    else if (root != NULL) 
    {
        printf(" %d ", root->data); // Visit the root node
        preOrder(root->left); // Traverse the left subtree
        preOrder(root->right); // Traverse the right subtree
    }
}

int main() 
{
    struct Node* root = NULL;
    int n, value;

    printf("Enter the number of nodes: ");
    scanf("%d", &n);

    printf("Enter the values of the nodes:\n");
    for (int i = 0; i < n; i++) 
    {
        scanf("%d", &value);
        root = insertNode(root, value);
    }

    // Perform and display all bst traversal operations 
    printf("Postorder:\n");
    postOrder(root);
    printf("\n");

    printf("Inorder:\n");
    inOrder(root);
    printf("\n");
    
    printf("Preorder:\n");
    preOrder(root);
    printf("\n");

    return 0;
}