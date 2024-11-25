#include <iostream>
using namespace std;

struct Node { //creating a node
    int data;
    Node* left;
    Node* right;

    Node(int val) { //giving value to the data
        data = val;
        left = nullptr;
        right = nullptr;
    }
};

struct Node* create() { //creating a node
    int value;
    cout << "Enter value: "; //input the data
    cin >> value;

    if (value == -1) {
        return nullptr; 
    }

    struct Node* newNode = new struct Node(value);
    cout << "Left node " << value << endl; //left node
    newNode->left = create();
    cout << "Right node " << value << endl; //right node
    newNode->right = create();

    return newNode;
}

void mirror(struct Node* root) {
    if (root == nullptr) {
        return; 
    }

    Node* temp = root->left; //temp store the left node
    root->left = root->right; //assigining the value of right node to left node 
    root->right = temp; //assigning the right node value to temp

    mirror(root->left); //calling the function for left node
    mirror(root->right); //calling the function for right node
}

void inorderTraversal(struct Node* root) {
    if (root == nullptr) {
        return;
    }

    inorderTraversal(root->left);
    cout << root->data << " ";
    inorderTraversal(root->right);
}

int main() {
    cout << "Create the binary tree:" << endl;
    Node* root = create();

    cout << "Inorder Traversal before: ";
    inorderTraversal(root);
    cout << endl;

    mirror(root);

    cout << "Inorder Traversal after: ";
    inorderTraversal(root);
    cout << endl;

    return 0;
}
