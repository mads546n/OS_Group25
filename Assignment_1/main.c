
/* You are not allowed to use <stdio.h> */
#include "io.h"


/**
 * @name  main
 * @brief This function is the entry point to your program
 * @return 0 for success, anything else for failure
 *
 *
 * Then it has a place for you to implementation the command 
 * interpreter as  specified in the handout.
 */

/* Node structure to construct a double linked-list */
typedef struct Node {
    int value;
    struct Node* next;
    struct Node* prev;
} Node;

/* Function that can add a new element to the end of the linked-list */
void add_element_to_collection(Node** head, Node** tail, int value) {
    // Allocate memory
    Node* new_node = (Node*)malloc(sizeof(Node));
    
    if (!new_node) {
        // Memory allocation error handling
        return;
    }
    new_node->value = value;
    new_node->next = next;
    new_node->prev = prev;

    // Add the node to the end of the list
    if (*tail) {
        (*tail)-> new_node;
    } else {
        // If the list turns out to be empty, then we add the node as the head of the list
        *head = new_node;
    }
    *tail = new_node;
}

/* Function to remove the most recently added element from the linked list */
void remove_last_added_element(Node** head, Node** tail) {
    // If the list is empty, there is nothing to remove
    if (!*tail) {
        return;
    }

    Node* to_remove = *tail;
    *tail = to_remove->prev;

    if (*tail) {
        (*tail)->next = NULL;
    } else {
        // If the list has become empty, then the head should also be NULL
        *head = NULL;
    }

    // Free allocated memory
    free(to_remove);
}

/* Function meant to print the entire collection with appropriate separators and commas */
void print_collection(Node* head) {
    if (!head) {
        // Call to functions from io.h
        write_char(';');
        write_char('\n');
        return;
    }

    Node* current = head;
    while (current) {
        // Print each element of the collection followed by a comma in front if it's not the last element
        write_int(current->value);
        // If current is followed up by another element
        if (current->next) {
            write_char(',');
            write_char(' ');
        }
        current = current->next;
    }
    // If current is last
    write_char(';');
    write_char()
}

int main() {
    char *prompt = "Enter a command: a, b, or c\n";
    write_string(prompt);

    char c;

    int counter = 0; // Initialize counter as 1

    Node* head = NULL; // Head of collection in the linked-list
    Node* tail = NULL; // Tail of collection in the linked-list

    // Loop to process commands from stdin and assign valid functions
    while (1) {
        c = read_char();

        if (c == 'a') {
            add_element_to_collection(&head, &tail, counter);
            counter++;
        } else if (c == 'b') {
            counter++;
        } else if (c == 'c') {
            remove_last_added_element(&head, &tail);
            counter++;
        } else {
            // If not a valid input, break
            break;
        }
    }

    // Call to function for printing the collection as a list separated by commas
    print_collection(head);

    // Free allocated memory for the linked list
    Node* current = head;
    while (current) {
        Node* next = current->next;
        free(current);
        current = next;
    } 


/*
    // Loop to read input
    do
    {
        c = read_char();

        if (c == 'a' || c == 'b' || c == 'c') 
        {
            write_char(c); // Echoes input
        } else {
            write_string(" Invalid input. \n");
        }
        
    } while (c != 'q');

    */
    
  /*-----------------------------------------------------------------
   *TODO:  You need to implement the command line driver here as
   *       specified in the assignment handout.
   *
   * The following pseudo code describes what you need to do
   *  
   *  Declare the counter and the collection structure variables
   *
   *
   *  In a loop
   *    1) Read a command from standard in using read_char function
   *    2) If the command is not 'a', 'b', 'c': then break the loop
   *    3) Process the command as specified in the handout
   *  End loop
   *
   *  Print your collection of elements as specified in the handout
   *    as a comma delimited series of integers
   *-----------------------------------------------------------------*/
    char *exitMessage = "Program ends. Farewell\n";
    write_string(exitMessage);
  return 0;
}
