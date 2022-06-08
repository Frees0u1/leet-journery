#include <iostream>
#include <algorithm>
#include <vector>
#include "../tool/leet_tool.h"
using namespace std;


/*
* dp[i][j]: nums[0..i] exist such subset that it's sum equals to x
* rolling rows to optimize
*/
class Solution {
public:
  bool canPartition(vector<int>& nums) {
    int n = nums.size();
    if (n < 2) return false;
    int sum = 0;
    for (int i = 0; i < n; i++) sum += nums[i];
    if (sum % 2 == 1) return false;

    int c = sum / 2;
    vector<vector<bool>> dp(n, vector<bool>(c + 1, false));
    if (nums[0] > c) return false;
    dp[0][nums[0]] = true;

    for (int i = 1; i < n; i++) {
      for (int j = c; j >= 0; j--) {
        dp[i][j] = dp[i - 1][j] ||
          (j >= nums[i] && dp[i - 1][j - nums[i]]);
      }
    }

    leet::printArray(dp);
    return dp[n - 1][c];
  }
};

int main() {
  Solution sol;
  vector<int> nums{ 5, 5 };
  cout << sol.canPartition(nums) << endl;
  return 0;
}