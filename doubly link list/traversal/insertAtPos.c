void insertAtPos(struct Node** head, int data, int position) {
    if(position < 1) {
        printf("Invaluid p[osition.\n");
        return;
    }
    if(position == 1) {
        inserAtBegin(head, data);
        return;
    }
    struct Node *newNode = createNode(data);
    struct Node *temp = *head;
    for(int i = 1; i < position - 1 && temp != NULL; i++) {
        temp =temp->next;
    }
    if(temp == NULL) {
        printf("Position is greater than number of nodes.\n");
        return;
    }
    newNode->next = temp->next;
    newNode->prev = temp;
    if(temp != NULL) {
        temp->next->prev = newNode;
    }
    temp->next = newNode;
}