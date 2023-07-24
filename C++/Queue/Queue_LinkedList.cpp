#include "Queue_LinkedList.h"
#include <iostream>

using namespace std;

Node::Node(int data) : data(data), next(nullptr){};

QueueLinkedList::QueueLinkedList() : front(nullptr), rear(nullptr){};

void QueueLinkedList::enqueue_LinkedList(int val) {
    Node *newNode = new Node(val);
    if (front == nullptr) {
        front = newNode;
        rear = newNode;
    }
    rear->next = newNode;
    rear = newNode;
}

int QueueLinkedList::dequeue_LinkedList() {
    if (front == nullptr) {
        cout << "Queue empty" << endl;
        return -1;
    }

    Node *temp = front;
    int tempData = temp->data;
    front = front->next;
    temp->next = nullptr;

    delete (temp);
    return tempData;
}

bool QueueLinkedList::empty_LinkedList() {
    return front == nullptr;
}

void QueueLinkedList::print_LinkedList() {
    Node *current = front;
    while (current != nullptr) {
        cout << current->data;
        current = current->next;
        if (current != nullptr)
            cout << "->";
    }
    cout << endl;
}
