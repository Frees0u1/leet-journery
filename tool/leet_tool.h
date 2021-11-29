#include "leet_data.h"
#include <iostream>
#include <vector>
#include <string>

namespace leet{
    template<typename T>
    void printList(ListNode<T>* l) {
        while (l != nullptr)
        {
            std::cout << l -> val << " -> ";
            l = l->next;
        }
        
       std::cout << "nullptr" << std::endl;
    }
    
    template <typename T>
    void printArray(const std::vector<T>& array, std::string seperator = " ") {
        for(auto x : array) {
            std::cout << x << seperator;
        }
        std::cout << std::endl;
    }

    template <typename T>
    void printArray(const std::vector<std::vector<T>>& array) {
        for(auto x : array) {
            printArray(x);
        }
    }

    class UnionSet {
    public:
        UnionSet (int n) {
            for(int i = 0; i < n; i++) {
                root.push_back(i);
            }
        }

        int getRoot(int x) {
            if(root[x] == x) return x;
            return root[x] = getRoot(root[x]);
        }

        void unite(int x, int y) {
            root[getRoot(x)] = getRoot(y);
        }

        bool isSameRoot(int x, int y) {
            return getRoot(x) == getRoot(y);
        }

    private:
        std::vector<int> root;
    };
} // end of namespace air
