#ifndef AVL_H
#define AVL_H

typedef struct Node Node;
struct Node {
    Node *left, *right;
    int data;
    int height;
};

/** @brief Get the current node height value
 *
 * @param node pointer to node
 *
 * @return Int. The height value of node
 */
int height(Node *node);

/** @brief Build new Node
 *
 * @param data the data we want store
 *
 * @return Node. pointer to new Node
 */
Node *newNode(int data);

/** @brief right rotate for balance the AVL tree
 *
 * @param y pointer to unbalance node abs(height(left child) - height(right child)) > 1
 *
 * @return Node. pointer to adjusted tree root
 */
Node *rightRotate(Node *y);

/** @brief left rotate for balance the AVL tree
 *
 * @param y pointer to unbalance node abs(height(left child) - height(right child)) > 1
 *
 * @return Node. pointer to adjusted tree root
 */
Node *leftRotate(Node *y);

/** @brief get the balance value (height(left child) - height(right child))
 *
 * @param node pointer to current node
 *
 * @return Int. balance value
 */
int getBalance(Node *node);

/** @brief find the left most node
 *
 * @param node pointer to root
 *
 * @return Node. pointer to left most node
 */
Node *minValue(Node *node);

/** @brief insert the value into AVL
 *
 * @param node pointer to root
 * @param data the data we want insert
 *
 * @return Node. pointer to root
 */
Node *insert(Node *node, int data);

/** @brief delete the value into AVL
 *
 * @param node pointer to root
 * @param target the data we want delete
 *
 * @return Node. pointer to root
 */
Node *delete(Node *node, int target);

/** @brief preorder traversal
 *
 * @param root pointer to BST root
 *
 * @return Void.
 */
void preorder(Node *root);

/** @brief inorder traversal
 *
 * @param root pointer to BST root
 *
 * @return Void.
 */
void inorder(Node *root);

/** @brief postorder traversal
 *
 * @param root pointer to BST root
 *
 * @return Void.
 */
void postorder(Node *root);

#endif