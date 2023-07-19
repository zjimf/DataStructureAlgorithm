#include "Stack_Arr.h"
#include <stdbool.h>
#include <stdio.h>
#define MAX_LEN 100

void push_Arr(Stack_Arr *s, int val) {
    if (s->top + 1 == MAX_LEN) {
        printf("Stack full");
        return;
    }
    s->value[s->top++] = val;
}

int pop_Arr(Stack_Arr *s) {
    int temp = s->value[s->top - 1];
    s->value[s->top - 1] = -1;
    s->top--;
    return temp;
}

void print_Arr(Stack_Arr *s) {
    for (int i = s->top - 1; i >= 0; i--) {
        if (i == s->top - 1)
            printf("| %d | Top\n", s->value[i]);
        else
            printf("| %d |\n", s->value[i]);
    }
}

bool empty_Arr(Stack_Arr *s) {
    return s->top == 0;
}
