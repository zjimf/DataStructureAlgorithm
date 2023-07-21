#include "Stack_Arr.h"
#include <iostream>

using namespace std;

Stack_Arr::Stack_Arr(int size) : size(size), top(-1) {
    data = new int[size];
}

void Stack_Arr::push_Arr(int val) {
    if (top < size) {
        data[++top] = val;
    } else {
        cout << "Stack is full!" << endl;
    }
}

int Stack_Arr::pop_Arr() {
    if (top == -1)
        return -1;

    return data[top--];
}
bool Stack_Arr::empty_Arr() {
    return top == -1;
}

void Stack_Arr::print_Arr() {
    for (int i = top; i >= 0; i--) {
        cout << "| " << data[i] << " |" << endl;
    }
}