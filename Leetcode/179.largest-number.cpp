/** 179. Largest Number
 *  @brief using lambda to adding sorting rule in sort algorithm
 *
 *  @Time_complexity according to sort algorithm
 */
class Solution {
public:
    string largestNumber(vector<int> &nums) {
        vector<string> numsStr;
        string ans;
        for (auto n : nums)
            numsStr.push_back(to_string(n));

        sort(numsStr.begin(), numsStr.end(), [](string a, string b) {
            return a + b > b + a;
        });

        for (auto s : numsStr)
            ans += s;

        return ans[0] == '0' ? "0" : ans;
    }
};
