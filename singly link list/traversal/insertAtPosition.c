struct Node *insertAtPos(int position, int data, struct Node *head){
    if(newNode == NULL) {
        printf("Error");
    }
    if(position == 1) {
        insetAtBegin(data, *head);
    }
    else {
        struct Node *newNode= createNode(data);
        struct Node *temp = *head;
        for(int i = 1; i < position - 1 && temp != NULL; i++)
        {
            temp = temp->next;
        };
        if(temp == NULL) {
            printf("Invalid position.");
        }
        else {
            newNode->next = temp->next;
            temp->next = newNode;
            printf("Node is inserted.\n")
        }
    }
};
