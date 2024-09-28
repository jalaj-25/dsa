void deleteAtPos(struct Node** head, int pos) {
    if (*head == NULL) {    // Check if the list is empty
        printf("List is empty! Nothing to delete.\n");
        return;
    }
    struct Node* temp = *head; // Temporary pointer to traverse the list
    if (pos == 1) { // If the position is the first node, call deleteAtBeginning function
        deleteAtBeginning(head);
        return;
    }
    struct Node* prev = NULL;
    int count = 1; // Pointer to store the previous node and a counter to keep track of the position
    while (count < pos && temp->next != *head) { // Traverse to the node just before the target position
        prev = temp;        // Store the current node as the previous node
        temp = temp->next;  // Move to the next node
        count++;            // Increment the position counter
    }
    if (count != pos) { //check for valid poisiton
        printf("Invalid position! No node at this position.\n");
        return;
    }
    prev->next = temp->next;    //updated value which skip the node that has to be deleted.
    printf("Node deleted at position %d.\n", pos);// Print confirmation of deletion
}