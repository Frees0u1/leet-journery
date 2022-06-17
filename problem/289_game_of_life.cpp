#include <iostream>
#include <algorithm>
#include <vector>
#include "../tool/leet_tool.h"
using namespace std;

// 0 -> -1; back to life
// 1 -> 2; // died

// current died: -1, 0
// current live: 1, 2

class Solution {
public:
  int gameOfLife(vector<vector<int>>& board) {
      int m = board.size(); if(m == 0) return 0;
      int n = board[0].size(); if(n == 0) return 0;
      
      for(int i = 0; i < m; i++) {
        for(int j = 0; j < n; j++) {
          int liveCount = 0;
          for(int x = max(0, i - 1); x < min(m, i + 2); x++) {
            for(int y = max(0, j - 1); y < min(n, j + 2); y++) {
              if(x == i && y == j) continue;
              liveCount += (board[x][y] >= 1);
            }
          }

          if(board[i][j] == 0) { //curent died
            if(liveCount == 3) board[i][j] = -1;
          } else { // current live
            if(liveCount < 2 || liveCount >= 4) board[i][j] = 2;
          }
        }
      }

      int flipCount = 0;
      for(int i = 0; i < m; i++) {
        for(int j = 0; j < n; j++) {
          if(board[i][j] == -1) { 
            board[i][j] = 1;
            flipCount++;
          }
          if(board[i][j] == 2) { 
            board[i][j] = 0;
            flipCount++;
          }
        }
      }

      return flipCount;
  }
};

int main() {
  vector<vector<int>> board{
    {0,0,0,0,0,0},
    {0,0,0,0,0,0}, 
    {0,0,1,1,1,0}, 
    {0,1,1,1,0,0},
    {0,0,0,0,0,0},
    {0,0,0,0,0,0}
  };

  Solution sol;
  for(int i = 0; i < 10001; i++) {
    system("clear");
    if(sol.gameOfLife(board) == 0) break;
    leet::printArray(board);
  }
  
  return 0;
}