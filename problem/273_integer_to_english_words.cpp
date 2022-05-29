#include <iostream>
#include <algorithm>
#include <string>
#include <vector>
#include <stack>
using namespace std;

const vector<string> BASE {
  "Zero", "One", "Two", "Three", "Four", "Five", "Six", "Seven", "Eight", "Nine", "Ten",
  "Eleven", "Twelve", "Thirteen", "Fourteen", "Fifteen", "Sixteen", "Seventeen", "Eighteen", "Nineteen"
};

const vector<string> TENS {
  "Twenty", "Thirty", "Forty", "Fifty", "Sixty", "Seventy", "Eighty", "Ninety"
};

const string HUNDRED = "Hundred";

const vector<string> TIER {
  "", "Thousand", "Million", "Billion"
};

class Solution {
public:
  string numberToWords(int num) {
    if(num == 0) return BASE[0];
    
    stack<string> results;
    while(num != 0) {
      int val = num % 1000;
      results.push(generateBase(val));
      num /= 1000;
    }

    int i = results.size();
    string toReturn = "";
    while(!results.empty()) {
      const string suffix = TIER[results.size() - 1];
      const string val = results.top();
      if(val != "") { 
        toReturn += 
         ((toReturn != "" ? " " : "") + 
          val);
        if(suffix != "") toReturn += (" " + suffix);
      }
      results.pop();
    }

    return toReturn;
  }

private:
  // 1-999
  string generateBase(const int num) {
    if(num == 0) return "";

    int hundred = num / 100;
    const string hundredStr = hundred > 0 ? BASE[hundred] + " " + HUNDRED: "";
    int val = num % 100;

   // printf("hundred: %d, val: %d\n", hundred, val);
    if(val == 0) {
      return hundredStr == "" ? BASE[val] : hundredStr;
     }

    if(val < 20) {
      return  merge(hundredStr, BASE[val]);
    }

    string temp = merge(hundredStr, TENS[(val / 10) - 2]);
    if(val % 10 == 0) return temp;
    
    return merge(temp, BASE[val % 10]);
  }

  string merge(const string& lhs, const string& rhs) {
    return lhs == "" ? rhs : lhs + " " + rhs;
  }
};

int main() {
  Solution solution;
  int num; 
  while(cin >> num) {
    cout << solution.numberToWords(num) << endl;
  } 
}
