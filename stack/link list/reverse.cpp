#include <iostream>
using namespace std;

struct Node {
    int data;
    Node* next;
};

bool isEmpty(Node* head) {
    return head == nullptr;
}

Node* newNode(int data) {
    Node* newNode = new Node();
    newNode->data = data;
    newNode->next = nullptr;
    return newNode;
}

void push(Node*& head, int data) {
    Node* newNode = new Node();
    newNode->data = data;
    newNode->next = head;
    head = newNode;
}

int pop(Node*& head) {
    if (head == nullptr) {
        return -1;
    }
    Node* temp = head;
    head = head->next;
    int popped = temp->data;
    delete temp;
    return popped;
}

void insertAtBottom(Node*& head, int data) {
    if (isEmpty(head)) {
        push(head, data);
    } else {
        int temp = pop(head);
        insertAtBottom(head, data);
        push(head, temp);
    }
}

void reverse(Node*& head) {
    if (!isEmpty(head)) {
        int temp = pop(head);
        reverse(head);
        insertAtBottom(head, temp);
    }
}

void print(Node* head) {
    while (head != nullptr) {
        cout << head->data << " ";
        head = head->next;
    }
    cout << endl;
}

int main() {
    Node* head = nullptr;
    int n, value;

    cout << "Enter the number of elements in the stack: ";
    cin >> n;

    cout << "Enter " << n << " elements:\n";
    for (int i = 0; i < n; i++) {
        cin >> value;
        push(head, value);
    }

    cout << "Original Stack: ";
    print(head);

    reverse(head);

    cout << "Reversed Stack: ";
    print(head);

    return 0;
}
