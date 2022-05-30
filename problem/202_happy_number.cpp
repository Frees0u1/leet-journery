#include <iostream>
#include <algorithm>
#include <unordered_set>
using namespace std;

class Solution {
public:
  bool isHappy(int n) {
    return isHappy(n, true);
  }
private:
  bool isHappy(int n, bool isFirstTime) {
    if (isFirstTime) occured.clear();
    if (n <= 0) return false;
    if (n == 1) return true;
    if (occured.find(n) != occured.end()) return false;
    occured.insert(n);

    return isHappy(getSquareSum(n), false);
  }


  int getSquareSum(int n) {
    int result = 0;

    while (n) {
      // printf("n = %d\n", n);
      int remain = n % 10;
      n /= 10;
      result += remain * remain;
    }

    return result;
  }

  unordered_set<int> occured;
};

int main() {
  Solution sol;
  int n;
  cin >> n;
  cout << sol.isHappy(n) << endl;
  return 0;
}