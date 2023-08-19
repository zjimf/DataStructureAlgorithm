/*
 * @lc app=leetcode id=150 lang=cpp
 *
 * [150] Evaluate Reverse Polish Notation
 */

// @lc code=start
class Solution {
public:
    int evalRPN(vector<string> &tokens) {
        stack<int> stack;
        for (string &i : tokens) {
            if (i == "+" || i == "-" || i == "*" || i == "/") {
                int op1 = stack.top();
                stack.pop();
                int op2 = stack.top();
                stack.pop();
                if (i == "+")
                    stack.push(op2 + op1);
                else if (i == "-")
                    stack.push(op2 - op1);
                else if (i == "*")
                    stack.push(op2 * op1);
                else if (i == "/")
                    stack.push(op2 / op1);
            } else {
                stack.push(stoi(i));
            }
        }
        return stack.top();
    }
};
// @lc code=end
