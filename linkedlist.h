//Header guards
#ifndef LINKEDLIST
#define LINKEDLIST

//Our node template: int data (TODO: generic typing) and a pointer to the next node in the list
typedef struct node {
    int data; 
    struct node *next;
} Node;

//Function prototypes
Node *create_node(int data);
Node *remove_last(Node *head);
int size(Node *head);
void free_list(Node *head);
void print_list(Node *head);
int get_index(int value, Node *head);
Node *append(int data, Node *head);

#endif
