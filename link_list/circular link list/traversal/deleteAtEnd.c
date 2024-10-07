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