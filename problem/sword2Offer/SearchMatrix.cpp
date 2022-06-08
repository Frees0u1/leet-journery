#include <iostream>
#include <vector>
#include <algorithm>
#include <map>
using namespace std;

class Solution {
public:
  /**
   * @param matrix: A list of lists of integers
   * @param target: An integer you want to search in matrix
   * @return: An integer indicate the total occurrence of target in the given matrix
   */
  int searchMatrix(vector<vector<int>>& matrix, int target) {
    int m = matrix.size(); if (m == 0) return 0;
    int n = matrix[0].size(); if (n == 0) return 0;
    return helper(matrix, target, 0, 0, m - 1, n - 1);
  }

  int helper(const vector<vector<int>>& matrix, int target, int i, int j, int x, int y) {
    printf("(%d, %d) => (%d, %d)\n", i, j, x, y);
    if (i > x || j > y) return 0;
    if (x == i && y == j) return matrix[i][j] == target;

    int midx = (i + x) / 2;
    int midy = (j + y) / 2;

    if (x == i) {
      if (matrix[midx][midy] == target) {
        return 1;
      }
      else if (matrix[midx][midy] < target) {
        return helper(matrix, target, i, midy + 1, x, y);
      }
      else {
        return helper(matrix, target, i, j, i, midy - 1);
      }
    }
    else if (y == j) {
      if (matrix[midx][midy] == target) {
        return 1;
      }
      else if (matrix[midx][midy] < target) {
        return helper(matrix, target, midx + 1, midy, x, y);
      }
      else {
        return helper(matrix, target, i, j, midx - 1, midy);
      }
    }

    if (matrix[midx][midy] == target) {
      return helper(matrix, target, midx, j, x, midy) +
        helper(matrix, target, i, midy, midx, j) - 1;
    }
    else if (matrix[midx][midy] < target) {
      return helper(matrix, target, midx, j, x, midy) +
        helper(matrix, target, i, midy, midx, y) +
        helper(matrix, target, midx + 1, midy + 1, x, y);
    }
    else {
      return helper(matrix, target, i, j, midx, midy);
    }
  }
};

/*
* 从右上角到左下角 单调线性遍历
*/
class Solution2 {
public:
  int searchMatrix(vector<vector<int>>& matrix, int target) {
    int m = matrix.size(); if (m == 0) return 0;
    int n = matrix[0].size(); if (n == 0) return 0;
    int i = 0, j = n - 1;
    int count = 0;
    while (i >= 0 && j >= 0 && i < m && j < n) {
      if (matrix[i][j] == target) {
        count++;
        i++; j--;
      }
      else if (matrix[i][j] > target) {
        j--;
      }
      else { // < target
        i++;
      }
    }

    return count;
  }
};

int main() {
  Solution sol;
  vector<vector<int>> matrix{
    {1}, {2}, {3}
  };
  cout << sol.searchMatrix(matrix, 100) << endl;
}