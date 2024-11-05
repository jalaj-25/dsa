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

void push(struct Node** top, int data)  {
    struct Node* newNode = createNode(data);
    newNode->next = *top;
    *top = newNode;
    printf("%d is pushed to stack.\n", data);
}

int pop(struct Node** top) {
    if(*top == NULL) {
        printf("Stack underflow!!");
        return -1;
    }
    struct Node* temp = *top;
    int poppedData = temp->data;
    *top = (*top)->next;
    return poppedData;
}

void display(struct Node* top) {
    if(top == NULL) {
        printf("Stack is empty!!");
        return;
    }
    struct Node* temp = top;
    printf("Elements of stack are: ");
    while(temp != NULL) {
        printf("%d ", temp->data);
        temp = temp->next;
    }
}

int main() {
    struct Node* stack = NULL;
    int choice, data;
    while(1) {
        printf("Operations of stack are: \n");
        printf("1. Push.\n2. Pop.\n3. Display.\n4. Exit.\n");
        scanf("%d" , &choice);  
        switch(choice) {
            case 1:
                printf("Enter the element you want to push in stack: ");
                scanf("%d", &data);
                push(&stack, data);
                break;
            case 2:
                data = pop(&stack);
                if (data != -1) {
                    printf("%d popped from stack\n", data);
                }
                break;
            case 3:
                display(stack);
                printf("\n");
                break;
            case 4:
                while(stack != NULL) {
                    pop(&stack);
                }
                printf("Exiting!!\n");
                break;
            default:
                printf("Invalid  choice!!");
                // break;
        }
    }
    return 0;
}