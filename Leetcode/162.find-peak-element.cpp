/** 162. Find Peak Element
 *  @brief binary search, consider two point is enough
 *
 *  @Time_complexity according to sort algorithm
 */
class Solution {
public:
    int findPeakElement(vector<int> &nums) {
        int left = 0, right = nums.size() - 1;
        while (left < right) {
            int mid = (left + right) / 2;

            if (nums[mid] < nums[mid + 1]) {
                left = mid + 1;
            } else
                right = mid;
        }
        return left;
    }
};

//  Iteration
//  class Solution {
//  public:
//      int findPeakElement(const vector<int> &num) {
//          for(int i = 1; i < num.size(); i ++)
//          {
//              if(num[i] < num[i-1])
//              {// <
//                  return i-1;
//              }
//          }
//          return num.size()-1;
//      }
//  };
