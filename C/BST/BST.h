#ifndef BST_H
#define BST_H
#include <stdbool.h>

typedef struct BST_Node BST_Node;
struct BST_Node {
    BST_Node *left, *right;
    int data;
};

/** @brief Build the new Node
 *
 * @param value the value store in node
 *
 * @return BST_Node. pointer to BST_Node
 */
BST_Node *newNode(int value);

/** @brief Insert the value in BST
 *
 * @param root pointer to BST root
 * @param value the value store in BST
 *
 * @return BST_Node. pointer to node
 */
BST_Node *insert(BST_Node *root, int value);

/** @brief Delete the value in BST
 *
 * @param root pointer to BST root
 * @param targetVal the value to delete in BST
 *
 * @return BST_Node. pointer to node
 */
BST_Node *deleteNode(BST_Node *root, int targetVal);

/** @brief find maximum value in BST
 *
 * @param root pointer to BST root
 *
 * @return BST_Node. pointer to maximum value node
 */
BST_Node *findMax(BST_Node *root);

/** @brief find minimum value in BST
 *
 * @param root pointer to BST root
 *
 * @return BST_Node. pointer to minimum value node
 */
BST_Node *findMin(BST_Node *root);

/** @brief determine whether the BST is empty
 *
 * @param root pointer to BST root
 *
 * @return Bool. BST is empty
 */
bool isEmpty(BST_Node *root);

/** @brief calculate the tree height
 *
 * @param root pointer to BST root
 *
 * @return Int. tree height
 */
int height(BST_Node *root);

/** @brief preorder traversal
 *
 * @param root pointer to BST root
 *
 * @return Void.
 */
void preorder(BST_Node *root);

/** @brief inorder traversal
 *
 * @param root pointer to BST root
 *
 * @return Void.
 */
void inorder(BST_Node *root);

/** @brief postorder traversal
 *
 * @param root pointer to BST root
 *
 * @return Void.
 */
void postorder(BST_Node *root);

#endif