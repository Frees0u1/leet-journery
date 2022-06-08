#include <iostream>
#include <map>
#include <string>
#include <vector>
#include <set>
#include <unordered_set>
#include <algorithm>
#include <queue>
#include "../tool/leet_tool.h"
using namespace std;

class Solution
{
public:
  vector<string> findItinerary(const vector<vector<string>> &tickets)
  {
    buildGraph(tickets);
    vector<string> path;
    dfs(path, "JFK");
    return vector<string>(path.rbegin(), path.rend());
  }

private:
  void dfs(vector<string>& path, string cur) {
    while(!G[cur].empty()) {
      string next = G[cur].top();
      G[cur].pop();
      dfs(path, next);
    }

    path.push_back(cur);
  }

  void buildGraph(const vector<vector<string>> &tickets) {
    G.clear();

    for (auto &ticket : tickets) {
      G[ticket[0]].emplace(ticket[1]);
    }
  }

  map<string, priority_queue<string, vector<string>, greater<string>>> G;
};

int main()
{
  Solution sol;
  vector<vector<string>> tickets{
      {"JFK", "SFO"},
      {"JFK", "ATL"},
      {"SFO", "ATL"},
      {"ATL", "JFK"},
      {"ATL", "SFO"}};

  leet::printArray(sol.findItinerary(tickets));
  return 0;
}