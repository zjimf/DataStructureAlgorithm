#ifndef linkedList_H
#define linkedList_H

struct node {
    int data;
    struct node *next;
};
typedef struct node Node;

/** @brief Appends a new node to the end of the list
 *
 * @param head Double pointer to the head of the list
 * @param data The value store in Node
 *
 * @return Void.
 */
void Append(Node **head, int data);

/** @brief Print all of the node data from head
 *
 * @param head Pointer to the head of the list
 *
 * @return Void.
 */
void PrintList(Node *head);

/** @brief Print the num of the node in the list
 *
 * @param head Pointer to the head of the list
 *
 * @return The count of nodes
 */
int Count(Node *head);

/** @brief Delete the target value node in the list
 *
 * @param head Pointer to the head of the list
 * @param target The value we want delete
 *
 * @return Void.
 */
void Delete(Node **head, int target);

/** @brief Insert the node in the list
 *
 * @param head Double pointer to the head of the list
 * @param data The node data
 * @param index The index we want insert in the list
 *
 * @return Void.
 */
void Insert(Node **head, int data, int index);

/** @brief Reverse the list(1->2->3 => 3->2->1)
 *
 * @param head Double pointer to the head of the list
 *
 * @return Void.
 */
void Reverse(Node **head);

#endif