#include <iostream>
using namespace std;

struct Node {
    int data;
    Node* left;
    Node* right;
    
    Node(int value) {
        data = value;
        left = right = nullptr;
    }
};

Node* insert(Node* root, int value) {
    if (root == nullptr) {
        return new Node(value);
    }
    if (value < root->data) {
        root->left = insert(root->left, value);
    } else {
        root->right = insert(root->right, value);
    }
    
    return root;
}

bool search(Node* root, int value) {
    if (root == nullptr) {
        return false;
    }
    if (root->data == value) {
        return true;
    }
    if (value > root->data) {
        return search(root->right, value);
    }
    return search(root->left, value);
}

int main() {
    Node* root = nullptr;
    int n, value, searchValue;
    cout << "Enter the number of nodes to insert: ";
    cin >> n;
    cout << "Enter the values to insert into the binary search tree:\n";
    for (int i = 0; i < n; i++) {
        cin >> value;
        root = insert(root, value);
    }
    cout << "Enter the value to search for: ";
    cin >> searchValue;
    if (search(root, searchValue)) {
        cout << "Node with value " << searchValue << " is found in the tree.\n";
    } else {
        cout << "Node with value " << searchValue << " is not found in the tree.\n";
    }

    return 0;
}
