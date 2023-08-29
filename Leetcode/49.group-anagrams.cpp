/** 49. Group Anagrams
 *  @brief using hashmap, counting sort
 *
 *  @Time_complexity O(N^2)
 */
class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string> &strs) {
        vector<vector<string>> res;
        unordered_map<string, vector<string>> map;
        for (auto &str : strs)
            map[strSort(str)].push_back(str);

        for (auto &m : map)
            res.push_back(m.second);

        return res;
    }

private:
    string strSort(string s) {
        string t;
        int counter[26] = {0};
        for (char c : s)
            counter[c - 'a']++;

        for (int c = 0; c < 26; c++)
            t += string(counter[c], c + 'a'); //(insert num, insert char)

        return t;
    }
};
