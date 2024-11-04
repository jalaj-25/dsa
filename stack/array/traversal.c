#include<stdio.h>
#include<stdlib.h>
#define MAX 1000
typedef struct Stack {
    int top;
    int items[MAX];
} Stack;
void initStack(Stack *s) {
    s->top = -1;
} 
int isFull(Stack *s) {
    return s->top == MAX - 1;
}
int isEmpty(Stack *s) {
    return s->top == -1;
}
void Push(Stack *s, int items) {
    if(isFull(s)) {
        printf("Stack overfloww ho gaya heinnn bro!!!");
        return;
    }
    s->items[++(s->top)] = items;
    printf("Pushed the items in %d stack.\n", items);
}
int pop(Stack *s) {
    if(isEmpty(s)) {
        printf("Stack mein kuch enter to karrooo broooo.\n");
        return -1;
    }
    return s->items[(s->top)--];
}
void display(Stack *s) {
    if(isEmpty(s)) {
        printf("Stack is empty.\n");
        return;
    }
    printf("Elements of the stack are: ");
    for(int i = 0; i <= s->top; i++) {
        printf("%d ", s->items[i]);
    }
    printf("\n");
}
int main() {    
    Stack s; 
    initStack(&s);
    int n, value;
    printf("Enter the number of elements to push onto the stack: ");
    scanf("%d", &n);
    printf("Enter elements of stack: \n");
    for(int i = 0; i < n; i++) {
        printf("Enter %d element of stack: ", i + 1);
        scanf("%d", &value);
        Push(&s, value);
    }
    display(&s);
    if(!isEmpty(&s)) {
        printf("Element poopedis: %d.\n", pop(&s));
        if(!isEmpty(&s)) {
            printf("Eleement that is on the top of element are: %d\n", s.items[s.top]);
        } else {
            printf("You have pushed all the elements.\n");
        }
    }
    display(&s);
    return 0;
}   
