#ifndef Stack_Arr_h
#define Stack_Arr_h

class Stack_Arr {
private:
    int *data;
    int top;
    int size;

public:
    Stack_Arr(int size);

    /** @brief Push data in Stack
     *
     * @param val The value push in Stack
     *
     * @return Void.
     */
    void push_Arr(int val);

    /** @brief Pop data in Stack
     *
     * @return Int. top value in Stack
     */
    int pop_Arr();

    /** @brief Determine the Stack is empty
     *
     * @return Bool. the Stack is empty
     */
    bool empty_Arr();

    /** @brief Print all data in the Stack, from top to bottom
     *
     * @return Void.
     */
    void print_Arr();
};

#endif