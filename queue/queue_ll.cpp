#include <iostream>
using namespace std;

struct Node {
    int data;
    Node* next;
};

void enqueue(Node*& front, Node*& rear, int value);
void dequeue(Node*& front, Node*& rear);
void display(Node* front);

int main() {
    Node* front = nullptr; 
    Node* rear = nullptr;  
    int choice, value;

    cout << "Queue Operations using Linked List:\n";
    cout << "1. Enqueue\n";
    cout << "2. Dequeue\n";
    cout << "3. Display\n";
    cout << "4. Exit\n";

    while (true) {
        cout << "\nEnter your choice: ";
        cin >> choice;

        switch (choice) {
            case 1: 
                cout << "Enter value to enqueue: ";
                cin >> value;
                enqueue(front, rear, value);
                break;
            case 2: 
                dequeue(front, rear);
                break;
            case 3: 
                display(front);
                break;
            case 4: 
                cout << "Exiting...\n";
                return 0;
            default:
                cout << "Invalid choice! Please try again.\n";
        }
    }
}

void enqueue(Node*& front, Node*& rear, int value) {
    Node* newNode = new Node();
    newNode->data = value;
    newNode->next = nullptr;

    if (rear == nullptr) { 
        front = rear = newNode;
    } else {
        rear->next = newNode;
        rear = newNode;
    }
    cout << "Enqueued: " << value << endl;
}

void dequeue(Node*& front, Node*& rear) {
    if (front == nullptr) { 
        cout << "Queue is empty! Cannot dequeue.\n";
        return;
    }

    Node* temp = front;
    cout << "Dequeued: " << front->data << endl;
    front = front->next;

    if (front == nullptr) { 
        rear = nullptr;
    }
}

void display(Node* front) {
    if (front == nullptr) {
        cout << "Queue is empty!\n";
        return;
    }

    cout << "Queue elements: ";
    Node* temp = front;
    while (temp != nullptr) {
        cout << temp->data << " ";
        temp = temp->next;
    }
    cout << endl;
}
