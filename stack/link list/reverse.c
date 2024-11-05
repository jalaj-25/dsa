#include <stdio.h>
#include <stdlib.h>
struct Node{
    int data;
    struct Node* next;
};

int isEmpty(struct Node* head) {
    return !head;
}

struct Node* newNode(int data) {
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    newNode->data = data;
    newNode->next = NULL;
    newNode->next = NULL;
    return newNode;
}

void push(struct Node** head, int data) {
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    newNode->data = data;
    newNode->next = *head;
    *head = newNode;
}

int pop(struct Node** head) {
    if (*head == NULL) {
        return -1;
    }
    struct  Node* temp = *head;
    *head = (*head)->next;
    int popped = temp->data;
    return popped;
}

void insertAtBottom(struct Node** head,  int data) {
    if(isEmpty(*head)) {
        push(head, data);
    } else {
        int temp = pop(head);
        insertAtBottom(head, data);
        push(head, temp);
    }
}

void reverse(struct Node** head) {
    if(!isEmpty(*head)) {
        int temp = pop(head);
        reverse(head);
        insertAtBottom(head, temp);
    }
}

void print(struct Node* head) {
    while(head !=  NULL) {
        printf("%d ", head->data);
        head = head->next;
    }
    printf("\n");
}


// Example usage
int main() {
    struct Node* head = NULL;
    int n, value;

    printf("Enter the number of elements in the stack: ");
    scanf("%d", &n);

    printf("Enter %d elements:\n", n);
    for (int i = 0; i < n; i++) {
        scanf("%d", &value);
        push(&head, value);
    }

    printf("Original Stack: ");
    print(head);

    reverse(&head);

    printf("Reversed Stack: ");
    print(head);

    return 0;
}
