class Solution {
public:
    bool canFinish(int numCourses, vector<vector<int>> &prerequisites) {
        vector<vector<int>> graph(numCourses, vector<int>());
        vector<int> inDegrees(numCourses, 0);

        for (const auto &prereq : prerequisites) {
            graph[prereq[1]].push_back(prereq[0]);
            inDegrees[prereq[0]]++;
        }

        queue<int> q;
        for (int i = 0; i < numCourses; i++) {
            if (inDegrees[i] == 0) {
                q.push(i);
            }
        }

        int coursesFinished = 0;
        while (!q.empty()) {
            int course = q.front();
            q.pop();
            coursesFinished++;

            for (int neighbor : graph[course]) {
                inDegrees[neighbor]--;
                if (inDegrees[neighbor] == 0) {
                    q.push(neighbor);
                }
            }
        }

        return coursesFinished == numCourses;
    }
};
