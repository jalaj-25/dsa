// Function to delete a node at the beginning
struct Node* deleteAtBegin(struct Node* head) {
  if (head == NULL) {
    printf("List is empty. Cannot delete from the beginning.\n");
    return head;
  }
  struct Node* temp = head;
  head = head->next;
  free(temp);
  printf("Deleted at the beginning.\n");
  return head;
}
