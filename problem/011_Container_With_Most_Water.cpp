/*
link: https://leetcode.com/problems/container-with-most-water/

Given n non-negative integers a1, a2, ..., an , where each represents a point at coordinate (i, ai). n vertical lines are drawn such that the two endpoints of the line i is at (i, ai) and (i, 0). Find two lines, which, together with the x-axis forms a container, such that the container contains the most water.

Notice that you may not slant the container.

![image](https://s3-lc-upload.s3.amazonaws.com/uploads/2018/07/17/question_11.jpg) 

Example 1:


Input: height = [1,8,6,2,5,4,8,3,7]
Output: 49
Explanation: The above vertical lines are represented by array [1,8,6,2,5,4,8,3,7]. In this case, the max area of water (blue section) the container can contain is 49.
Example 2:

Input: height = [1,1]
Output: 1
Example 3:

Input: height = [4,3,2,1,4]
Output: 16
Example 4:

Input: height = [1,2,1]
Output: 2
 

Constraints:

n == height.length
2 <= n <= 3 * 104
0 <= height[i] <= 3 * 104
*/

#include <iostream>
#include "../tool/leet_data.h"
#include "../tool/leet_tool.h"
#include <iostream>
#include <algorithm>
using namespace leet;
using namespace std;

class Solution {
public:
    int maxArea(vector<int>& height) {
        if(height.size() < 2) return 0;

        int left = 0, right = (int)height.size() - 1;
        int maxArea = 0;
        while(left < right) {
            int h = min(height[left], height[right]);
            maxArea = max(maxArea, (right - left) * h);

            while(left < right && height[left] <= h) left++;
            while(left < right && height[right] <= h) right--;
        }

        return maxArea;
    }

private:
    int calcArea(int l, int r, const vector<int>& height) {
        if(r <= l) return 0;        
        return (r - l) * min(height[l], height[r]);
    }
};



int main() {
    Solution sol;
    vector<int> height{1,8,6,2,5,4,8,3,7};
    cout << sol.maxArea(height) << endl;
    return 0;
}
