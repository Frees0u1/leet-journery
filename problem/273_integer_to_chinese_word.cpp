#include <iostream>
#include <algorithm>
#include <string>
#include <vector>
#include <stack>
using namespace std;



class Solution {
public:
  string numberToWords(long long num) {
    if(num == 0) return BASE[0];
    
    return generate(num, 3);
  }

private:

  string generate(long long num, int i) {
    if(num == 0) return BASE[0];
    if(num >= 1 && num < 10000) return generateBase(num);

    
      long long left = num / LOOP_BASE[i];
      long long right = num % LOOP_BASE[i];

      if(left == 0) {
        return generate(right, i - 1);
      }

      if(right == 0) {
        return generate(left, i - 1) + LOOP_TIER[i];
      }

      string connector = (right * 10 >= LOOP_BASE[i]) ? "" : "零";
      return generate(left, i - 1) + LOOP_TIER[i] + connector + generate(right, i - 1);
  }

  // 1-9999
  string generateBase(long long num) {
    if(num == 0) return "";
    string result = "";    
    if(num == 10) return TIER[1];
    if(num > 10 && num < 20) {
      return TIER[1] + BASE[num%10];
    }

    int tierIdx = 0;
    int j = 0;

    int lastVal = -1;
    while(num != 0) {
      int val = num % 10;
      if(val == 0) {
        if(lastVal > 0) {
          result = "零" + result;
        }
      }
      else {
        result =  BASE[val] + TIER[tierIdx] + result;
      }

      lastVal = val;
      num /= 10;
      tierIdx++;
    }

    return result;
  }

  const vector<string> BASE {
    "零", "一", "二", "三", "四", "五", "六", "七", "八", "九",
  };

  const vector<string> TIER {
    "", "十", "百", "千",
  };

  const vector<string> LOOP_TIER {
    "", "万", "亿", "兆"
  };

  const vector<long long> LOOP_BASE {
    0, 10000, 100000000, 1000000000000
  };
};

int main() {
  Solution solution;
  long long num; 
  while(cin >> num) {
    cout << solution.numberToWords(num) << endl;
  }

  // for(int i = 0; i < 10000; i++) {
  //   cout << solution.numberToWords(i) << endl;
  // }
  // cout << solution.numberToWords(1010) << endl;
}
