#ifndef Stack_LinkedList_H
#define Stack_LinkedList_H
#include "stdbool.h"
struct node {
    int data;
    struct node *next;
};

typedef struct node Node;

/** @brief Push data in Stack
 *
 * @param head double pointer to the Stack head
 * @param val The value push in Stack
 *
 * @return Void.
 */
void push_LinkedList(Node **head, int val);

/** @brief Pop data in Stack
 *
 * @param head double pointer to the Stack head
 *
 * @return Int. top value in Stack
 */
int pop_LinkedList(Node **head);

/** @brief Determine the Stack is empty
 *
 * @param head double pointer to the Stack head
 *
 * @return Bool. the Stack is empty
 */
bool empty_LinkedList(Node *head);

/** @brief Print all data in the Stack, from top to bottom
 *
 * @param head double pointer to the Stack head
 *
 * @return Void.
 */
void print_LinkedList(Node *head);

#endif