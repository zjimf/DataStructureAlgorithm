#include "DBLinkedList.h"
#include <iostream>
using namespace std;

int main() {
    DBLinkedList dbList;
    int length, nodeVal, deleteVal, insertVal, insertIndex;
    cout << "The length of the linked list: ";
    cin >> length;

    for (int i = 1; i <= length; i++) {
        printf("The node%d value is: ", i);
        cin >> nodeVal;
        dbList.Append(nodeVal);
    }
    dbList.PrintList();

    cout << "List len is: " << dbList.Count() << endl;

    cout << "The value you want delete: ";
    cin >> deleteVal;
    dbList.Delete(deleteVal);
    dbList.PrintList();

    cout << "The value you want insert: ";
    cin >> insertVal;
    cout << "The index you want insert: ";
    cin >> insertIndex;
    dbList.Insert(insertVal, insertIndex);
    dbList.PrintList();
}