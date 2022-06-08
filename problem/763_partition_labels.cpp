#include <string>
#include "../tool/leet_tool.h"
using namespace std;

class Solution {
public:
  vector<int> partitionLabels(string s) {
    if (s.length() == 0) return vector<int>();

    vector<int> lastPos(26, -1);
    for (int i = 0; i < s.size(); i++) {
      lastPos[s[i] - 'a'] = i;
    }

    vector<int> result;
    int left = 0, right = 0;
    while (left < s.size()) {
      int i = left;
      right = lastPos[s[left] - 'a'];
      while (i < s.size() && right < s.size() && i < right) {
        right = max(right, lastPos[s[i++] - 'a']);
      }

      result.push_back(right - left + 1);
      left = right + 1;
    }

    return result;
  }
};

int main(int argc, char** argv) {
  string s = "ababcbacadefegdehijhklij";
  Solution sol;
  leet::printArray(sol.partitionLabels(s));
}