void insertNode(struct Node** head, int data) {
    struct Node* newNode = createNode(data);
    if (*head == NULL) {
        *head = newNode;
    } else {
        struct Node* tail = *head;
        while (tail->next != NULL) {
            tail = tail->next;
        }
        tail->next = newNode;
    }
}