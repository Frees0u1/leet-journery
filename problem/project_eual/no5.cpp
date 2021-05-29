/*
Smallest multiple
2520 is the smallest number that can be divided by each of the numbers from 1 to 10 without any remainder.

What is the smallest positive number that is evenly divisible by all of the numbers from 1 to 20?
*/

#include <iostream>
#include "../../tool/leet_data.h"
#include "../../tool/leet_tool.h"
#include <vector>
#include <algorithm>
#include <cmath>
using namespace leet;
using namespace std;

class Solution {
public:
  void trial_divisio_fac(long long n, vector<int>& primeCount) {
    long long a = 2;
    vector<int> selfPrimeCount(21, -1);
    for (auto p : PRIMES) {
      selfPrimeCount[p] = 0;
    }
    while (a * a <= n) {
      while (n % a == 0) {
        selfPrimeCount[a]++;
        n /= a;
      }

      a = a + 1;
    }

    if (n > 1)
      selfPrimeCount[n]++;;

    for (int i = 0; i < primeCount.size(); i++) {
      primeCount[i] = max(primeCount[i], selfPrimeCount[i]);
    }
  }

  long long solve(int n) {
    vector<int> primeCount(21, -1);
    for (auto p : PRIMES) {
      primeCount[p] = 0;
    }

    for (int i = 2; i <= n; i++) {
      trial_divisio_fac(i, primeCount);
      printArrayWithIndex(primeCount);
    }

    long long result = 1;
    for (int i = 0; i < primeCount.size(); i++) {
      if (primeCount[i] > 0) result *= pow(i, primeCount[i]);
    }

    return result;
  }
private:
  const vector<int> PRIMES{ 2, 3, 5, 7, 11, 13, 17, 19 };
};

int main() {
  Solution sol;
  cout << sol.solve(20) << endl;
  return 0;
}
