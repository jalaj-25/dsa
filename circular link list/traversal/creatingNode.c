struct Node {
    int data;
    struct Node* next;
}; 

struct Node* createNode(int data) {
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    if(newNode == NULL) {
        printf("Memory allocation failed!!");
        exit(1);
    }
    newNode->data = data;
    newNode->next = NULL;
    return newNode;
}