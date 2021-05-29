/*
42. Trapping Rain Water
Hard
Given n non-negative integers representing an elevation map where the width of each bar is 1, compute how much water it can trap after raining.

Example 1:


Input: height = [0,1,0,2,1,0,1,3,2,1,2,1]
Output: 6
Explanation: The above elevation map (black section) is represented by array [0,1,0,2,1,0,1,3,2,1,2,1]. In this case, 6 units of rain water (blue section) are being trapped.
Example 2:

Input: height = [4,2,0,3,2,5]
Output: 9
*/


#include <iostream>
#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

class Solution {
public:
  int solve(const vector<int>& heights) {
    int n = heights.size();
    if (n <= 2) return 0;
    int left = 0, right = n - 1;

    vector<int> leftMax(n, heights[0]);
    vector<int> rightMax(n, heights[n - 1]);
    for (int i = 1; i < n; i++) {
      int j = n - i - 1;
      leftMax[i] = max(leftMax[i - 1], heights[i]);
      rightMax[j] = max(rightMax[j + 1], heights[j]);
    }

    long long result = 0;
    for (int i = 0; i < n; i++) {
      result += min(leftMax[i], rightMax[i]) - heights[i];
    }

    return result;
  }

  int solve2(vector<int>& height) {
    if (height.size() <= 2) return 0;

    int leftMax = height[0];
    int rightMax = height.back();
    long long res = 0;


    int left = 0, right = height.size() - 1;
    while (left <= right) {
      leftMax = max(leftMax, height[left]);
      rightMax = max(rightMax, height[right]);

      if (leftMax < rightMax) {
        res += leftMax - height[left++];
      }
      else {
        res += rightMax - height[right--];
      }
    }

    return res;
  }
};

int main() {
  Solution sol;
  vector<int> heights{ 3, 2, 1 };
  cout << sol.solve2(heights) << endl;
  return 0;
}
