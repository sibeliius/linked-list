#include <stdio.h>
#include "../linkedlist.h"

int main() {
    Node *head = create_node(3);
    //Warning: providing a head->next... position already containing a node will OVERWRITE it.
    head->next = create_node(5);
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

    free_list(head);
    return 0;
}
