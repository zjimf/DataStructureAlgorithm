/*
 * @lc app=leetcode id=981 lang=cpp
 *
 * [981] Time Based Key-Value Store
 */

// @lc code=start
class TimeMap {
public:
    unordered_map<string, vector<pair<int, string>>> hashMap;

    TimeMap() {
    }

    void set(string key, string value, int timestamp) {
        hashMap[key].push_back({timestamp, value});
    }

    string get(string key, int timestamp) {
        if (hashMap.find(key) == hashMap.end())
            return "";

        int low = 0, high = hashMap[key].size() - 1;

        int maxTimeStamp = -1;
        while (low <= high) {
            int mid = (low + high) / 2;

            if (hashMap[key][mid].first <= timestamp) {
                maxTimeStamp = max(maxTimeStamp, mid);
                low = mid + 1;
            } else
                high = mid - 1;
        }

        if (maxTimeStamp == -1)
            return "";
        return hashMap[key][maxTimeStamp].second;
    };
};
/**
 * Your TimeMap object will be instantiated and called as such:
 * TimeMap* obj = new TimeMap();
 * obj->set(key,value,timestamp);
 * string param_2 = obj->get(key,timestamp);
 */
// @lc code=end
