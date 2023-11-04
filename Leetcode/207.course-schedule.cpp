/** 207. Course schedule
 *  @brief using topological sort
 *  build graph and inDegree table, start from begin node(inDegree value = 0)
 *  and start topological sort, then count the path(coursesFinished)
 *  if equal numCourses, means ok(no cycle), but if bigger than numCourses means have cycle
 *
 */
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
        for (int i = 0; i < numCourses; i++)
            if (inDegrees[i] == 0)
                q.push(i);

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

// DFS
// class Solution {
// public:
//     bool canFinish(int numCourses, vector<pair<int, int>> &prerequisites) {
//         graph g = buildGraph(numCourses, prerequisites);
//         vector<bool> todo(numCourses, false), done(numCourses, false);
//         for (int i = 0; i < numCourses; i++) {
//             if (!done[i] && !acyclic(g, todo, done, i)) {
//                 return false;
//             }
//         }
//         return true;
//     }

// private:
//     typedef vector<vector<int>> graph;

//     graph buildGraph(int numCourses, vector<pair<int, int>> &prerequisites) {
//         graph g(numCourses);
//         for (auto p : prerequisites) {
//             g[p.second].push_back(p.first);
//         }
//         return g;
//     }

//     bool acyclic(graph &g, vector<bool> &todo, vector<bool> &done, int node) {
//         if (todo[node]) {
//             return false;
//         }
//         if (done[node]) {
//             return true;
//         }
//         todo[node] = done[node] = true;
//         for (int v : g[node]) {
//             if (!acyclic(g, todo, done, v)) {
//                 return false;
//             }
//         }
//         todo[node] = false;
//         return true;
//     }
// };
