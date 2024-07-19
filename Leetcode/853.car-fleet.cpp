/*
 * @lc app=leetcode id=853 lang=cpp
 *
 * [853] Car Fleet
 */

// @lc code=start
class Solution {
    class Car {
    public:
        int pos, speed;
        Car(int p, int s) : pos(p), speed(s){};
    };

    static bool carComp(Car&a, Car&b) {
           return a.pos < b.pos;
       
    };

    public:
         int carFleet(int target, vector<int> &position, vector<int> &speed) {
            vector<Car> cars;
            for (int i = 0; i < position.size(); i++){    
                Car car(position[i],speed[i]);
                cars.push_back(car);
            }
            sort(cars.begin(),cars.end(),carComp);

            stack<float> s;
            for(auto car:cars){
                float time = (target-car.pos) / (float)car.speed;
                while(!s.empty()&&time>=s.top())
                    s.pop();
                
                s.push(time);
            }
            return s.size();
    }
};
