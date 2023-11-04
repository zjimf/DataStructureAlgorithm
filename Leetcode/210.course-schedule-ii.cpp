/** 210. Course schedule II
 *  @brief using topological sort
 *  build graph and inDegree table, start from begin node(inDegree value = 0)
 *  and start topological sort, store value in topologicalSort, then count the path(coursesFinished)
 *  if equal numCourses, means ok(no cycle) return topologicalSort
 *  but if bigger than numCourses means have cycle!
 *
 */
class Solution {
public:
    vector<int> findOrder(int numCourses, vector<vector<int>> &prerequisites) {
        vector<vector<int>> graph(numCourses, vector<int>());
        vector<int> inDegree(numCourses, 0);
        vector<int> topologicalSort;
        int count = 0;
        // build graph and inDegree table
        for (auto &prereq : prerequisites) {
            graph[prereq[1]].push_back(prereq[0]);
            inDegree[prereq[0]]++;
        }

        queue<int> queue;
        for (int i = 0; i < inDegree.size(); i++)
            if (inDegree[i] == 0) {
                queue.push(i);
                topologicalSort.push_back(i);
            }

        while (!queue.empty()) {
            int front = queue.front();
            queue.pop();
            count++;

            for (auto item : graph[front]) {
                if (--inDegree[item] == 0) {
                    queue.push(item);
                    topologicalSort.push_back(item);
                }
            }
        }
        if (count != numCourses)
            return {};
        return topologicalSort;
    }
};
