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