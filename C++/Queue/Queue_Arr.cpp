#include "Queue_Arr.h"
#include <iostream>

using namespace std;

QueueArr::QueueArr(int size) : size(size), front(0), rear(0) {
    data = new int[size];
}

void QueueArr::enqueue_Arr(int val) {
    if (rear + 1 % size == front) {
        cout << "queue full" << endl;
        return;
    }
    data[rear] = val;
    rear = rear + 1 % size;
}
int QueueArr::dequeue_Arr() {
    if (front == rear) {
        cout << "queue empty" << endl;
        return -1;
    }
    int temp = data[front];
    front = front + 1 % size;
    return temp;
}
bool QueueArr::empty_Arr() {
    return front == rear;
}
void QueueArr::print_Arr() {
    int current = front;
    while (current != rear) {
        cout << data[current];
        current = current + 1 % size;
        if (current != rear)
            cout << "->";
    }
    cout << endl;
}