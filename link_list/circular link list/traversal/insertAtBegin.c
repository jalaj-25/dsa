void insertAtBeginning(int data, struct Node** head) {
    struct Node* newNode = createNode(data);
    if (*head == NULL) {
        newNode->next = newNode;
    } else {
        struct Node* last = *head;
        while (last->next != *head) {
            last = last->next;
        }
        newNode->next = *head;
        last->next = newNode;
    }
    *head = newNode;
    printf("Node inserted at the beginning!\n");
}