#include "linkedList.h"
#include <stdio.h>
#include <stdlib.h>

void Append(Node **head, int data) {
    Node *newNode = (Node *)malloc(sizeof(Node));

    newNode->data = data;
    newNode->next = NULL;

    if (*head == NULL) {
        *head = newNode;
        return;
    } else {
        Node *temp = *head;
        while (temp->next != NULL) {
            temp = temp->next;
        }
        temp->next = newNode;
    }
}

void PrintList(Node *tmp) {
    if (tmp == NULL)
        return;
    while (tmp != NULL) {
        printf("%d ", tmp->data);
        tmp = tmp->next;
    }
    printf("\n");
}

int Count(Node *tmp) {
    int count = 0;
    while (tmp != NULL) {
        count++;
        tmp = tmp->next;
    }
    return count;
}

void Delete(Node **head, int target) {
    Node *current = *head;
    Node *prev = NULL;

    if (current == NULL)
        return;

    if (current->data == target) {
        *head = current->next;
        free(current);
        return;
    }

    while (current->data != target && current != NULL) {
        prev = current;
        current = current->next;
    }

    if (current != NULL) {
        prev->next = current->next;
        current->next = NULL;
        free(current);
        return;
    }
}

void Insert(Node **head, int data, int index) {
    int currentLength = Count(*head);
    if (currentLength + 1 < index) {
        printf("The string length is only%d Cannot be added", currentLength);
        return;
    }

    Node *newNode = (Node *)malloc(sizeof(Node));
    newNode->data = data;

    // empty list
    if (*head == NULL) {
        newNode->next = NULL;
        *head = newNode;
        return;
    }

    // only one node
    if (index == 1) {
        newNode->next = *head;
        *head = newNode;
        return;
    }

    Node *prev = *head;
    Node *current = *head;
    // find insert index
    int currentIndex = 1;
    while (currentIndex != index) {
        prev = current;
        currentIndex++;
        current = current->next;
    }

    // insert
    newNode->next = prev->next;
    prev->next = newNode;
}

void Reverse(Node **head) {
    Node *prev = NULL;
    Node *current = *head;
    Node *next = NULL;

    while (current != NULL) {
        next = current->next;
        current->next = prev;
        prev = current;
        current = next;
    }
    *head = prev;
}