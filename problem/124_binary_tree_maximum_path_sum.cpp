#include <iostream>
#include <algorithm>
using namespace std;

class Solution {
public:
  int maxPathSum(TreeNode<int>* root) {
    int result = INT_MIN;
    maxLength(root, result);
    return result;
  }
private:
  int maxLength(TreeNode<int>* root, int& result) {
    if (root == nullptr) return 0;
    int leftMaxLength = max(0, maxLength(root->left, result));
    int rightMaxLength = max(0, maxLength(root->right, result));
    result = max(result, leftMaxLength + rightMaxLength + root->val);
    return max(leftMaxLength, rightMaxLength) + root->val;
  }
};

int main() {
  Solution sol;
  return 0;
}
