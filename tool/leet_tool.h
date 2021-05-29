#include "leet_data.h"
#include <iostream>
#include <vector>

namespace leet {
  void printList(ListNode* l) {
    while (l != nullptr)
    {
      std::cout << l->val << " -> ";
      l = l->next;
    }

    std::cout << "nullptr" << std::endl;
  }

  template <typename T>
  void printArray(const std::vector<T>& array) {
    for (auto x : array) {
      std::cout << x << " ";
    }
    std::cout << std::endl;
  }

  template <typename T>
  void printArrayWithIndex(const std::vector<T>& array) {
    for (int i = 0; i < array.size(); i++) {
      printf("(%d, %d) ", i, array[i]);
    }
    std::cout << std::endl;
  }

  template <typename T>
  void printArray(const std::vector<std::vector<T>>& array) {
    for (auto x : array) {
      printArray(x);
    }
  }
}