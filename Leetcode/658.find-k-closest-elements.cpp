/** 658. Find K Closest Elements
 * @brief priority queue adding pair
 *
 * Time_complexity O(N * log(N))
 */
class Solution {
public:
    vector<int> findClosestElements(vector<int> &arr, int k, int x) {
        vector<int> ans;
        priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;

        for (auto ele : arr)
            pq.push({abs(ele - x), ele});

        for (int i = 0; i < k; i++) {
            ans.push_back(pq.top().second);
            pq.pop();
        }

        sort(ans.begin(), ans.end());

        return ans;
    }
};

/** 658. Find K Closest Elements
 * @brief Customize sorting algorithm, in place
 *
 * Time_complexity O(N * log(N))
 */
// class Solution {
// public:
//     vector<int> findClosestElements(vector<int> &arr, int k, int x) {
//         // we sort the given vector using custom comparator (lambda function)
//         sort(arr.begin(), arr.end(), [&](int &a, int &b) {
//             if (abs(x - a) < abs(x - b))
//                 return true; // it should be sorted according to lower absolute difference
//             else if (abs(x - a) == abs(x - b))
//                 return a < b; // if the absolute difference is same we sort it according to the smaller element
//             return false;     // otherwise we return false
//         });
//         vector<int> ans;
//         for (int i = 0; i < arr.size() && k--; i++) { // we consider the first k elements after sorting
//             ans.push_back(arr[i]);
//         }
//         sort(ans.begin(), ans.end()); // as we have to return the answer in sorted order, we sort it at the end.
//         return ans;
//     }
// };