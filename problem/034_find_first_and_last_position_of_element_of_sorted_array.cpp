#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

class Solution {
public:
  vector<int> searchRange(vector<int>& nums, int target) {
    if (nums.empty() || target < nums[0] || target > nums.back()) {
      return vector<int>{-1, -1};
    }
    int lb = lowerBound(nums, 0, nums.size(), target);
    int ub = upperBound(nums, lb, nums.size(), target);
    if (lb == ub) return vector<int>{-1, -1};
    return vector<int>{lb, ub - 1};
  }

  int lowerBound(const vector<int>& nums, int lo, int hi, int target) {
    while (lo < hi) {
      int mi = lo + (hi - lo) / 2;
      if (nums[mi] >= target) {
        hi = mi;
      }
      else {
        lo = mi + 1;
      }
    }

    return lo;
  }

  int upperBound(const vector<int>& nums, int lo, int hi, int target) {
    while (lo < hi) {
      int mi = lo + (hi - lo) / 2;
      if (nums[mi] > target) {
        hi = mi;
      }
      else {
        lo = mi + 1;
      }
    }

    return lo;
  }
};
int main() {
  Solution sol;
  vector<int> nums{ 1,1,2,2,4 };
  cout << sol.upperBound(nums, 0, nums.size(), 2) << endl;
  return 0;
}