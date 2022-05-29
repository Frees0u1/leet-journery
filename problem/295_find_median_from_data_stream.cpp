#include <iostream>
#include <algorithm>
#include <queue>
#include <vector>
#include <optional>
using namespace std;

class MedianFinder {
public:
    MedianFinder() {        
    }
    
    void addNum(int num) {
        left.push(num);
        reBalance();
    }
    
    double findMedian() {
      if(left.size() == 0 && right.size() == 0) {
        return -1;
      }

      if(left.size() == right.size()) {
        return (left.top() + right.top()) / 2.0;
      }

      return left.top();
    }
private:
  priority_queue<int> left;
  priority_queue<int, vector<int>, greater<int> > right;

  void reBalance() {
    
    if(left.size() > 0 && right.size() > 0 && left.top() > right.top()) {
      int l = left.top(), r = right.top();
      left.pop(); right.pop();
      right.push(l),left.push(r);
    }

    if(left.size() - right.size() == 2 ) {
      right.push(left.top());
      left.pop();
    }
  }
};

/**
 * Your MedianFinder object will be instantiated and called as such:
 * MedianFinder* obj = new MedianFinder();
 * obj->addNum(num);
 * double param_2 = obj->findMedian();
 */

int main(int argc, char const *argv[])
{
  MedianFinder* obj = new MedianFinder();
  obj->addNum(1);
  double param_2 = obj->findMedian();
}
