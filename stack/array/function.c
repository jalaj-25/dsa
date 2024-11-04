// in this file we will see all the function that we are using for making stack ussing link list. 

// initializing a empty stack
void initStack(Stack *s) {
    s->top = -1;
} 

// giving condition to stack to check if it is full or not
int isFull(Stack *s) {
    return s->top == MAX - 1;
}

// giving condition to stack to check if it is empty or not
int isEmpty(Stack *s) {
    return s->top == -1;
}

// pushing certain values in stack
void Push(Stack *s, int items) {
    if(isFull(s)) {
        printf("Stack overfloww ho gaya heinnn bro!!!");
        return;
    }
    s->items[++(s->top)] = items;
    printf("Pushed the items in %d stack.\n", items);
}

// removing the entered value in the format of "FILO"
int pop(Stack *s) {
    if(isEmpty(s)) {
        printf("Stack mein kuch enter to karrooo broooo.\n");
        return -1;
    }
    return s->items[(s->top)--];
}