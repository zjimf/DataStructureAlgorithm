#ifndef dbLinkedList_h
#define dbLinkedList_h

struct node {
    int data;
    struct node *prev;
    struct node *next;
};
typedef struct node Node;

void Append(Node **head, int data);

void PrintList(Node *head);

int Count(Node *head);

void Delete(Node **head, int target);

void Insert(Node **head, int data, int index);

#endif