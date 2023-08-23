/** 1249. Minimum Remove to Make Valid Parentheses
 *  @brief Replace the un-match parentheses to "#", then remove it
 *
 *  @Time_complexity O(2N)
 */
class Solution {
public:
    string minRemoveToMakeValid(string s) {
        stack<int> stack;
        string res;
        for (int i = 0; i < s.length(); i++) {
            if (s[i] == '(') {
                s[i] = '#';
                stack.push(i);
            } else if (s[i] == ')') {
                if (stack.empty())
                    s[i] = '#';
                else {
                    int temp = stack.top();
                    stack.pop();
                    s[temp] = '(';
                }
            }
        }

        for (int i = 0; i < s.length(); i++)
            if (s[i] != '#')
                res += s[i];

        return res;
    }
};