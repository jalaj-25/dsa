struct Node *deleteAtEnd(struct Node*head) {
  if(head == NULL) {
    printf("List is empty.");
    return head;
  }
  if(head -> next == NULL} 
    free(head);
  printf("Deleted the node at end.");
  return NULL;
  }
  struct Node *current = head;
  while(current->next->next != NULL} {
    current =  current->next;
  }
  free(current->next);
  current->next = NULL;
  printf("Deleted at end.");
  return head;
}
