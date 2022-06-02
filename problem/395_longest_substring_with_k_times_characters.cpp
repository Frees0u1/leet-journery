#include <iostream>
#include <algorithm>
#include <vector>
#include <unordered_map>
#include "../tool/leet_tool.h"
using namespace std;

// bruce force. O(26^N^2)
class Solution {
public:
  int longestSubstring(const string& s, int k) {
    for(int len = s.size(); len >= k; len--) {
      if(isValid(s, len, k)) return len;
    }

    return 0;
  }

private:
  bool isValid(const string& s, int len, int k) {
    if(len > s.size()) return false;
    if(len == 0) return false;

    vector<int> chMap(26, 0);
    for(int i = 0; i < len; i++) {
      int cIdx = s[i] - 'a';
      chMap[cIdx]++;
    }
    if(getMinRepeatTimes(chMap) >= k) return true;
    // leet::printArray(chMap);

    for(int i = len; i < s.size(); i++) {
      int rightIndex = s[i] - 'a';
      int leftIndex = s[i - len] - 'a';
      if(rightIndex == leftIndex) continue;

      chMap[rightIndex]++;
      chMap[leftIndex]--;
      if(getMinRepeatTimes(chMap) >= k) return true;
    }

    return false;
  }

  int getMinRepeatTimes(const vector<int>& chMap) {
    int minRepeatTimes = INT_MAX;
    for(int repeatTime: chMap) {
      if(repeatTime > 0) {
        minRepeatTimes = min(minRepeatTimes, repeatTime);
      }
    }

    return minRepeatTimes;
  }
};

// sliding window: each window has most m distinct characters - O(26N)
class Solution2 {
public:
  int longestSubstring(const string& s, int k) {
    int result = 0;
    for(int m = 1; m <= 26; m++) {
      result = max(result, helper(s, m, k));
    }
    return result;
  }
private:
  int helper(const string& s, int m, int k) {
    int result = 0;
    unordered_map<char, int> freqMap;
    int count = 0;
    int left = 0, right = 0;
    
    while(left < s.size()) {
      while(right < s.size() && freqMap.size() <= m) {
        freqMap[s[right]]++;
        if(freqMap[s[right]] == k) count++;
        if(freqMap.size() == m && count == m) result = max(result, right - left + 1);
        right++;
      }
      freqMap[s[left]]--;
      if(freqMap[s[left]] == k - 1) count--;
      if(freqMap[s[left]] == 0) freqMap.erase(s[left]);
      left++;
    }

    return result;
  }
};

// divided and conquer
// if we found some characters it's total repeat times is less than k
// then any substring contains it would be useless
// e.g [X, X, a, X, X, X, a, X, X], k=3
// the a repeat times is 2, so we can divide the whole string with the `a`
class Solution3 {
public:
  int longestSubstring(const string& s, int k) {
    return helper(s, 0, s.size(), k);
  }

private:
  int helper(const string& s, int lo, int hi, int k) {
    printf("lo = %d, hi = %d \n", lo, hi);
    if(hi - lo < k) { 
      printf("result = 0\n");
      return 0; 
    }
    vector<int> chMap(26, 0);
    for(int i = lo; i < hi; i++) {
      chMap[s[i] - 'a']++;
    }
    leet::printArray(chMap);

    bool hasBadCharacter = false;
    for(int i = 0; i < 26; i++) {
      if(chMap[i] > 0 && chMap[i] < k)  {
        hasBadCharacter = true;
        break;
      }
    }

    if(!hasBadCharacter) {
      printf("result = %d\n", hi - lo);
      return hi - lo;
    }

    int start = 0;
    int result = 0;
    for(int i = 0; i <= s.size(); i++) {
      if(i == s.size() || chMap[s[i] - 'a'] < k) {
        result = max(result, helper(s, start, i, k));
        start = i + 1;
      }
    }

    printf("result = %d\n", result);
    return result;
  }
};

int main() {
  Solution3 sol;
  string s = "aaabb";
  cout << sol.longestSubstring(s, 3) << endl;
  return 0;
}