#include <stdio.h>
#include <stdlib.h>
#include "linkedlist.h"

//Creates a new node AT the exact position with the provided data.
//Returns a node pointer to link it to other nodes, but it will OVERWRITE any nodes at the position it's invoked.
Node *create_node(int data) {
    Node *new = malloc(sizeof(Node));

    new->data = data;
    new->next = NULL;
    return new;
}

//Inserts a new Node at a provided index, returns NULL if the index doesn't exist
Node *insert(int index, int data, Node *head) {
    Node *tmp = head;

    //Case where an insertion is desired at the head node
    if (index == 0) {
        Node *new_head = create_node(data);
        new_head->next = head;
        //Updates head with our newly set head node
        return new_head;
    }

    if (head == NULL) {
        return NULL;
    }

    //Traversal to the index before the position to unlink
    for (int i=0; i<index-1; i++) {
        //If if we are at the end of the list before reaching the index, we return NULL
        if (tmp->next == NULL) {
            return NULL;
        }
        tmp = tmp->next;
    }
    //Saves the current index Node to relink to the new node, shifting it rightwards
    Node *index_node = tmp->next;
    tmp->next = create_node(data);
    tmp->next->next = index_node;
    return head;
}

//Removes all the nodes after the provided head from the linked list, setting the head node to NULL
Node *clear(Node *head) {
    free_list(head->next);
    head = NULL; 
    return head;
}

//Removes the last node from the linked list
Node *remove_last(Node *head) {
    Node *tmp = head;

    //If head is null, return NULL
    if (head == NULL) {
        return NULL;
    }

    //If we only have a head node, free it
    if (head->next == NULL) {
        free(head);
        return NULL;
    }

    //Traverse to the penultimate node of the linked list
    while (tmp->next->next != NULL) {
        tmp = tmp->next;
    }

    //Once reached, we free the final node and set its reference to null
    free(tmp->next);
    tmp->next = NULL;
    return head;
}

//Traverses through the entire linked list to find its size.
int size(Node *head) {
    int size = 0;

    while (head != NULL) {
        size++;
        head = head->next;
    }
    return size;
}

//Iteratively frees allocated memory by stepping 1, freeing current node, and saving link to the next.
void free_list(Node *head) {
    Node *curr = head;
    Node *tmp = NULL;

    while (curr != NULL) {
        //tmp holds the next node, while curr gets freed and switches to tmp 
        tmp = curr->next;
        free(curr);
        curr = tmp;
    }
}

//Iteratively prints out values stored in each linked node starting from the head.
void print_list(Node *head) {
    while (head != NULL) {
        printf("%d ", head->data);
        head = head->next;
    }
}

//Traverses linked list comparing nodes to find one whose data matches, returning its index.
//If no such node was found, return -1.
int get_index(int value, Node *head) {
    int idx = 0;

    while (head != NULL) {
        if (head->data == value) {
            return idx;
        } 
        idx++;
        head = head->next;
    }
    return -1;
}

//Adds node to the end of the linked list
Node *append(int data, Node *head) {
    //Preserves head pointer
    Node *tmp = head;
    //Replaces our head if it is null
    if (head == NULL) {
        return create_node(data);
    }

    //Traverses until the last node
    while (tmp->next != NULL) {
        tmp = tmp->next;
    }

    //Updates penultimate node with pointer to new node with data, returning the head node
    tmp->next = create_node(data);
    return head;
}

//Appends a list of int values to the end of the linked list
Node *add_all(int values[], size_t length, Node *head) {
    for (size_t i=0; i<length; i++) {
        append(values[i], head);
    }
    return head;
}

//Inserts a list of int values at a specific position. Basically an overriden variant of add_all().
Node *insert_all(int idx, size_t length, int values[], Node *head) {
    for (size_t i=0; i<length; i++) {
        insert(idx+i, values[i], head);
    }
    return head;
}
