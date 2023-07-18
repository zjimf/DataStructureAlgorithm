#include "linkedList.h"
#include <iostream>
using namespace std;

int main() {
    LinkedList list;
    int length, nodeVal, deleteVal, insertVal, insertIndex;
    cout << "The length of the linked list: ";
    cin >> length;

    for (int i = 1; i <= length; i++) {
        printf("The node%d value is: ", i);
        cin >> nodeVal;
        list.Append(nodeVal);
    }

    list.PrintList();
    cout << "List len is: " << list.Count() << endl;

    cout << "The value you want delete: ";
    cin >> deleteVal;
    list.Delete(deleteVal);
    list.PrintList();

    cout << "The value you want insert: ";
    cin >> insertVal;
    cout << "The index you want insert: ";
    cin >> insertIndex;
    list.Insert(insertVal, insertIndex);
    list.PrintList();

    cout << "Reverse";
    list.Reverse();
    list.PrintList();
}