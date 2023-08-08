/** 279. Perfect Squares
* @brief 
* 1. if the queue is not empty, iterate the "current" value in Queue, and dequeue the front value each time（front）
* 2. Calculate every possibility of the front, if equal to n then return, enqueue the value, and record in visited if not equal to n and not in visited
* 3. Back to 1
*
* Time_complexity O(N * sqrt(N))
*/
class Solution {
public:
    int numSquares(int n) {
        unordered_set<int> visited;
        queue<int> queue;
        visited.insert(0);
        queue.push(0);
        int steps = 0;

        while (!queue.empty()) {
            ++steps;

            for (int i = queue.size() - 1; i >= 0; i--) {
                int front = queue.front();
                queue.pop();

                for (int j = 1; j * j <= n; j++) {
                    int current = front + j * j;

                    if (current == n)
                        return steps;

                    if (!visited.count(current)) {
                        visited.insert(current);
                        queue.push(current);
                    }
                }
            }
        }
        return steps;
    }
};
