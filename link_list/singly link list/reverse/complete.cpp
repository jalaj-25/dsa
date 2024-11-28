#include <iostream>
using namespace std;

struct Node {
    int data;
    struct Node* next;
};

struct Node* createNode(int data) {
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    newNode->data = data;
    newNode->next = nullptr;
    return newNode;
}

void insertNode(struct Node** head, int data) {
    struct Node* newNode = createNode(data);
    if(*head == NULL) {
        *head = newNode;
    } else {
        struct Node* tail = *head;
        while(tail->next != nullptr) {
            tail = tail->next;
        }
        tail->next = newNode;
    }
}

struct Node* reverse(struct Node * head) {
    struct Node* prev = nullptr;
    struct Node* curr = head;
    struct Node *next = nullptr;
    while(curr != nullptr) {
        next = curr->next;
        curr->next = prev;
        prev = curr;
        curr->next;
    }
    return prev;
} 

void print(struct Node* head) {
    struct Node* temp = head;
    while (temp != NULL) {
        printf("%d -> ", temp->data);
        temp = temp->next;
    }
    printf("NULL\n");
}

int main() {
    int n, data;
    struct Node* head = NULL;

    printf("Enter the size: ");
    scanf("%d", &n);

    printf("Enter the data: ");
    for (int i = 0; i < n; i++) {
        scanf("%d", &data);
        insertNode(&head, data);
    }

    printf("Original linked list: ");
    print(head);

    printf("Reversed linked list: ");
    head = reverse(head);
    print(head);

    return 0;
}
