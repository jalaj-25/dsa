struct Node{ //creating a node
    int data; //inserting data
    struct Node* next; //address of next ndoe
};

void createList(struct Node** head, int n) { //crearing a link list
    int i, data;
    struct Node* prevNode = NULL; //prev node address
    struct Node* newNode = NULL; //next node address
    if (n <= 0) {
        printf("Invalid number of nodes.\n");
        return;
    }
    for(i = 0; i < n; i++) {
        newNode = (struct Node*)malloc(sizeof(struct Node));  //allocating memory
        printf("Enter the data you want to insert in link list: ");
        scnaf("%d", &data); //enter data for link list
        newNode->data = data;  //inserting data in node
        newNode->next = NULL; //assigning the new address
        if(*head == NULL) {
            *head = newNode; //newnode address
        } else {
            prevNode->next = newNode; //giveing address of new node to prev node
        }
        prevNode = newNode;
    }
    prevNode->next = *head;
    printf("Circular link list inserted.\n");
}