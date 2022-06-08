#include <iostream>
#include <algorithm>
#include <set>
#include <vector>
#include <unordered_map>
#include "../tool/leet_tool.h"
using namespace std;

// std::distance time complexity is O(n), so this solution will get TLE when test data set is large
class Solution {
public:
  vector<int> countSmaller(const vector<int>& nums) {
    vector<int> result(nums.size(), 0);
    if(nums.empty()) return result;
    multiset<int> rightNumbers;
    rightNumbers.insert(nums.back());

    for(int i = (int)nums.size() - 2; i >= 0; i--) {
      
      auto lowerBound = rightNumbers.lower_bound(nums[i]);      
      result[i] = distance(rightNumbers.begin(), lowerBound);
      rightNumbers.insert(nums[i]);
    }

    return result;
  }
};


// merge sort, find the semiCount
struct Node {
  int val;
  int idx;
  int semiCount;

  Node(int val, int idx, int semiCount):val(val), idx(idx), semiCount(semiCount) {}
};

class Solution2 {
public:
  vector<int> countSmaller(const vector<int>& nums) {
    int n = nums.size();
    vector<Node> nodes;
    for(int i = 0; i < n; i++) {
      nodes.emplace_back(Node(nums[i], i, 0));
    }
    mergeSortAndCount(nodes, 0, n);

    vector<int> result(n, 0);
    for(int i = 0; i < n; i++) {
      result[ nodes[i].idx ] = nodes[i].semiCount;
    }

    return result;
  }
private:
  void mergeSortAndCount(vector<Node>& nodes, int lo, int hi) {
    if(hi - lo <= 1) return;
    int mi = lo + (hi - lo) / 2;

    mergeSortAndCount(nodes, lo, mi);
    mergeSortAndCount(nodes, mi, hi);
    merge(nodes, lo, mi, hi);
  }

  void merge(vector<Node>& nodes, int lo, int mi, int hi) {
    vector<Node> left(nodes.begin() + lo, nodes.begin() + mi);
    int i = 0, j = mi, k = lo;

    int semiCount = 0;
    while(i < left.size() && j < hi) {
      if(left[i].val <= nodes[j].val) {
        nodes[k] = left[i++];
        nodes[k++].semiCount += semiCount;
      }
      else {
        nodes[k++] = nodes[j++];
        semiCount++;
      }
    }

    while(i < left.size()) {
      nodes[k] = left[i++];
      nodes[k++].semiCount += semiCount;
    }
  }
};

int main() {
  Solution2 sol;
  vector<int> nums{5, 2, 6, 1};
  leet::printArray(sol.countSmaller(nums));
  return 0;
}
