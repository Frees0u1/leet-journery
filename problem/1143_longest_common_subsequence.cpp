#include <iostream>
#include <algorithm>
#include <vector>
#include "../tool/leet_tool.h"
using namespace std;

/*
* dp[i][j]: the lcs of text1[0...i] and text2[0...j]
*/
class Solution {
public:
  int longestCommonSubsequence(string text1, string text2) {
    int m = text1.length(); if (m == 0) return 0;
    int n = text2.length(); if (n == 0) return 0;

    vector<vector<int>> dp(m + 1, vector<int>(n + 1, 0));
    for (int i = 1; i <= m; i++) {
      for (int j = 1; j <= n; j++) {
        dp[i][j] = max(dp[i - 1][j - 1], max(dp[i][j - 1], dp[i - 1][j]));

        if (text1[i - 1] == text2[j - 1]) {
          dp[i][j] = max(dp[i][j], dp[i - 1][j - 1] + 1);
        }
      }
    }

    leet::printArray(dp);
    return dp[m][n]
      ;
  }
};

int main() {
  Solution sol;
  cout << sol.longestCommonSubsequence("abc", "def") << endl;
  return 0;
}
