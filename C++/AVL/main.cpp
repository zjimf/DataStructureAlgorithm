#include "AVL.h"
#include <iostream>
using namespace std;

int main() {
    AVL *avl = new AVL();
    Node *root = avl->getRoot();
    int data[] = {9, 5, 10, 0, 6, 11, -1, 1, 2};
    int len = sizeof(data) / sizeof(data[0]);
    for (int i = 0; i < len; i++) {
        root = avl->insert(root, data[i]);
    }

    cout << "inorder: ";
    avl->inorder(root);
    cout << endl;
    root = avl->deleteNode(root, 10);

    cout << "inorder: ";
    avl->inorder(root);
    cout << endl;

    return 0;
}