/*
  link: https://leetcode.com/problems/longest-substring-without-repeating-characters/
  Given a string s, find the length of the longest substring without repeating characters.

 

Example 1:

Input: s = "abcabcbb"
Output: 3
Explanation: The answer is "abc", with the length of 3.
Example 2:

Input: s = "bbbbb"
Output: 1
Explanation: The answer is "b", with the length of 1.
Example 3:

Input: s = "pwwkew"
Output: 3
Explanation: The answer is "wke", with the length of 3.
Notice that the answer must be a substring, "pwke" is a subsequence and not a substring.
Example 4:

Input: s = ""
Output: 0
 

Constraints:

0 <= s.length <= 5 * 104
s consists of English letters, digits, symbols and spaces.
*/

#include <iostream>
#include "../tool/leet_data.h"
#include "../tool/leet_tool.h"
#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
using namespace leet;
using namespace std;

class Solution_SlidingWindow {
public:
    int lengthOfLongestSubstring(string s) {
        vector<int> chMap(256, -1);
        int lo = 0, hi = 0;
        int maxLen = 0;

        while(hi <= s.size()) {
            if(hi == s.size() || chMap[ s[hi] ] != -1) { // found a no repeat substring
                maxLen = max(maxLen, hi - lo);
                if(hi == s.size()) break;

                int x = chMap[ s[hi] ];
                for(int i = lo; i <= x; i++) chMap[ s[i] ] = -1;
                lo = x + 1;
            }

            chMap[s[hi]] = hi;
            hi++;
        }

        return maxLen;
    }
};

class Solution_Elegant {
public:
    int lengthOfLongestSubstring(string s) {
        vector<int> chMap(256, -1);
        int maxLen = 0, lastDupIdx = 0;
        for(int i = 0; i < s.size(); i++) {
            lastDupIdx = max( chMap[s[i]] + 1, lastDupIdx); // 上一次发生过位置重复的位置
            chMap[ s[i] ] = i;
            maxLen = max(maxLen, i - lastDupIdx + 1);
            cout << " lastDupIdx=" << lastDupIdx << endl;
        }

        return maxLen;
    }
};

int main() {
    Solution_SlidingWindow sol1;
    Solution_Elegant sol2;
    string s = "axcab";
    cout << "(Sol1) maxLen: " << sol1.lengthOfLongestSubstring(s) << endl;
    cout << "(Sol2) maxLen: " << sol2.lengthOfLongestSubstring(s) << endl;
    return 0;
}
