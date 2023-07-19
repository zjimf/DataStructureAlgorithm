#include "Stack_Arr.h"
#include "Stack_LinkedList.h"
#include <stdio.h>
#include <stdlib.h>
void stack_Arr();
void stack_LinkedList();

int main() {
    printf("Implement Stack with Array\n");
    stack_Arr();
    printf("-------------------------------------------------\n");
    printf("Implement Stack with LinkedList\n");
    stack_LinkedList();
}

void stack_Arr() {
    Stack_Arr s = {{0}, 0};
    s.top = 0;
    printf("The Stack is %s\n", empty_Arr(&s) ? "empty" : "have data");
    push_Arr(&s, 1);
    push_Arr(&s, 2);
    push_Arr(&s, 3);
    push_Arr(&s, 4);
    push_Arr(&s, 5);
    print_Arr(&s);
    printf("The Stack is %s\n", empty_Arr(&s) ? "empty" : "have data");
    printf("Pop value is:%d\n", pop_Arr(&s));
    print_Arr(&s);
}

void stack_LinkedList() {
    Node *head = NULL;

    printf("The Stack is %s\n", empty_LinkedList(head) ? "empty" : "have data");
    push_LinkedList(&head, 1);
    push_LinkedList(&head, 2);
    push_LinkedList(&head, 3);
    push_LinkedList(&head, 4);
    push_LinkedList(&head, 5);
    print_LinkedList(head);
    printf("The Stack is %s\n", empty_LinkedList(head) ? "empty" : "have data");
    printf("Pop value is:%d\n", pop_LinkedList(&head));
    print_LinkedList(head);
}