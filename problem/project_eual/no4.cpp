/*
Largest palindrome product
Problem 4
A palindromic number reads the same both ways. The largest palindrome made from the product of two 2-digit numbers is 9009 = 91 × 99.

Find the largest palindrome made from the product of two 3-digit numbers.
*/

#include <iostream>
#include <string>
#include <algorithm>
using namespace std;

bool isPalindromeNumber(int number) {
  string numStr = to_string(number);
  int i = 0, j = numStr.size() - 1;
  while(i < j) {
    if(numStr[i++] != numStr[j--]) {
      return false;
    }
  }

  return true;
}

int solve_bruceforce() {
  int maxResult = -1;
  for(int i = 999; i >= 100; i--) {
    for(int j = 999; j >= 100; j--) {
      if (isPalindromeNumber(i * j)) { 
        //cout << i << "*" << j << " = "; 
        //return i * j;
        cout << i << "*" << j << " = " << i*j << endl;
        maxResult = max(i*j, maxResult);
      }
    }
  }

  return maxResult;
}


/*
  let's assume that the bigest one is a 6 digit number: abccba
  abccba = a*100000 + b*10000 + c*1000 + c*100 + b*10 + a
         = a*100001 + b*10010 + c*1100
         = 11（a*9091 + b*910 + c*100）
  thus, one of the number must be division by 11!
*/

int solve_by_less_check() {
   int maxResult = -1;
  for(int i = 999; i >= 100; i--) {
    for(int j = 999; j >= 100; j--) {
       if(i < j) continue;
      if(i % 11 != 0 && j % 11 != 0) continue;     
      int product = i * j;
      if(product < 100000) return maxResult;

      if (isPalindromeNumber(product)) {
        cout << i << "*" << j << " = " << product << endl;
        maxResult = max(product, maxResult);
      }
    }
  }

  return maxResult;
}

int main() {
  cout << solve_by_less_check() << endl; 
}
