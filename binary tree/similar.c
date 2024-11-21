#include<stdio.h>
#include<stdlib.h>

struct Node {
    int data;
    struct Node* left;
    struct Node* right;
};

struct Node* createNode(int data) {
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    newNode->data = data;
    newNode->left = NULL;
    newNode->right = NULL;
    return newNode;
}

struct Node* insertNode() {
    int data;
    printf("Enter the data: ");
    scanf("%d", &data);

    if (data == -1) {
        return NULL;
    }

    struct Node* newNode = createNode(data);

    printf("Enter left node of %d:\n", data);  
    newNode->left = insertNode();

    printf("Enter right node of %d:\n", data);  
    newNode->right = insertNode(); 

    return  newNode;
}

int isSimilar(struct Node* root1, struct Node* root2) {
    if(root1 == NULL && root2 == NULL) {
        return 1;
    }

    if(root1 == NULL || root2 == NULL) {
        return 0;
    }   

    return (root1->data == root2->data) && isSimilar(root1->left, root2->left) && isSimilar(root1->right, root2->right);
}

int main() {
    printf("craete first binary tree: ");
    struct Node* root1 = insertNode();

    printf("craete second binary tree: ");
    struct Node* root2 = insertNode();

    if(isSimilar(root1, root2)) {
        printf("Both the tree are similar.\n");
    } else {
        printf("Both the tree are not similar.\n");
    }
    return 0;
}
