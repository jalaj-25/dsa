#include <iostream>
using namespace std;

struct Node {
    int data;
    Node* next;
};

Node* createNode(int data) {
    Node* newNode = new Node();
    newNode->data = data;
    newNode->next = nullptr;
    return newNode;
}

void push(Node** top, int data) {
    Node* newNode = createNode(data);
    newNode->next = *top;
    *top = newNode;
    cout << data << " is pushed to stack." << endl;
}

int pop(Node** top) {
    if(*top == nullptr) {
        cout << "Underflow!!" << endl;
        return -1;
    }
    Node* temp = *top;
    int poped = temp->data;
    *top = (*top)->next;
    delete temp;
    return poped;
}

void display(Node* top) {
    if(top == nullptr) {
        cout << "Empty!!" << endl;
        return;
    }
    Node* temp = top;
    cout << "Elements are: ";
    while(temp != nullptr) {
        cout << temp->data << " ";
        temp = temp->next;
    }
    cout << endl;
}

int main() {
    Node* stack = nullptr;
    int choice, data;
    while(true) {
        cout << "Operations of stack are: " << endl;
        cout << "1. Push." << endl;
        cout << "2. Pop." << endl;
        cout << "3. Display." << endl;
        cout << "4. Exit." << endl;
        cin >> choice;
        
        switch(choice) {
            case 1:
                cout << "Enter the element: ";
                cin >> data;
                push(&stack, data);
                break;
            case 2:
                data = pop(&stack);
                if (data != -1) {
                    cout << data << " popped from stack" << endl;
                }
                break;
            case 3:
                display(stack);
                break;
            case 4:
                while(stack != nullptr) {
                    pop(&stack);
                }
                cout << "Exiting" << endl;
                return 0;
            default:
                cout << "Invalid choice" << endl;
        }
    }
    return 0;
}
