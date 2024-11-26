#include <iostream>
using namespace std;

struct TreeNode {
    int data;
    TreeNode* left;
    TreeNode* right;

    TreeNode(int val) {
        data = val;
        left = nullptr;
        right = nullptr;
    }
};

TreeNode* createTree() {
    int value;
    cout << "Enter node value: ";
    cin >> value;

    if (value == -1) {
        return nullptr; 
    }

    TreeNode* newNode = new TreeNode(value);
    cout << "Creating left node " << value << endl;
    newNode->left = createTree();
    cout << "Creating right node " << value << endl;
    newNode->right = createTree();

    return newNode;
}

TreeNode* findMin(TreeNode* root) {
    while (root && root->left) {
        root = root->left;
    }
    return root;
}

TreeNode* deleteNode(TreeNode* root, int key) {
    if (root == nullptr) {
        return root;
    }

    if (key < root->data) {
        root->left = deleteNode(root->left, key);
    } else if (key > root->data) {
        root->right = deleteNode(root->right, key);
    } else {
        if (root->left == nullptr) {
            TreeNode* temp = root->right;
            delete root;
            return temp;
        } else if (root->right == nullptr) {
            TreeNode* temp = root->left;
            delete root;
            return temp;
        } else {
            TreeNode* temp = findMin(root->right);
            root->data = temp->data; 
            root->right = deleteNode(root->right, temp->data); 
        }
    }
    return root;
}

void traversal(TreeNode* root) {
    if (root == nullptr) {
        return;
    }

    traversal(root->left);
    cout << root->data << " ";
    traversal(root->right);
}

int main() {
    cout << "Create the binary tree:" << endl;
    TreeNode* root = createTree();

    cout << "Traversal before Deletion: ";
    traversal(root);
    cout << endl;

    int key;
    cout << "Enter the value to delete: ";
    cin >> key;

    root = deleteNode(root, key);

    cout << "Traversal after Deletion: ";
    traversal(root);
    cout << endl;

    return 0;
}
