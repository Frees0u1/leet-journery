#include <iostream>
using namespace std;

class Solution {
public:
  ~Solution() {
    std::cout << "destructor called!" << std::endl;
  }
  Solution(const Solution&) = delete;
  Solution& operator=(const Solution&) = delete;

  /**
   * @return: The same instance of this class every time
   */
   // works in c++11
  static Solution* getInstance() {
    static Solution* solution = new Solution;
    return solution;
  }

private:
  Solution() {
    std::cout << "constructor called!" << std::endl;
  }
};

int main() {
  Solution* instance1 = Solution::getInstance();
  Solution* instance2 = Solution::getInstance();
  cout << (instance1 == instance2) << endl;
  cout << instance1 << endl;
}