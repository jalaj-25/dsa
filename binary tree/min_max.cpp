#include <iostream>
#include <climits>
using namespace std;

struct TreeNode {
    int data;
    TreeNode* left;
    TreeNode* right;
    TreeNode(int value) {
        data = value;
        left = nullptr;
        right = nullptr;
    }
};

TreeNode* insertNode(TreeNode* root, int value) {
    if (root == nullptr) {
        return new TreeNode(value);
    }
    if (value < root->data) {
        root->left = insertNode(root->left, value);
    } else {
        root->right = insertNode(root->right, value);
    }
    return root;
}

int findMin(TreeNode* root) {
    if (root == nullptr) {
        return INT_MAX; 
    }
    int leftMin = findMin(root->left);
    int rightMin = findMin(root->right);
    return min(root->data, min(leftMin, rightMin));
}

int findMax(TreeNode* root) {
    if (root == nullptr) {
        return INT_MIN; 
    }
    int leftMax = findMax(root->left);
    int rightMax = findMax(root->right);
    return max(root->data, max(leftMax, rightMax));
}

int main() {
    TreeNode* root = nullptr;
    int n, value;

    cout << "Number of nodes: ";
    cin >> n;

    if (n <= 0) {
        cout << "Tree is empty. No minimum or maximum value." << endl;
        return 0;
    }

    cout << "Node values:\n";
    for (int i = 0; i < n; ++i) {
        cin >> value;
        root = insertNode(root, value);
    }

    int minValue = findMin(root);
    int maxValue = findMax(root);

    cout << "Minimum value: " << minValue << endl;
    cout << "Maximum value: " << maxValue << endl;

    return 0;
}
