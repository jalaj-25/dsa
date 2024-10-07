#include <stdio.h>
#include <stdlib.h>

struct Node {
    int data;
    struct Node* next;
};

struct Node* createNode(int data) {
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    newNode->data = data;
    newNode->next = NULL;
    return newNode;
}

void insertNode(struct Node** head, int data) {
    struct Node* newNode = createNode(data);
    if (*head == NULL) {
        *head = newNode;
    } else {
        struct Node* tail = *head;
        while (tail->next != NULL) {
            tail = tail->next;
        }
        tail->next = newNode;
    }
}

void print(struct Node* head) {
    struct Node* temp = head;
    while (temp != NULL) {
        printf("%d -> ", temp->data);
        temp = temp->next;
    }
    printf("NULL\n");
}

struct Node* reverse(struct Node* head) {
    struct Node* prev = NULL;
    struct Node* current = head;
    struct Node* next = NULL;
    while (current != NULL) {
        next = current->next;
        current->next = prev;
        prev = current;
        current = next;
    }
    return prev;
}

int main() {
    int n, data;
    struct Node* head = NULL;

    printf("Enter the size of linked list: ");
    scanf("%d", &n);

    printf("Enter the data for the linked list: ");
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
