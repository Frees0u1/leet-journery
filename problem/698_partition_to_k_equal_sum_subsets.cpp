#include <iostream>
#include <algorithm>
#include <vector>
#include "../tool/leet_tool.h"
using namespace std;

// Pure DFS
class Solution {
public:
  bool canPartitionKSubsets(vector<int>& nums, int k) {
    if (nums.size() < 2) return false;
    if (k == 1) return true;
    int sum = 0;
    for (int& x : nums) sum += x;
    if (sum % k != 0) return false;
    int targetSum = sum / k;
    vector<bool> visited(nums.size(), false);
    return canPartition(0, nums, k, visited, 0, targetSum);
  }


  bool canPartition(int startIndex, vector<int>& nums, int k, vector<bool>& visited, int curSum, int targetSum) {
    if (k == 1) return true;
    if (curSum > targetSum) return false;
    if (curSum == targetSum)
      return canPartition(0, nums, k - 1, visited, 0, targetSum);

    for (int i = startIndex; i < nums.size(); i++) {
      if (visited[i]) continue;
      visited[i] = true;
      if (canPartition(i + 1, nums, k, visited, curSum + nums[i], targetSum)) return true;
      visited[i] = false;
    }

    return false;
  }
};

int main() {
  Solution sol;
  vector<int> nums{ 4, 3, 2, 3, 5, 2, 1 };

  cout << sol.canPartitionKSubsets(nums, 4) << endl;
  return 0;
}