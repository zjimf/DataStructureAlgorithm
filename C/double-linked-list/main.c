#include "dbLinkedList.h"
#include <stdio.h>
#include <stdlib.h>

int main() {
    Node *head = NULL;
    int length = 0, appendVal, deleteVal, insertVal, insertIndex;
    printf("The length of list: ");
    scanf("%d", &length);

    for (int i = 0; i < length; i++) {
        printf("Node%d's value is: ", i + 1);
        scanf("%d", &appendVal);
        Append(&head, appendVal);
    }

    PrintList(head);

    printf("Count: %d\n", Count(head));

    printf("The value you want delete: ");
    scanf("%d", &deleteVal);
    Delete(&head, deleteVal);
    PrintList(head);

    printf("The value you want insert: ");
    scanf("%d", &insertVal);
    printf("The index you want insert: ");
    scanf("%d", &insertIndex);
    Insert(&head, insertVal, insertIndex);
    PrintList(head);
}