/** 895. Maximum Frequency Stack
 * @brief priority_queue can auto sort, no matter the type of data
 *
 * Time complexity push: O(log n)
 *                 pop: O(1)
 */
class FreqStack {
    priority_queue<pair<int, pair<int, int>>> maxHeap;
    unordered_map<int, int> map;
    int position = 0;

public:
    FreqStack() {}

    void push(int val) {
        map[val]++;
        maxHeap.push({map[val], {position++, val}});
    }

    int pop() {
        int top = maxHeap.top().second.second;
        map[top]--;
        maxHeap.pop();
        return top;
    }
};
