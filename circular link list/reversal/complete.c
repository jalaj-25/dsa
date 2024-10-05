#include <stdio.h>
#include <stdlib.h>
struct Node{ //creating a node
    int data;
    struct Node* next;
};

void createList(struct Node** head, int n) { //crearing a link list
    int i, data;
    struct Node* prevNode = NULL;
    struct Node* newNode = NULL;
    if (n <= 0) {
        printf("Invalid number of nodes.\n");
        return;
    }
    for(i = 0; i < n; i++) {
        newNode = (struct Node*)malloc(sizeof(struct Node));
        printf("Enter the data you want to insert in limnk list: ");
        scnaf("%d", &data);
        newNode->data = data;
        newNode->next = NULL;
        if(*head == NULL) {
            *head = newNode;
        } else {
            prevNode->next = newNode;
        }
        prevNode = newNode;
    }
    prevNode->next = *head;
    printf("Circular link list inserted.\n");
}

void display(struct Node* head) { //displaying the link list
    struct Node* current;
    int n = 1;
    if(head == NULL) {
       printf("List is inserted!!");
       return;
    }
    current = head;
    printf("Data in the list are: \n");
    do {
        printf("%d -> ", current->data);
        current = current->next;
    } while (current != head);
    printf("NULL");
}

void reverseList(struct Node** head) {
    if(*head == NULL) {
        printf("Cannot reverse the empty list\n");
        return;
    }
    struct Node* prev = NULL;
    struct Node* curr = *head;
    struct Node* next = NULL;
    struct Node* last = *head;
    do {
        last = last->next;
    } while(last->next != *head);
    do {
        next = curr->next;
        curr->next = prev;
        prev = curr;
        curr = next;
    } while(curr != *head);
    (*head)->next = prev;
    *head = prev;
    last->next = *head;
}

int main() {
    int n, choice = -1;
    struct node *head = NULL;

    while (choice != 0) {
        printf("--------------------------------------------\n");
        printf("        CIRCULAR LINKED LIST PROGRAM        \n");
        printf("--------------------------------------------\n");
        printf("1. Create List\n");
        printf("2. Display list\n");
        printf("3. Reverse list\n");
        printf("0. Exit\n");
        printf("--------------------------------------------\n");
        printf("Enter your choice : ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                printf("Enter total nodes to create: ");
                scanf("%d", &n);
                createList(&head, n);
                break;
            
            case 2:
                displayList(head);
                break;
            
            case 3:
                reverseList(&head);
                printf("List reversed.\n");
                break;

            case 0:
                printf("Exiting from application.\n");
                exit(0);
                break;

            default:
                printf("Error! Invalid choice. Please choose between 0-3.\n");
        }

        printf("\n\n");
    }

    return 0;
}
