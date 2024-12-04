#include <iostream>
using namespace std;

struct Node{
    int data;
    struct Node* next;

    Node(int value) {
        data = value;
        next = nullptr;
    }
};
class LinkedList {
private:
    Node* head;

public:
    LinkedList() {
        head = nullptr;
    }

    void insertAtHead(int value) {
        Node* newNode = new Node(value);
        newNode->next = head;
        head = newNode;
    }

    void insertAtEnd(int value) {
        Node* newNode = new Node(value);
        if (!head) {
            head = newNode;
            return;
        }
        Node* temp = head;
        while (temp->next) {
            temp = temp->next;
        }
        temp->next = newNode;
    }

    void deleteNode(int value) {
        if (!head) return;

        if (head->data == value) {
            Node* temp = head;
            head = head->next;
            return;
        }

        Node* temp = head;
        while (temp->next && temp->next->data != value) {
            temp = temp->next;
        }

        if (temp->next) {
            Node* toDelete = temp->next;
            temp->next = temp->next->next;
            delete toDelete;
        }
    }

    void display() {
        Node* temp = head;
        while (temp) {
            cout << temp->data << " -> ";
            temp = temp->next;
        }
        cout << "nullptr" << endl;
    }
};
int main() {
    LinkedList list;
    int choice, value;

    do {
        cout << "\nMenu:\n";
        cout << "1. Insert at Head\n";
        cout << "2. Insert at Tail\n";
        cout << "3. Delete a Node\n";
        cout << "4. Display List\n";
        cout << "5. Exit\n";
        cout << "Enter your choice: ";
        cin >> choice;

        switch (choice) {
            case 1:
                cout << "Enter value to insert at head: ";
                cin >> value;
                list.insertAtHead(value);
                break;
            case 2:
                cout << "Enter value to insert at tail: ";
                cin >> value;
                list.insertAtEnd(value);
                break;
            case 3:
                cout << "Enter value to delete: ";
                cin >> value;
                list.deleteNode(value);
                break;
            case 4:
                cout << "Linked List: ";
                list.display();
                break;
            case 5:
                cout << "Exiting...\n";
                break;
            default:
                cout << "Invalid choice! Please try again.\n";
        }
    } while (choice != 5);

    return 0;
}