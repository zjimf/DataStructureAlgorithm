#include "Queue_Arr.h"
#include "Queue_LinkedList.h"
#include <iostream>
using namespace std;
void queueArr();
void queueLinkedList();

int main() {
    cout << "Implement Queue with Array" << endl;
    queueArr();
    cout << "-------------------------------------------------" << endl;
    cout << "Implement Queue with Linked List" << endl;
    queueLinkedList();
}

void queueArr() {
    QueueArr q(5);

    cout << "The Queue is "
         << (q.empty_Arr()
                 ? "empty"
                 : "have data")
         << endl;

    q.enqueue_Arr(1);
    q.enqueue_Arr(2);
    q.enqueue_Arr(3);
    q.enqueue_Arr(4);
    q.enqueue_Arr(5);
    q.print_Arr();

    cout << "dequeue value is:"
         << q.dequeue_Arr() << endl;
    cout << "dequeue value is:"
         << q.dequeue_Arr() << endl;
    cout << "dequeue value is:"
         << q.dequeue_Arr() << endl;
    cout << "dequeue value is:"
         << q.dequeue_Arr() << endl;
    cout << "dequeue value is:"
         << q.dequeue_Arr() << endl;
    q.print_Arr();

    cout << "The Queue is "
         << (q.empty_Arr()
                 ? "empty"
                 : "have data")
         << endl;
}

void queueLinkedList() {
    QueueLinkedList q;

    cout << "The Queue is "
         << (q.empty_LinkedList()
                 ? "empty"
                 : "have data")
         << endl;

    q.enqueue_LinkedList(1);
    q.enqueue_LinkedList(2);
    q.enqueue_LinkedList(3);
    q.enqueue_LinkedList(4);
    q.enqueue_LinkedList(5);
    q.print_LinkedList();

    cout << "dequeue value is:"
         << q.dequeue_LinkedList() << endl;
    cout << "dequeue value is:"
         << q.dequeue_LinkedList() << endl;
    cout << "dequeue value is:"
         << q.dequeue_LinkedList() << endl;
    cout << "dequeue value is:"
         << q.dequeue_LinkedList() << endl;
    cout << "dequeue value is:"
         << q.dequeue_LinkedList() << endl;
    q.print_LinkedList();

    cout << "The Queue is "
         << (q.empty_LinkedList()
                 ? "empty"
                 : "have data")
         << endl;
}