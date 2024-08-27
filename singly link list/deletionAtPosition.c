struct Node* deleteAtPos(struct Node* head, int position) {
if (head == NULL) {
printf("List is empty. Cannot delete from the specified position.\n");
return head;
}
if (position == 1) {
struct Node* temp = head;
head = head->next;
free(temp);
printf("Deleted at position %d.\n", position);
return head;
}
struct Node* current = head;
int i;
for (i = 1; i < position - 1 && current != NULL; i++) {
current = current->next;
}
if (current == NULL || current->next == NULL) {

printf("Invalid position. Cannot delete from position %d.\n", position);
return head;
}
struct Node* temp = current->next;
current->next = current->next->next;
free(temp);
printf("Deleted at position %d.\n", position);
return head;
}
