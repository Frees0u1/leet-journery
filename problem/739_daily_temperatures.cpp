#include <iostream>
#include <algorithm>
#include <vector>
#include <stack>
#include "../tool/leet_tool.h"
using namespace std;

class Solution {
public:
    vector<int> dailyTemperatures(vector<int>& temperatures) {
        vector<int> result(temperatures.size(), 0);
        if(temperatures.empty()) { return result; }
        
        stack<int> stk;
        stk.push(0);

        for(int i = 1; i < temperatures.size(); i++) {
            while(!stk.empty() && temperatures[i] > temperatures[stk.top()]) {
              result[stk.top()] = i - stk.top();
              stk.pop();
            }
            
            stk.push(i);
        }

        return result;
    }
};

int main() {
  Solution sol;
  vector<int> temps {73,74,75,71,69,72,76,73};

  leet::printArray(sol.dailyTemperatures(temps));

  return 0;
}