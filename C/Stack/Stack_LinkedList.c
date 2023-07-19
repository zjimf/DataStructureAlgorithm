#include "Stack_LinkedList.h"
#include "stdbool.h"
#include "stdio.h"
#include "stdlib.h"

void push_LinkedList(Node **head, int val) {
    Node *newNode = (Node *)malloc(sizeof(Node));
    newNode->data = val;
    newNode->next = *head;
    *head = newNode;
}

int pop_LinkedList(Node **head) {
    Node *current = *head;
    int temp = current->data;
    *head = current->next;

    current->next = NULL;
    free(current);
    return temp;
}

bool empty_LinkedList(Node *head) {
    return head == NULL;
}

void print_LinkedList(Node *head) {
    Node *current = head;
    while (current != NULL) {
        (current == head) ? printf("| %d | Top\n", current->data) : printf("| %d |\n", current->data);
        current = current->next;
    }
}