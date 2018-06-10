//#include "linkedlist.h"

//****************************************************************************
//	Linked List Function Definitions
//****************************************************************************

//****	NODE STRUCTURE  ****//
struct Node {
	int data;
	struct Node *next;
};

	struct Node *start = NULL;

// Function to print a float
void printFloat(void *f) {
   printf(" %f", *(float *)f);
}
//****	ADD ELEMENT TO LIST  ****//
void push(struct Node** head_ref, void *new_data, size_t data_size) {
    // Allocate memory for node
    struct Node* new_node = (struct Node*)malloc(sizeof(struct Node));
 
    new_node->data  = malloc(data_size);
    new_node->next = (*head_ref);
 
    // Copy contents of new_data to newly allocated memory.
    // Assumption: char takes 1 byte.
    int i;
    for (i=0; i < data_size; i++)
        *(char *)(new_node->data + i) = *(char *)(new_data + i);
 
    // Change head pointer as new node is added at the beginning
    (*head_ref)    = new_node;
}

 
/* Function to print nodes in a given linked list. fpitr is used
   to access the function to be used for printing current node data.
   Note that different data types need different specifier in printf() */
  
//****	PRINT LIST  ****//
void printList(struct Node *node, void (*fptr)(void *)) {
    while (node != NULL)
    {
        (*fptr)(node->data);
        node = node->next;
    }
}