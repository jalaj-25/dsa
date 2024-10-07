#include <stdio.h>
#include <stdlib.h>

struct Node {
    int data;
    struct Node* next;
};

struct Node* createNode(int data) {
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    if(newNode == NULL) {
        printf("Memory allocation failed!!");
        exit(1);
    }
    newNode->data = data;
    newNode->next = NULL;
    return newNode;
}

void insertAtBeginning(int data, struct Node** head) {
    struct Node* newNode = createNode(data);
    if (*head == NULL) {
        newNode->next = newNode;
    } else {
        struct Node* last = *head;
        while (last->next != *head) {
            last = last->next;
        }
        newNode->next = *head;
        last->next = newNode;
    }
    *head = newNode;
    printf("Node inserted at the beginning!\n");
}

void insertAtEnd(struct Node** head, int data) {
    struct Node* newNode = createNode(data);
    if (*head == NULL) {
        newNode->next = newNode;
        *head = newNode;
    } else {
        struct Node* last = *head;
        while (last->next != *head) {
            last = last->next;
        }
        last->next = newNode;
        newNode->next = *head;
    }
    printf("Node inserted at the end!\n");
}

void insertAtPos(struct Node** head, int data, int pos) {
    if(pos <= 0) { //check if the position is invalid
        printf("Invalid position!\n");
    }
    if(pos == 1) { //if position = 1 call the function
        insertAtBeginning(data, head);
    }
    struct Node* newNode = createNode(data); //newNode craetion
    struct Node* temp = *head; //temp variable creation with assigned value of head
    while(temp->next != *head && --pos > 1) {  //loop for finding the correct position
        temp = temp->next;  //till the move the temp to the next
    }
    // changing the value of newNode and temp 
    newNode->next = temp->next;
    temp->next = newNode;
    printf("Node is inserted.\n");
}

void deleteAtBeginning(struct Node** head) {
    if (*head == NULL) {
        printf("List is empty! Nothing to delete.\n");
        return;
    }
    struct Node* temp = *head;
    if (temp->next == temp) {
        free(temp);
        *head = NULL;
    } else {
        struct Node* last = *head;
        while (last->next != *head) {
            last = last->next;
        }
        *head = temp->next;
        last->next = *head;
        free(temp);
    }
    printf("Node deleted from the beginning!\n");
}

void deleteAtEnd(struct Node** head) {
    if (*head == NULL) {
        printf("List is empty! Unable to delete.\n");
        return;
    }
    struct Node* temp = *head;
    if (temp->next == temp) {
        free(temp);
        *head = NULL;
    } else {
        struct Node* last = *head;
        struct Node* secondLast = NULL;
        while (last->next != *head) {
            secondLast = last;
            last = last->next;
        }
        secondLast->next = *head;
        free(last);
    }
    printf("Node deleted from the end!\n");
}

void deleteAtPos(struct Node** head, int pos) {
    if (*head == NULL) {    // Check if the list is empty
        printf("List is empty! Nothing to delete.\n");
        return;
    }
    struct Node* temp = *head; // Temporary pointer to traverse the list
    if (pos == 1) { // If the position is the first node, call deleteAtBeginning function
        deleteAtBeginning(head);
        return;
    }
    struct Node* prev = NULL;
    int count = 1; // Pointer to store the previous node and a counter to keep track of the position
    while (count < pos && temp->next != *head) { // Traverse to the node just before the target position
        prev = temp;        // Store the current node as the previous node
        temp = temp->next;  // Move to the next node
        count++;            // Increment the position counter
    }
    if (count != pos) { //check for valid poisiton
        printf("Invalid position! No node at this position.\n");
        return;
    }
    prev->next = temp->next;    //updated value which skip the node that has to be deleted.
    printf("Node deleted at position %d.\n", pos);// Print confirmation of deletion
}


void display(struct Node* head) {
    if (head == NULL) {
        printf("List is empty.\n");
        return;
    }
    struct Node* temp = head;
    do {
        printf("%d -> ", temp->data);
        temp = temp->next;
    } while (temp != head);
    printf("(head)\n");
}

int main() {
    struct Node* head = NULL;
    int choice, data, pos;
    
    do {
        printf("\nCircular Linked List Operations\n");
        printf("1. Insert at the beginning\n");
        printf("2. Insert at the end\n");
        printf("3. Insert at the position\n");
        printf("4. Delete at the beginning\n");
        printf("5. Delete at the end\n");
        printf("6. Delete at the position\n");
        printf("7. Display\n");
        printf("8. Exit\n");
        
        printf("Enter your choice: ");
        scanf("%d", &choice);
        
        switch (choice) {
            case 1:
                printf("Enter data to insert at the beginning: ");
                scanf("%d", &data);
                insertAtBeginning(data, &head);
                break;
            case 2:
                printf("Enter data to insert at the end: ");
                scanf("%d", &data);
                insertAtEnd(&head, data);
                break;
            case 3:
                printf("Enter the data you want to insert: ");
                scanf("%d", &data);
                display(head);
                printf("Enter the position you want to add data: ");
                scanf("%d", &pos);
                insertAtPos(&head, data, pos);
                display(head);
                break;
            case 4:
                deleteAtBeginning(&head);
                break;
            case 5:
                deleteAtEnd(&head);
                break;
            case 6:
                printf("Before deletion:\n");
                display(head);
                printf("Enter the position of the data you want to delete: ");
                scanf("%d", &pos);
                printf("\n");
                display(head);
                break;
            case 7:
                display(head);
                break;
            case 8:
                printf("Exiting the program.\n");
                break;
            default:
                printf("Invalid input.\n");
        }
    } while (choice != 7);   
    return 0;
}