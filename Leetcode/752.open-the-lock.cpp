/** 752. Open the Lock
 *  @brief BFS, Find all possible steps for the current password, enqueue in queue
 *         Then check whether each current value of the queue is equal to the target
 *         If not, find all possibilities for the current value, enqueue in queue
 *
 *  @Time_complexity O(N^2)
 */
class Solution {
public:
    int openLock(vector<string> &deadends, string target) {
        int steps = -1;
        unordered_set<string> visited(deadends.begin(), deadends.end());
        array<char, 10> ch = {'0', '1', '2', '3', '4', '5', '6', '7', '8', '9'};
        queue<string> queue;
        if (!visited.count("0000")) {
            queue.push("0000");
            visited.insert("0000");
        }

        while (!queue.empty()) {
            ++steps;
            // related with previous round
            for (int size = queue.size() - 1; size >= 0; --size) {
                string current = queue.front();
                queue.pop();

                if (current == target)
                    return steps;

                // all possible
                for (int digitIndex = 0; digitIndex < 4; digitIndex++) {
                    for (int leftORright = -1; leftORright <= 1; leftORright += 2) {
                        string neighbor = current;
                        neighbor[digitIndex] = ch[(neighbor[digitIndex] - '0' + leftORright + 10) % 10];

                        if (!visited.count(neighbor)) {
                            queue.push(neighbor);
                            visited.insert(neighbor);
                        }
                    }
                }
            }
        }
        return -1;
    }
};
