#include "linkedList.h"
#include <iostream>
using namespace std;

Node::Node() : data(0), next(nullptr){};
Node::Node(int data) : data(data), next(nullptr){};

LinkedList::LinkedList() : head(nullptr){};

void LinkedList::Append(int data) {
    Node *newNode = new Node(data);

    if (head == nullptr) {
        head = newNode;
        return;
    }

    Node *current = head;
    while (current->next != nullptr) {
        current = current->next;
    }

    current->next = newNode;
}

void LinkedList::PrintList() {
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

int LinkedList::Count() {
    int cnt = 0;
    Node *current = head;
    while (current != nullptr) {
        cnt++;
        current = current->next;
    }
    return cnt;
}

void LinkedList::Delete(int target) {
    Node *current = head;

    if (current->data == target) {
        head = current->next;
        delete (current);
        return;
    }

    while (current->next->data != target && current->next != nullptr)
        current = current->next;

    if (current->next->data == target) {
        Node *tmp = current->next;
        current->next = tmp->next;
        tmp->next = nullptr;
        delete (tmp);
    }
}

void LinkedList::Insert(int data, int index) {
    int currentLen = Count();
    if (currentLen + 1 < index) {
        printf("The string length is only%d Cannot be added", currentLen);
    }

    Node *newNode = new Node(data);
    if (head == nullptr)
        head = newNode;

    Node *current = head;
    int currentIndex = 1;
    while (currentIndex != index - 1) {
        currentIndex++;
        current = current->next;
    }
    newNode->next = current->next;
    current->next = newNode;
}

void LinkedList::Reverse() {
    Node *prev = nullptr;
    Node *current = head;
    Node *next = nullptr;

    while (current != nullptr) {
        next = current->next;
        current->next = prev;
        prev = current;
        current = next;
    }
    head = prev;
}