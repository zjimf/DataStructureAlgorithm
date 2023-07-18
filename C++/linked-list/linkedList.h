#ifndef linkedList_H
#define linkedList_H

class LinkedList;

class Node {
private:
    int data;
    Node *next;

public:
    // constructor
    Node();
    Node(int data);

    friend class LinkedList;
};

class LinkedList {
private:
    Node *head;

public:
    // constructor
    LinkedList();

    /** @brief Appends a new node to the end of the list
     *
     * @param data The value store in Node
     *
     * @return Void.
     */
    void Append(int data);

    /** @brief Print all of the node data from head
     *
     * @return Void.
     */
    void PrintList();

    /** @brief Print the num of the node in the list
     *
     * @return The count of nodes
     */
    int Count();

    /** @brief Delete the target value node in the list
     *
     * @param target The value we want delete
     *
     * @return Void.
     */
    void Delete(int target);

    /** @brief According the index insert the node in the list
     *
     * @param data The node data
     * @param index The index we want insert in the list
     *
     * @return Void.
     */
    void Insert(int data, int index);

    /** @brief Reverse the list(1->2->3 => 3->2->1)
     *
     * @return Void.
     */
    void Reverse();
};

#endif