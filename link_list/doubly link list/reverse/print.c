void print(struct Node* head) {
    printf("Reversed doubly link list: ");
    while(head != NULL) {
        printf("%d ", head->data);
        head = head->next;
    }
    printf("\n");
}

void reverse(struct Node** head) {
    struct Node *current = *head, *temp = NULL;
    while(current != NULL) {
        temp = current->prev;
        current->prev = current->next;
        current->next = temp;
        current = current->prev;
    }
    if(temp != NULL) {
        *head = temp->prev;
    }
} 