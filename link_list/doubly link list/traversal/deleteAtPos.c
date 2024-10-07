void deleteAtPosition(struct Node** head, int position) {
    if (*head == NULL) {
        printf("The list is already empty.\n");
        return;
    }
    if (position == 1) {
        deleteAtBeginning(head); 
        return;
    }
    struct Node* temp = *head;
    for (int i = 1; temp != NULL && i < position; i++) {
        temp = temp->next;
    }
    if (temp == NULL) {
        printf("Position is greater than the number of nodes.\n");
        return;
    }
    if (temp->next != NULL) {
        temp->next->prev = temp->prev;
    }
    if (temp->prev != NULL) {
        temp->prev->next = temp->next;
    }
    free(temp);
}