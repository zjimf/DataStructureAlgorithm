#ifndef Stack_LinkedList_H
#define Stack_LinkedList_H
class Stack_LinkedList;

class Node {
private:
    int data;
    Node *next;

public:
    Node();
    Node(int data);

    friend class Stack_LinkedList;
};

class Stack_LinkedList {
private:
    Node *top;

public:
    Stack_LinkedList();

    /** @brief Push data in Stack
     *
     * @param val The value push in Stack
     *
     * @return Void.
     */
    void push_LinkedList(int val);

    /** @brief Pop data in Stack
     *
     * @return Int. top value in Stack
     */
    int pop_LinkedList();

    /** @brief Determine the Stack is empty
     *
     * @return Bool. the Stack is empty
     */
    bool empty_LinkedList();

    /** @brief Print all data in the Stack, from top to bottom
     *
     * @return Void.
     */
    void print_LinkedList();
};

#endif