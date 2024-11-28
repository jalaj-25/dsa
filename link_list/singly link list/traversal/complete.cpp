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

void display(Node* head) {
    while (head != nullptr) {
        cout << head->data << " ";
        head = head->next;
    }
    cout << endl;
}

Node* insertAtBegin(Node* head, int data) {
    Node* newNode = createNode(data);
    newNode->next = head;
    head = newNode;
    cout << "Inserted at beginning.\n";
    return head;
}

Node* insertAtEnd(Node* head, int data) {
    Node* newNode = createNode(data);
    if (head == nullptr) {
        head = newNode;
    } else {
        Node* current = head;
        while (current->next != nullptr) {
            current = current->next;
        }
        current->next = newNode;
    }
    cout << "Node inserted at end.\n";
    return head;
}

Node* insertAtPos(Node* head, int data, int position) {
    if (position < 1) {
        cout << "Invalid position.\n";
        return head;
    }
    if (position == 1) {
        return insertAtBegin(head, data);  
    }
    Node* newNode = createNode(data);
    Node* temp = head;
    for (int i = 1; i < position - 1 && temp != nullptr; ++i) {
        temp = temp->next;
    }

    if (temp == nullptr) {
        cout << "Invalid position.\n";
    } else {
        newNode->next = temp->next;
        temp->next = newNode;
        cout << "Node inserted at position " << position << ".\n";
    }
    return head;
}

Node* deleteAtBegin(Node* head) {
    if (head == nullptr) {
        cout << "List is empty.\n";
        return head;
    }
    Node* temp = head;
    head = head->next;
    delete temp;
    cout << "Deleted at beginning.\n";
    return head;
}

Node* deleteAtEnd(Node* head) {
    if (head == nullptr) {
        cout << "List is empty.\n";
        return head;
    }
    if (head->next == nullptr) { 
        delete head;
        cout << "Node deleted.\n";
        return nullptr;
    }

    Node* current = head;
    while (current->next->next != nullptr) {
        current = current->next;
    }
    delete current->next;
    current->next = nullptr;
    cout << "Node deleted at end.\n";
    return head;
}

int main() {
    Node* head = nullptr;
    int data, choice, position;

    do {
        cout << "Menu:\n";
        cout << "1. Insert At Begin\n2. Insert At End\n3. Insert At Position\n4. Display Node\n5. Delete At Begin\n6. Delete At End\n7. Exit\n";
        cout << "Enter your choice: ";
        cin >> choice;

        switch (choice) {
            case 1:
                cout << "Enter the data: ";
                cin >> data;
                head = insertAtBegin(head, data);
                break;
            case 2:
                cout << "Enter the data to insert: ";
                cin >> data;
                head = insertAtEnd(head, data);
                break;
            case 3:
                cout << "Enter the data to insert: ";
                cin >> data;
                cout << "Enter the position: ";
                cin >> position;
                head = insertAtPos(head, data, position);
                break;
            case 4:
                cout << "The list is: ";
                display(head);
                break;
            case 5:
                head = deleteAtBegin(head);
                break;
            case 6:
                head = deleteAtEnd(head);
                break;
            case 7:
                cout << "Exiting...\n";
                break;
            default:
                cout << "Invalid choice!\n";
                break;
        }
    } while (choice != 7);

    return 0;
}
