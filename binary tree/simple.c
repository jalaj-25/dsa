#include <stdio.h>
#include <stdlib.h>

struct Node {
    int data;
    struct Node* left;
    struct Node* right;
};

struct Node* createNode(int data) {
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    newNode->data = data;
    newNode->right = NULL;
    newNode->left = NULL;
    return newNode;
}

//inorder treaversal
void inOrder(struct Node* head) {
    if(head == NULL) {
        return;
    }
    inOrder(head->left);
    printf("%d", head->data);
    inOrder(head->right);
}

//post order traversal 
void postOrder(struct Node* head) {
    if(head == NULL) {
        return;
    }
    postOrder(head->left);
    postOrder(head->right);
    printf("%d", head->data);
}

//pre order traversal
void preOrder(struct Node* head) {
    if(head == NULL) {
        return;
    }
    printf("%d", head->data);
    preOrder(head->left);
    preOrder(head->right);
}

//insert data in node
struct Node* insertData(int data, struct Node* root) {
    if(root== NULL)
        return createNode(data);
    if(data < root->data)
        root->left = insertData(data, root->left);
    else 
        root->right = insertData(data, root->right);    
    return root;
}

int main() {
    struct Node* root = NULL;
    int n, data;
    printf("Enter the number of Nodes in the tree: ");
    scanf("%d", &n);//number of nodes in tree
    printf("Eenter the vlaues that you have to enter in nodes: ");
    for(int i = 0; i < n; i++) {
        scanf("%d", &data);//enter the data
        root = insertData(data, root);
    }
    printf("Inorder traversal of the binary tree: ");
    inOrderTraversal(root); //inorder reversal
    printf("\n");
    printf("Postorder traversal of the binary tree: ");
    postOrderTraversal(root); //postorder reversal
    printf("\n");
    printf("Preorder traversal of the binary tree: ");
    preOrderTraversal(root); //preorder reversal
    return 0;
}