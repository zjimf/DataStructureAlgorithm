#include "Stack_LinkedList.h"
#include <iostream>

using namespace std;
Node::Node() : data(0), next(nullptr){};
Node::Node(int data) : data(data), next(nullptr){};

Stack_LinkedList ::Stack_LinkedList() : top(nullptr){};

void Stack_LinkedList::push_LinkedList(int val) {
    Node *newNode = new Node(val);
    newNode->next = top;
    top = newNode;
}

int Stack_LinkedList::pop_LinkedList() {
    int temp;
    Node *current = top;
    top = top->next;
    current->next = nullptr;
    temp = current->data;
    delete (current);
    return temp;
}

bool Stack_LinkedList::empty_LinkedList() {
    return top == nullptr;
}
void Stack_LinkedList::print_LinkedList() {
    Node *current = top;

    while (current) {
        cout << "| " << current->data << " |" << endl;
        current = current->next;
    }
}