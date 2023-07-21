#ifndef Stack_Arr_H
#define Stack_Arr_H
#define MAX_LEN 100
#include <stdbool.h>

struct Stack_Arr {
    int value[MAX_LEN];
    int top;
};

typedef struct Stack_Arr Stack_Arr;

/** @brief Push data in Stack
 *
 * @param s Pointer to the Stack
 * @param val The value push in Stack
 *
 * @return Void.
 */
void push_Arr(Stack_Arr *s, int val);

/** @brief Pop data in Stack
 *
 * @param s Pointer to the Stack
 *
 * @return Int. top value in Stack
 */
int pop_Arr(Stack_Arr *s);

/** @brief Determine the Stack is empty
 *
 * @param s Pointer to the Stack
 *
 * @return Bool. the Stack is empty
 */
bool empty_Arr(Stack_Arr *s);

/** @brief Print all data in the Stack, from top to bottom
 *
 * @param s Pointer to the Stack
 *
 * @return Void.
 */
void print_Arr(Stack_Arr *s);

#endif