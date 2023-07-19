#include <stdio.h>
#include <stdlib.h>

#include "linkedList.h"

int main(int argc, char **argv) {
    Node *head = NULL;
    int length, nodeVal, deleteVal, InsertVal, InsertIndex;
    printf("The length of the list: ");
    scanf("%d", &length);

    for (int i = 0; i < length; i++) {
        printf("Enter the Node%d value: ", i + 1);
        scanf("%d", &nodeVal);
        Append(&head, nodeVal);
    }

    PrintList(head);
    printf("length: ");
    printf("%d", Count(head));
    printf("\n");
    printf("The Value You want Delete: ");
    scanf("%d", &deleteVal);
    Delete(&head, deleteVal);
    PrintList(head);
    printf("The Value You want Insert: ");
    scanf("%d", &InsertVal);
    printf("The Index You want Insert: ");
    scanf("%d", &InsertIndex);
    Insert(&head, InsertVal, InsertIndex);
    PrintList(head);
    printf("Reverse List: ");
    Reverse(&head);
    PrintList(head);
    return 0;
}
