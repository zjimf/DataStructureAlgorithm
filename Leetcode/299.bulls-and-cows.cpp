/** 299. Bulls and Cows
 * @brief
 * 1. store each secret char nums in map
 * 2. see each guess char and check the map to count B
 * 3. check A and B each char is same(calculate A)
 *
 * Time_complexity O(N)
 */
class Solution {
public:
    string getHint(string secret, string guess) {
        int A = 0, B = 0, len = secret.length();
        unordered_map<char, int> map;
        for (auto &c : secret)
            map[c] = (map.find(c) == map.end()) ? 1 : map[c] + 1;

        for (auto &c : guess) {
            if (map.find(c) != map.end() && map[c] != 0) {
                B++;
                map[c]--;
            }
        }

        for (int i = 0; i < len; i++)
            if (secret[i] == guess[i])
                A++;

        return to_string(A) + "A" + to_string(B - A) + "B";
    }
};
