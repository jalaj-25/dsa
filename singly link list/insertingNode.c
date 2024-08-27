
//INSERTING A NODE AT BEGNING
struct  Node *insertAtBegin(struct Node *head, int data) {  
    struct Node*newNode = cretaeNode(data);
    newNode->next = *head;
    printf("Inserted.");
}

//INSERTING A NODE IN END
struct Node *insertAtEnd(struct Node *head, int data) {
    if(newNode == NULL) {
        *head = newNode;
    }
    else{
        struct Node *temp = *head;
        while(temp->next!=NULL) {
            temp = temp->next;
        }
        temp->next = newNode;
    }
    printf("Node inserted.")
}
