#include<iostream>
using namespace std;

struct Node{
    int data;
    struct Node* prev;
    struct Node* next;
};

struct Node* createNode(int data) {
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    newNode->data = data;
    newNode->next = nullptr;
    newNode->prev = nullptr;
    return newNode;
}

void insertAtBegin(int data, struct Node** head) {
    struct Node* newNode = createNode(data);
    if(*head == NULL) {
        *head = newNode;
        return;
    }
    newNode->next = *head;
    (*head)->prev = newNode;
    *head = newNode;
}

void insertAtEnd(struct Node** head, int data) {
    struct Node* newNode = createNode(data);
    if(*head == NULL) {
        *head = newNode;
        return;
    }
    struct Node* temp = *head;
    while(temp->next != NULL) {
        temp = temp->next;
    }
    temp->next = newNode;
    newNode->prev = temp;
}

void insertAtPos(struct Node** head, int data, int position) {
    if(position <= 0) {
        cout << "Invalid position!" << endl;
        return;
    }
    struct Node* newNode = createNode(data);
    if(position == 1) {
        insertAtBegin(data, head);
        return;
    }
    struct Node* temp = *head;
    int count = 1;
    while(temp != NULL && count < position - 1) {
        temp = temp->next;
        count++;
    }
    if(temp == NULL) {
        cout << "Position out of range!" << endl;
        return;
    }
    newNode->next = temp->next;
    if(temp->next != NULL) {
        temp->next->prev = newNode;
    }
    temp->next = newNode;
    newNode->prev = temp;
}

void printList(struct Node* head) {
    struct Node* temp = head;
    while(temp != NULL) {
        cout << temp->data << " ";
        temp = temp->next;
    }
    cout << endl;
}

int main() {
    struct Node* head = NULL;
    int choice, data, position;

    while(true) {
        cout << "1. Insert at Beginning\n";
        cout << "2. Insert at End\n";
        cout << "3. Insert at Position\n";
        cout << "4. Print List\n";
        cout << "5. Exit\n";
        cout << "Enter your choice: ";
        cin >> choice;

        switch(choice) {
            case 1:
                cout << "Enter the data to insert at beginning: ";
                cin >> data;
                insertAtBegin(data, &head);
                break;

            case 2:
                cout << "Enter the data to insert at end: ";
                cin >> data;
                insertAtEnd(&head, data);
                break;

            case 3:
                cout << "Enter the data to insert and the position: ";
                cin >> data >> position;
                insertAtPos(&head, data, position);
                break;

            case 4:
                cout << "List: ";
                printList(head);
                break;

            case 5:
                cout << "Exiting..." << endl;
                return 0;

            default:
                cout << "Invalid choice! Please try again." << endl;
        }
    }

    return 0;
}
