#ifndef Stack_LinkedList_H
#define Stack_LinkedList_H
#include "stdbool.h"
struct node {
    int data;
    struct node *next;
};

typedef struct node Node;

void push_LinkedList(Node **head, int val);

int pop_LinkedList(Node **head);

bool empty_LinkedList(Node *head);

void print_LinkedList(Node *head);

#endif