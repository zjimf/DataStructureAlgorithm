#include "Stack_Arr.h"
#include "Stack_LinkedList.h"
#include <iostream>
using namespace std;
void stackArr();
void stackLinkedList();

int main() {
    cout << "Implement Stack with Array" << endl;
    stackArr();
    cout << "-------------------------------------------------" << endl;
    cout << "Implement Stack with Linked List" << endl;
    stackLinkedList();
}

void stackArr() {
    Stack_Arr s(5);
    cout << "The Stack is " << (s.empty_Arr() ? "empty" : "have data") << endl;

    s.push_Arr(1);
    s.push_Arr(2);
    s.push_Arr(3);
    s.push_Arr(4);
    s.push_Arr(5);
    s.print_Arr();

    cout << "Pop value is:" << s.pop_Arr() << endl;
    s.print_Arr();

    cout << "The Stack is " << (s.empty_Arr() ? "empty" : "have data") << endl;
}

void stackLinkedList() {
    Stack_LinkedList s;
    cout << "The Stack is " << (s.empty_LinkedList() ? "empty" : "have data") << endl;

    s.push_LinkedList(1);
    s.push_LinkedList(2);
    s.push_LinkedList(3);
    s.push_LinkedList(4);
    s.push_LinkedList(5);
    s.print_LinkedList();

    cout << "Pop value is:" << s.pop_LinkedList() << endl;
    s.print_LinkedList();

    cout << "The Stack is " << (s.empty_LinkedList() ? "empty" : "have data") << endl;
}