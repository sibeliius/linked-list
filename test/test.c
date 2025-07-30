#include <stdio.h>
#include "../linkedlist.h"

int main() {
    Node *head = create_node(3);

    head = insert(0, 12, head);
    printf("Inserted 12 at head.\n");

    //Warning: providing a head->next... position already containing a node will OVERWRITE it.
    head->next->next = create_node(5);
    head = append(18, head);
    
    printf("Initial linked list values: ");
    print_list(head);

    printf("\nThe index of value 5 is %d.\n", get_index(5, head));

    head = append(7, head);
    printf("The new size of the linked list is %d.\n", size(head));
    print_list(head);
    
    head = remove_last(head);
    printf("\nThe new linked list with its final element removed is: ");
    print_list(head);

    head = insert(2, 6, head);
    printf("\nThe new linked list with 6 inserted at index 2 is: ");
    print_list(head);
    printf("\n");

    free_list(head);
    return 0;
}
