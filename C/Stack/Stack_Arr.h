#ifndef Stack_Arr_H
#define Stack_Arr_H
#define MAX_LEN 100
#include <stdbool.h>

struct Stack_Arr {
    int value[MAX_LEN];
    int top;
};

typedef struct Stack_Arr Stack_Arr;

void push_Arr(Stack_Arr *s, int val);

int pop_Arr(Stack_Arr *s);

bool empty_Arr(Stack_Arr *s);

void print_Arr(Stack_Arr *s);

#endif