#include <iostream>
#include <vector>
#include <unordered_set>
#include "../../tool/leet_tool.h"
using namespace std;

int dfs(int i, int x, vector<int>& sol, unordered_set<int>& cols, unordered_set<int>& rcSums, unordered_set<int>& rcDiffs) {
  if (i >= x) {
    leet::printArray(sol);
    return 1;
  }

  int solCount = 0;
  for (int j = 0; j < x; j++) {
    int rcSum = i + j;
    int rcDiff = i - j;
    if (cols.find(j) == cols.end() &&
      rcSums.find(rcSum) == rcSums.end() &&
      rcDiffs.find(rcDiff) == rcDiffs.end()) {
      sol.push_back(j);
      cols.insert(j);
      rcSums.insert(rcSum);
      rcDiffs.insert(rcDiff);

      solCount += dfs(i + 1, x, sol, cols, rcSums, rcDiffs);

      sol.pop_back();
      cols.erase(j);
      rcSums.erase(rcSum);
      rcDiffs.erase(rcDiff);
    }
  }

  return solCount;
}

int xqueen(int x) {
  if (x <= 1) return x;
  vector<int> sol;
  unordered_set<int> cols;
  unordered_set<int> rcSums;
  unordered_set<int> rcDiffs;
  return dfs(0, x, sol, cols, rcSums, rcDiffs);
}

int main(int argc, char const* argv[])
{
  int x;
  cin >> x;
  printf("x = %d, total solution:%d\n", x, xqueen(x));
  return 0;
}
