#include <iostream>
#include <algorithm>
#include <string>
#include <stack>
#include <vector>
#include "../tool/leet_tool.h"
using namespace std;

class Solution {
public:
  int calculate(const string& expr) {
    string refinedExpr = preprocess(expr);
    if (refinedExpr == "") return 0;
    stack<int> oprands;
    stack<char> operators;

    int right = refinedExpr.size() - 1, left = right;
    while (right >= 0) {
      left = right;
      bool isTier0Expr = false;
      while (left >= 0) {
        if (refinedExpr[left] == '+' || refinedExpr[left] == '-') {
          operators.push(refinedExpr[left]);
          break;
        }
        if (refinedExpr[left] == '*' || refinedExpr[left] == '/') isTier0Expr = true;
        left--;
      }

      if (isTier0Expr) {
        oprands.push(calcTier0Expr(refinedExpr.substr(left + 1, right - left)));
      }
      else {
        oprands.push(stoi(refinedExpr.substr(left + 1, right - left)));
      }


      right = left - 1;
    }

    return doCalc(oprands, operators);
  }

  string preprocess(string expr) {
    string result = "";
    for (char c : expr) {
      if (c == ' ' || c == '\t' || c == '\r' || c == '\n') continue;
      result.push_back(c);
    }
    return result;
  }

  int calcTier0Expr(const string& expr) {
    int right = expr.size() - 1, left = right;
    stack<int> oprands;
    stack<char> ops;
    while (right >= 0) {
      left = right;
      while (left >= 0) {
        if (expr[left] == '*' || expr[left] == '/') {
          ops.push(expr[left]);
          break;
        }
        left--;
      }

      oprands.push(stoi(expr.substr(left + 1, right - left)));
      right = left - 1;
    }

    return doCalc(oprands, ops);
  }

  int doCalc(stack<int>& oprands, stack<char>& ops) {
    while (!ops.empty()) {
      char op = ops.top(); ops.pop();
      int lhs = oprands.top(); oprands.pop();
      int rhs = oprands.top(); oprands.pop();
      oprands.push(doCalc(op, lhs, rhs));
    }

    return oprands.top();
  }

  int doCalc(char op, int lhs, int rhs) {
    switch (op) {
    case '+': return lhs + rhs;
    case '-': return lhs - rhs;
    case '*': return lhs * rhs;
    case '/': return lhs / rhs;
    default: throw "invalid op";
    }
  }
};

class Solution2 {
public:
  int calculate(string expr) {
    stack<int> oprands;
    stack<int> operators;
    int curNum = 0;
    for (int i = 0; i < expr.length(); i++) {
      char c = expr[i];
      if (c >= '0' && c <= '9') {
        curNum = curNum * 10 + c - '0';
      }
      if (i == expr.length() - 1 || isOperator(c)) {
        char lastOperator = operators.top(); operators.pop();
        switch (lastOperator) {

        }
      }
    }
  }
private:
  bool isOperator(char c) {
    return c == '+' || c == '-' || c == '*' || c == '/';
  }
}

int main() {
  Solution sol;
  string expression;
  while (cin >> expression) {
    cout << expression << " = " << sol.calculate(expression) << endl;
  }
  return 0;
}