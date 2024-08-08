#ifndef SELSORT_H
#define SELSORT_H

struct node{
    int value;
    struct node* prev;
    struct node* next;
};

// usage prints program usage with the correct command name
//
void usage(char* cmdName);

// is_empty returns true if the passed in list is empty
//
bool is_empty(struct node* head);

// connect will connect the the two nodes passe in.
// Note that connect will not fail on empty nodes
// but will make all possible connections
// Think about this carefully!
//
void connect(struct node* prev, struct node* next);

// unlink will disconnect a node by connecting 
// it's prev and next nodes together.
// Note that unlink will not fail on empty nodes
// Think about this carefully!
//
void unlink(struct node* n);

// new_unconnected_node will create a new node
// with the passed in value but will make no
// attempt to connect it to an existing list.
// This is on purpose for this assignment to
// help you make progress one piece at a time.
//
struct node* new_unconnected_node(int value);

// print_list will print the list values inside
// of square brackets in a forward direction. See
// the examples below
//
void print_list(struct node* head);

// print_list_reversed will print the list values inside
// of square brackets in a backward direction. See
// the examples below
//
void print_list_reversed(struct node* tail);

// find_minimum returns the node that contains
// the minimum value in the list referenced by
// head
// Note that it returns the node, not the value, 
// in addition, it does not unlink the node. Again
// this is on purpose to help you have granular 
// pieces to this puzzle.
//
struct node* find_minimum(struct node* head);

// sort_list returns a sorted list. Note that it
// is destructive to the original list, however,
// it does not allocate new memory, it simply 
// rearranges the nodes. 
//
struct node* sort_list(struct node* head);

// free_list will free all allocated memory for
// the list
//
void free_list(struct node* head);

#endif