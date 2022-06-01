#include <string>
#include <unordered_map>
#include <vector>
#include <queue>
#include <unordered_set>
#include <iostream>
#include "../tool/leet_tool.h"
using namespace std;

class Solution {
public:
    int ladderLength(string beginWord, string endWord, vector<string>& wordList) {
      if(beginWord == endWord) return 0;
      unordered_map<string, unordered_set<string>> G;
      int N = wordList.size();
      for(int i = -1; i < N; i++) {
        for(int j = i + 1; j <= N; j++) {
          string& lhs = (i == -1) ? beginWord : wordList[i];
          string& rhs = (j == N) ? endWord : wordList[j];

          if(hasPath(lhs, rhs)) {
            G[lhs].insert(rhs);
            G[rhs].insert(lhs);
          }
        }
      }

      // printf("Graph size = %d\n", G.size());
      // for(auto p : G) {
      //   cout << p.first << " ";
      //   for(string i : p.second) {
      //     cout << i << ", ";
      //   }
      //   cout << endl;
      // }

      // bfs
      queue<pair<string, int>> que;
      unordered_set<string> visited;
      que.push(make_pair(beginWord, 1));
      visited.insert(beginWord);
      while(!que.empty()) {
        string cur = que.front().first;
        int step = que.front().second;
        que.pop();
        if(cur == endWord) return step;

        for(string nbr : G[cur]) {
          if(visited.find(nbr) == visited.end()) {
            que.push(make_pair(nbr, step + 1));
            visited.insert(nbr);
          }
        }

        step++;
      }

      return -1;
    }

  bool hasPath(const string& lhs, const string& rhs) {
    if(lhs.size() != rhs.size()) return false;
    int diff = 0;
    
    for(int i = 0; i < lhs.size(); i++) {
      if(lhs[i] != rhs[i]) diff++;
      if(diff > 1) return false;
    }

    return diff == 1;
  }

  string getWord(int i, string beginWord, string endWord, vector<string>& wordList) {
    if (i == -1) return beginWord;
    if (i == wordList.size()) return endWord;
    return wordList[i];
  }
};

int main() {
  string beginWord = "hit";
  string endWord = "cog";
  vector<string> wordList{"hot","dot","dog","lot","log"};
  Solution sol;
  cout << sol.ladderLength(beginWord, endWord, wordList) << endl;
}