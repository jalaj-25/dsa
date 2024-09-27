void insertAtPos(struct Node** head, int data, int pos) {
    if(pos <= 0) { //check if the position is invalid
        printf("Invalid position!\n");
    }
    if(pos == 1) { //if position = 1 call the function
        insertAtBeginning(data, head);
    }
    struct Node* newNode = createNode(data); //newNode craetion
    struct Node* temp = *head; //temp variable creation with assigned value of head
    while(temp->next != *head && --pos > 1) {  //loop for finding the correct position
        temp = temp->next;  //till the move the temp to the next
    }
    // changing the value of newNode and temp 
    newNode->next = temp->next;
    temp->next = newNode;
    printf("Node is inserted.\n");
}