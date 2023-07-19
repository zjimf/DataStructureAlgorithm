#include "dbLinkedList.h"
#include <stdio.h>
#include <stdlib.h>

void Append(Node **head, int data) {
    Node *newNode = (Node *)malloc(sizeof(Node));
    newNode->data = data;
    newNode->next = NULL;

    // null list
    if (*head == NULL) {
        newNode->prev = NULL;
        *head = newNode;
        return;
    }

    Node *current = *head;
    while (current->next != NULL)
        current = current->next;
    current->next = newNode;
    newNode->prev = current;
}

void PrintList(Node *tmp) {
    if (tmp == NULL) {
        printf("empty");
        return;
    }
    Node *current = tmp;
    while (current) {
        printf("%d ", current->data);
        current = current->next;
    }
    printf("\n");
}

int Count(Node *tmp) {
    Node *current = tmp;
    int cnt = 0;
    while (current != NULL) {
        cnt++;
        current = current->next;
    }
    return cnt;
}

void Delete(Node **head, int target) {
    Node *current = *head;

    if (current->data == target) {
        *head = current->next;
        current->next->prev = NULL;
        current->next = NULL;
        free(current);
        return;
    }

    while (current->data != target)
        current = current->next;

    current->prev->next = current->next;
    current->next->prev = current->prev;
    current->next = NULL;
    current->prev = NULL;

    free(current);
}

void Insert(Node **head, int data, int index) {
    int currentLength = Count(*head);
    if (currentLength + 1 < index) {
        printf("The string length is only%d Cannot be added", currentLength);
        return;
    }

    Node *newNode = (Node *)malloc(sizeof(Node));
    newNode->data = data;

    if (*head == NULL) {
        newNode->next = NULL;
        newNode->prev = NULL;
        *head = newNode;
        return;
    }

    // if adding head
    if (index == 1) {
        newNode->next = *head;
        newNode->prev = NULL;
        *head = newNode;
        return;
    }

    Node *current = *head;
    int currentIndex = 1;
    while (currentIndex != index) {
        current = current->next;
        currentIndex++;
    }
    newNode->prev = current->prev;
    newNode->next = current;
    current->prev->next = newNode;
    current->prev = newNode;
}
