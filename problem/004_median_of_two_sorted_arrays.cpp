#include <iostream>
#include <algorithm>
using namespace std;

class Solution {
public:
  double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
    int m = nums1.size();
    int n = nums2.size();
    int lo = 0, hi = max(m, n);

    while (lo < hi) {
      int mi = lo + hi / 2;

    }
  }

private:
  int lowerBound(const vector<int>& nums1, int lo, int hi, int target) {
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
};

int main() {
  Solution sol;
  return 0;
}