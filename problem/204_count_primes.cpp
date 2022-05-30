#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

class Solution {
public:
  int countPrimes(int n) {
    if (n < 2) return 0;
    vector<bool> numbers(n + 1, true);
    int primeCount = 0;
    for (int i = 2; i < n; i++) {
      if (!numbers[i]) continue;

      primeCount++;
      for (int factor = 2; factor * i < n; factor++) {
        numbers[factor * i] = false;
      }
    }

    return primeCount;
  }
};

int main() {
  Solution sol;
  int n;
  cin >> n;
  cout << sol.countPrimes(n) << endl;
  return 0;
}