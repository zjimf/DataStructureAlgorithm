#include <iostream>
#include <vector>
using namespace std;

int minSubArrayLen(int target, vector<int> &nums) {
    sort(nums.begin(), nums.end());
    int ans = 0, b = 0, e = 0;
    int current = nums[0];
    while (e < nums.size()) {
        if (current < target)
            current += nums[++e];
        else if (current > target)
            current -= nums[b++];
        else {
            ans = e - b + 1;
            current += nums[++e];
        }
    }
    return ans;
}

int main() {
    vector<int> v = {2, 3, 1, 2, 4, 3};
    cout << minSubArrayLen(7, v);
}