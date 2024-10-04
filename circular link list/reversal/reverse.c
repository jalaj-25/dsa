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
