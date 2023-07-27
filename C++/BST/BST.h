#ifndef BST_H
#define BST_H
class BST;
class Node {
private:
    int data;
    Node *left;
    Node *right;
    friend class BST;

public:
    Node(int data);
};

class BST {
private:
    Node *root;

public:
    BST();

    /** @brief Get the root
     *
     * @param value the value store in node
     *
     * @return Node. root
     */
    Node *getRoot();

    /** @brief Build the new Node
     *
     * @param value the value store in node
     *
     * @return BST_Node. pointer to BST_Node
     */
    Node *newNode(int value);

    /** @brief Insert the value in BST
     *
     * @param value the value store in BST
     *
     * @return Node. root
     */
    Node *insert(Node *root, int value);

    /** @brief Delete the value in BST
     *
     * @param targetVal the value to delete in BST
     *
     * @return BST_Node. pointer to node
     */
    Node *deleteNode(Node *root, int targetVal);

    /** @brief find maximum value in BST
     *
     * @param root pointer to BST root
     *
     * @return Int. maximum value
     */
    int findMax(Node *root);

    /** @brief find minimum value in BST
     *
     * @param root pointer to BST root
     *
     * @return Int. minimum value
     */
    int findMin(Node *root);

    /** @brief determine whether the BST is empty
     *
     * @return Bool. BST is empty
     */
    bool isEmpty();

    /** @brief calculate the tree height
     *
     * @param root pointer to BST root
     *
     * @return Int. tree height
     */
    int height(Node *root);

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
};
#endif