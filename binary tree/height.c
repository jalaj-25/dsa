#include <stdio.h>
#include <stdlib.h>

struct Node {
    int data;
    struct Node* left;
    struct Node* right;
};

// Create node
struct Node* createNode(int data) {
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    newNode->data = data;
    newNode->left = NULL;
    newNode->right = NULL;
    return newNode;
}

// inorder traversal
void inOrderTraversal(struct Node* root) {
    if (root == NULL) {
        return;
    }
    inOrderTraversal(root->left);
    printf("%d ", root->data);
    inOrderTraversal(root->right);
}

// postorder traversal
void postOrderTraversal(struct Node* root) {
    if (root == NULL) {
        return;
    }
    postOrderTraversal(root->left);
    postOrderTraversal(root->right);
    printf("%d ", root->data);
}

// preorder traversal
void preOrderTraversal(struct Node* root) {
    if (root == NULL) {
        return;
    }
    printf("%d ", root->data);
    preOrderTraversal(root->left);
    preOrderTraversal(root->right);
}

// calculate height of node
int height(struct Node* root) {
    if (root == NULL) {
        return 0;
    }
    int left_height = height(root->left);
    int right_height = height(root->right);
    return (left_height > right_height ? left_height : right_height) + 1;
}

// Check if the tree is balanced
int isBalanced(struct Node* root) {
    if (root == NULL) {
        return 1;
    }
    int left_height = height(root->left);
    int right_height = height(root->right);

    // recursively check for both subtrees
    if (abs(left_height - right_height) <= 1 && isBalanced(root->left) && isBalanced(root->right)) {
        return 1;
    }
    return 0;
}

// Insert data 
struct Node* insertData(int data, struct Node* root) {
    if (root == NULL)
        return createNode(data);
    if (data < root->data)
        root->left = insertData(data, root->left);
    else 
        root->right = insertData(data, root->right);    
    return root;
}

// Count nodes of the tree
int countNode(struct Node* root) {
    if (root == NULL) {
        return 0;
    }
    return 1 + countNode(root->left) + countNode(root->right);
}

int main() {
    struct Node* root = NULL;
    int n, data;

    printf("Enter the number of Nodes in the tree: ");
    scanf("%d", &n); // Enter number of nodes in the tree
    printf("Enter the values that you have to insert in nodes: ");
    for (int i = 0; i < n; i++) {
        scanf("%d", &data); // Insert data for each node
        root = insertData(data, root);
    }

    printf("Inorder traversal of the binary tree: ");
    inOrderTraversal(root); // Inorder traversal
    printf("\n");

    printf("Postorder traversal of the binary tree: ");
    postOrderTraversal(root); // Postorder traversal
    printf("\n");

    printf("Preorder traversal of the binary tree: ");
    preOrderTraversal(root); // Preorder traversal
    printf("\n");

    int h = height(root), num_node = countNode(root);
    printf("Height of the binary tree: %d\n", h); // Height of the tree
    printf("Number of nodes in the binary tree are: %d\n", num_node); // Number of nodes in the tree

    if (isBalanced(root)) {
        printf("The binary tree is balanced.\n");
    } else {
        printf("The binary tree is not balanced.\n");
    }

    return 0;
}