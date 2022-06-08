#include <iostream>
#include <algorithm>
#include <unordered_map>
#include <unordered_set>
#include <queue>
#include "../tool/leet_tool.h"
using namespace std;

class Solution {
public:
  vector<double> calcEquation(vector<vector<string>>& equations, vector<double>& values, vector<vector<string>>& queries) {
    buildGraph(equations, values);
    vector<double> result;
    for (auto& query : queries) {
      result.push_back(calc(query[0], query[1]));
    }

    return result;
  }

private:
  unordered_map<string, vector<pair<string, double>>> G;

  void buildGraph(const vector<vector<string>>& equations, const vector<double>& values) {
    G.clear();
    for (int i = 0; i < equations.size(); i++) {
      string lhs = equations[i][0];
      string rhs = equations[i][1];

      G[lhs].push_back(make_pair(rhs, values[i]));
      G[rhs].push_back(make_pair(lhs, 1.0 / values[i]));
    }
  }

  double calc(const string& lhs, const string& rhs) {
    if (G.find(rhs) == G.end()) return -1.0;
    if (lhs == rhs) return 1;

    queue<pair<string, double>> que;
    unordered_set<string> visited;
    que.push(make_pair(lhs, 1.0));
    visited.insert(lhs);
    while (!que.empty()) {
      string cur = que.front().first;
      double val = que.front().second;
      printf("lhs=%s, rhs=%s, cur=%s\n", lhs.c_str(), rhs.c_str(), cur.c_str());
      que.pop();
      if (cur == rhs) return val;
      for (pair<string, double>& p : G[cur]) {
        if (visited.find(p.first) == visited.end()) {
          que.push(make_pair(p.first, p.second * val));
          visited.insert(p.first);
        }
      }
    }

    return -1.0;
  }
};

int main() {
  Solution sol;
  vector<vector<string>> equations{
    {"a", "b"},
    {"c", "d"},
  };
  vector<double> values{
    1.0, 1.0
  };
  vector<vector<string>> queries{
  {"a", "c"},
  {"b", "d"},
  {"b", "a"},
  {"d", "c"}
  };

  leet::printArray(sol.calcEquation(equations, values, queries));
  return 0;
}