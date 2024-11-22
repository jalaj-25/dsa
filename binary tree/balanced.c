#include <stdio.h>
#include <stdlib.h>

// Structure for a binary tree node
struct Node {
    int data;
    struct Node* left;
    struct Node* right;
};

// Function to create a new node
struct Node* newNode(int data) {
    struct Node* node = (struct Node*)malloc(sizeof(struct Node));
    node->data = data;
    node->left = NULL;
    node->right = NULL;
    return node;
}

// Function to calculate the height of the tree
int height(struct Node* root) {
    if (root == NULL)
        return 0;
    int leftHeight = height(root->left);
    int rightHeight = height(root->right);
    
    return (leftHeight > rightHeight ? leftHeight : rightHeight) + 1;
}

// Function to check if the tree is balanced
int isBalanced(struct Node* root) {
    if (root == NULL)
        return 1;
    int leftHeight = height(root->left);
    int rightHeight = height(root->right);
    if ((leftHeight - rightHeight <= 1 && leftHeight - rightHeight >= -1) 
        && isBalanced(root->left) && isBalanced(root->right))
        return 1;
    return 0;
}

// Function to input the binary tree nodes
struct Node* insertNode() {
    int data;
    printf("Enter node data (-1 to stop): ");
    scanf("%d", &data);
    if (data == -1) {
        return NULL;
    }    
    struct Node* root = newNode(data);
    printf("Enter left child of %d:\n", data);
    root->left = insertNode();
    printf("Enter right child of %d:\n", data);
    root->right = insertNode();
    return root;
}

int sumOfNodes(struct Node* root) {
    if (root == NULL)
        return 0;
    return root->data + sumOfNodes(root->left) + sumOfNodes(root->right);
}

int main() {
    struct Node* root = NULL;

    printf("Create the binary tree:\n");
    root = insertNode();

    if (isBalanced(root))
        printf("The binary tree is balanced.\n");
    else
        printf("The binary tree is not balanced.\n");

    int sum = sumOfNodes(root);
    printf("Sum of all the nodes of the binary tree is: %d", sum);
    return 0;
}
