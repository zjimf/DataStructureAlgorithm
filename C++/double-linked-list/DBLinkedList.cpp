#include "DBLinkedList.h"
#include <iostream>
using namespace std;

Node::Node() : data(0), prev(nullptr), next(nullptr){};
Node::Node(int data) : data(data), prev(nullptr), next(nullptr){};

DBLinkedList::DBLinkedList() : head(nullptr){};

void DBLinkedList::Append(int data) {
    Node *newNode = new Node(data);
    newNode->next = nullptr;

    if (head == nullptr) {
        head = newNode;
        return;
    }

    Node *current = head;
    while (current->next != nullptr) {
        current = current->next;
    }
    current->next = newNode;
    newNode->prev = current;
}

void DBLinkedList::PrintList() {
    if (head == nullptr) {
        cout << "empty" << endl;
        return;
    }
    Node *current = head;
    while (current != nullptr) {
        cout << current->data << " ";
        current = current->next;
    }
    cout << endl;
}

int DBLinkedList::Count() {
    int cnt = 0;
    if (head == nullptr)
        return 0;
    Node *current = head;
    while (current != nullptr) {
        cnt++;
        current = current->next;
    }
    return cnt;
}

void DBLinkedList::Delete(int target) {
    Node *current = head;
    if (current == nullptr)
        return;

    if (current->data == target) {
        head = current->next;
        free(current);
        return;
    }

    while (current != nullptr && current->data != target)
        current = current->next;

    if (current->data == target) {
        current->prev->next = current->next;
        current->next->prev = current->prev;

        free(current);
        return;
    }
}

void DBLinkedList::Insert(int data, int index) {
    int currentLength = Count();
    if (currentLength + 1 < index) {
        printf("The string length is only%d Cannot be added", currentLength);
        return;
    }

    Node *newNode = new Node(data);
    newNode->data = data;

    if (head == nullptr) {
        newNode->prev = nullptr;
        newNode->next = nullptr;
        head = newNode;
        return;
    }

    if (index == 1) {
        newNode->prev = nullptr;
        newNode->next = head;
        head->prev = newNode;
        head = newNode;
        return;
    }

    Node *current = head;
    int currentIndex = 1;
    while (currentIndex != index) {
        currentIndex++;
        current = current->next;
    }

    newNode->prev = current->prev;
    newNode->next = current;
    current->prev->next = newNode;
    current->prev = newNode;
}