#include <iostream>
#include <algorithm>
#include <unordered_map>
#include <utility>
#include <stack>
#include "../tool/leet_data.h"
using namespace std;
using namespace leet;

class Solution {
public:
  int kthSmallest(TreeNode<int>* root, int k) {
    TreeNode<int>* result = nullptr;
    dfs(root,k, result);
    if(result != nullptr) return result->val;
    
    return -1;
  }
private:
  int dfs(TreeNode<int>* root, int k, TreeNode<int>*& kthNode) {
    if(root == nullptr) return 0;
    int leftSize = dfs(root->left, k, kthNode);
    if(kthNode != nullptr) return leftSize;
    if(leftSize == k - 1) {
      kthNode = root;
      return leftSize;
    }

    int rightSize = dfs(root->right, k - leftSize - 1, kthNode);
    return leftSize + rightSize + 1;
  }
};

class Solution2 {
public:
  int kthSmallest(TreeNode<int>* root, int k) {
    stack<TreeNode<int>* > S;
    TreeNode<int> *cur = root;
    int curPos = 1;
    while(true){
        while(cur){
            S.push(cur); cur = cur->left;
        }
        if(S.empty()) break;

        cur = S.top();
        if(curPos++ == k) return cur -> val;
        S.pop();
        cur = cur->right;
    }

    return -1;
  }
};


int main() {
  Solution sol;
  return 0;
}