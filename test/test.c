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

    head = clear(head);
    printf("The list has now been cleared: ");
    print_list(head);

    if (head == NULL) {
        printf("head is NULL\n");
    }

    int added_array[3] = {0};
    head = insert(0, 5, head);
    head = add_all(added_array, 3, head);
    printf("Our array with three zeros appended from a list is now: ");
    print_list(head);

    head = append(3, head);
    head = insert_all(4, 3, added_array, head);
    printf("\nAfter appending a 3 and inserting our array again between it, the list is now: ");
    print_list(head);

    free_list(head);
    return 0;
}
