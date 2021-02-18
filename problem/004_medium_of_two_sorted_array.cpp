/*
4. Median of Two Sorted Arrays 
link: https://leetcode.com/problems/median-of-two-sorted-arrays/
Given two sorted arrays nums1 and nums2 of size m and n respectively, return the median of the two sorted arrays.

Follow up: The overall run time complexity should be O(log (m+n)).

 

Example 1:

Input: nums1 = [1,3], nums2 = [2]
Output: 2.00000
Explanation: merged array = [1,2,3] and median is 2.
Example 2:

Input: nums1 = [1,2], nums2 = [3,4]
Output: 2.50000
Explanation: merged array = [1,2,3,4] and median is (2 + 3) / 2 = 2.5.
Example 3:

Input: nums1 = [0,0], nums2 = [0,0]
Output: 0.00000
Example 4:

Input: nums1 = [], nums2 = [1]
Output: 1.00000
Example 5:

Input: nums1 = [2], nums2 = []
Output: 2.00000
 

Constraints:

nums1.length == m
nums2.length == n
0 <= m <= 1000
0 <= n <= 1000
1 <= m + n <= 2000
-106 <= nums1[i], nums2[i] <= 106
*/

#include <iostream>
#include "../tool/leet_data.h"
#include "../tool/leet_tool.h"
#include <iostream>
#include <vector>
#include <algorithm>
using namespace leet;
using namespace std;

class Solution {
public:
    double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
        if(nums1.size() == 0) {
            return buildSingleArrayResult(nums2);
        }
        if(nums2.size() == 0) {
            return buildSingleArrayResult(nums1);
        }

        return nums1.size() <= nums2.size() 
            ? core(nums1, nums2, 0, nums1.size())
            : core(nums2, nums1, 0, nums2.size());
    }

private:
    // A.size <= B.size()
    double core(const vector<int>& A, const vector<int>& B,  int lo, int hi) {
        int m = A.size(), n = B.size();
        int mi = (lo + hi) / 2;
        int i = mi;
        int j = ceil((m + n) / 2.0) - i;

        if(f(A,i - 1) <= f(B, j) && f(B,j - 1) <= f(A, i) ) {
            return buildResult(A, B, i, j);
        } 
        else if(f(B,j) <= f(A, i - 1)) {
            return core(A, B, lo, mi - 1);
        } 
        else {
            return core(A, B, mi + 1, hi);
        }
    }

    int f(const vector<int>& A, int i) {
        if(i < 0) return INT_MIN;
        if(i >= A.size()) return INT_MAX;

        return A[i];
    }
    double buildResult(const vector<int>& A, const vector<int>& B,  int i ,int j) {
        int m = A.size(), n = B.size();
        return (m + n) % 2 == 0
                ? (max(f(A, i - 1), f(B, j - 1)) + min(f(A, i),  f(B, j)))/2.0
                : max(f(A, i - 1), f(B, j - 1));
    }

    double buildSingleArrayResult(const vector<int>& A) {
        int n = A.size();
        if(n == 0) return 0;
        return n % 2 == 0
            ? (A[n / 2] + A[n / 2 - 1]) / 2.0
            : A[n / 2];
    }
};

int main() {
    Solution sol;
    vector<int> nums1 {1, 2, 4};
    vector<int> nums2 {1, 3, 3};

    cout << "result: " << sol.findMedianSortedArrays(nums1, nums2) << endl;
    return 0;
}
