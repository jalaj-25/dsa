void display(struct Node* head) { //displaying the link list
    struct Node* current;
    int n = 1;
    if(head == NULL) {
       printf("List is inserted!!");
       return;
    }
    current = head;
    printf("Data in the list are: \n");
    do {
        printf("%d -> ", current->data);
        current = current->next;
    } while (current != head);
    printf("NULL");
}