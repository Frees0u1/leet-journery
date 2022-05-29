#include <iostream>
#include <vector>
#include <queue>
#include <utility>
#include <cassert>
using namespace std;

#define ID(I, J, N) ((I * N) + J)

class UnionSet {
public:
  UnionSet(int m, int n) : m(m), n(n) {
    root.clear();
    root.resize(m, vector<int>(n, 0));
    for (int i = 0; i < m; i++) {
      for (int j = 0; j < n; j++) {
        root[i][j] = id(i, j);
      }
    }
  }

  int find(int id) {
    int i = getI(id);
    int j = getJ(id);
    if (root[i][j] == id) return id;


    return find(root[i][j]);
  }

  // unite (x, y) => (i, j)
  void unite(int i, int j, int x, int y) {
    root[i][j] = find(ID(x, y, n));
  }

private:
  int m, n;
  vector<vector<int>> root;

  inline int id(int i, int j) {
    return i * n + j;
  }

  inline int getI(int id) {
    return id / n;
  }

  inline int getJ(int id) {
    return id % n;
  }
};

class Solution {
public:
  int trapRainWater(vector<vector<int>>& heightMap) {

    int m = heightMap.size();
    if (m < 2) return 0;
    int n = heightMap[0].size();
    if (n < 2) return 0;
    vector<vector<int>> minNbr(m, vector<int>(n, -1));

    // bfs
    vector<vector<bool>> visited(m, vector<bool>(n, false));
    queue<pair<int, int>> que;
    for (int i = 0; i < m; i++) {
      for (int j = 0; j < n; j++) {
        if (minNbr[i][j] != -1) continue;

        assert(que.empty());
        que.push(make_pair(i, j));
        while (!que.empty()) {
          int x = que.front().first;
          int y = que.front().second;
          if (visited[x][y]) continue;
          que.pop();
          visited[x][y] = true;

          // do something for cur node

          for (int k = 0; k < dx.size(); k++) {
            int x1 = x + dx[k];
            int y1 = y + dy[k];

            if (isValid(i, j, m, n) && heightMap[x1][y1] <= heightMap[x][y])
              que.push(make_pair(x1, y1));
          }
        }
      }
    }
  }
private:
  const vector<int> dx{ 1, 1, -1, -1 };
  const vector<int> dy{ 1, -1, -1, 1 };

  bool isValid(int i, int j, int m, int n) {
    return i >= 0 && i < m&& j >= 0 && j < n;
  }
};

int main() {
  Solution sol;
  return 0;
}