#include <iostream>
#include <algorithm>
#include <bitset>
using namespace std;

class Solution {
public:
    uint32_t reverseBits(uint32_t n) {
        uint32_t result = 0;
        cout << bitset<32>(n) << endl;
        cout << "=============================" << endl;
        for(int i = 0; i < 32; i++) {
          uint32_t tmp = ((n >> i) & 1) << (32 - i - 1);
          cout << i << endl;
          cout << bitset<32>(n >> i) << endl;
          cout << bitset<32>(tmp) << endl;
          result = result | tmp;
          cout << bitset<32>(result) << endl;
          cout << "=============================" << endl;
        }

        return result;
    }
};

int main() {
  Solution sol;
  sol.reverseBits(43261596);

  return 0;
}