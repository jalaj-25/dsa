// Function to insert a new node at the end of the list
void insertAtEnd(struct Node** head, int data) {
    // Create a new node with the given data
    struct Node* newNode = createNode(data);
    // If the list is empty, set the new node as the head
    if(*head == NULL) {
        *head = newNode;
        return;
    }
    // Otherwise, traverse the list to find the last node
    struct Node* temp = *head;
    while(temp->next != NULL) {
        temp = temp->next;
    }
    // Update the next and previous pointers of the new node and the last node
    temp->next = newNode;
    newNode->prev = temp;
}
