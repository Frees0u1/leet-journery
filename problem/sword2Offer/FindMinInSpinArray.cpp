#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

class Solution {
public:
  /**
   * @param nums: a rotated sorted array
   * @return: the minimum number in the array
   */
  int findMin(vector<int>& nums) {
    if (nums.size() <= 0) throw "bad input";

    int lo = 0, mi = 0, hi = nums.size() - 1;
    while (nums[lo] >= nums[hi]) {
      if (hi - lo == 1) {
        mi = hi; break;
      }

      mi = lo + (hi - lo) / 2;
      if (nums[mi] >= nums[lo]) {
        lo = mi;
      }
      else {
        hi = mi;
      }
    }

    return nums[mi];
  }
};

int main() {
  Solution sol;
  vector<int> nums{ 2, 1 };
  cout << sol.findMin(nums) << endl;
  return 0;
}