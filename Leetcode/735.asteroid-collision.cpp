/** 735. Asteroid Collision
 *  @brief Stack
 *
 *  @Time_complexity O(N)
 */
class Solution {
public:
    vector<int> asteroidCollision(vector<int> &asteroids) {
        vector<int> s;
        for (auto asteroid : asteroids) {
            if (asteroid > 0 || s.empty())
                s.push_back(asteroid);
            else {
                while (!s.empty() && s.back() > 0 && s.back() < abs(asteroid))
                    s.pop_back();
                if (!s.empty() && s.back() == abs(asteroid))
                    s.pop_back();
                else if (s.empty() || s.back() < 0)
                    s.push_back(asteroid);
            }
        }
        return s;
    }
};