/*
link: https://leetcode.com/problems/longest-palindromic-substring/
Given a string s, return the longest palindromic substring in s. 

Example 1:

Input: s = "babad"
Output: "bab"
Note: "aba" is also a valid answer.
Example 2:

Input: s = "cbbd"
Output: "bb"
Example 3:

Input: s = "a"
Output: "a"
Example 4:

Input: s = "ac"
Output: "a"
 

Constraints:

1 <= s.length <= 1000
s consist of only digits and English letters (lower-case and/or upper-case),

*/

#include <iostream>
#include "../tool/leet_data.h"
#include "../tool/leet_tool.h"
#include <iostream>
#include <string>
#include <vector>
using namespace leet;
using namespace std;

class Solution {
public:
    string longestPalindrome(string s) {
        int n = s.size(); 
        if(n <= 1) return s.substr(0, n);

        vector<vector<int>> dp(n, vector<int>(n, -1));
        for(int i = 0; i < n; i++) dp[i][i] = 1;
        int maxLen = 1, maxIdx = 0;

        for(int x = 1; x < n; x++) {
            for(int i = 0; i < n; i++) {
                int j = i + x; if(j >= n) continue;
                
                int previ = i + 1;
                int prevj = j - 1;
                if( (previ > prevj || dp[previ][prevj] == 1)  && s[i] == s[j]) {
                    dp[i][j] = 1;
                    if(j - i + 1 >= maxLen) {
                        maxLen = j - i + 1;
                        maxIdx = i;
                    }
                }
                else {
                    dp[i][j] = 0;
                }
            }
        }

        return s.substr(maxIdx, maxLen);
    }
};

// 马拉车算法
class Solution2 {
public:
    string longestPalindrome(string s) {
        int n = s.size(); 
        if(n == 0) return "";
        string ps = "#";
        for(int i = 0; i < n; i++) {
            ps += s[i];
            ps += "#";
        }

        int center = 0, maxRight = 0;
        int maxLen = 0, begin = 0; 
        vector<int> p(2 * n + 1, 0);
        p[0] = 0;

        for(int i = 0; i < ps.size(); i++) {
            int mirror = 2 * center - i;
            if(i < maxRight) {
                p[i] = min(maxRight - i, p[mirror]);
            }

            int j = i + p[i] + 1;
            while(j < ps.size()) {
                int k = 2 * i - j;
                if(k < 0 || ps[j] != ps[k]) break;
                p[i]++;
                j++;
            }

            if(i + p[i] > maxRight) {
                maxRight = i + p[i];
                center = i;
            }

            if(p[i] > maxLen) {
                maxLen = p[i];
                begin = (i - maxLen) / 2;
            }
        }

        return s.substr(begin, maxLen);
    }
};

int main() {
    Solution sol2;
    string s = "abbcccbbbcaaccbababcbcabca";
    cout << sol2.longestPalindrome(s) << endl;
    return 0;
}
