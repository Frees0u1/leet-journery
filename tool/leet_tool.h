#include "leet_data.h"
#include <iostream>

namespace leet{
    void printList(ListNode* l) {
        while (l != nullptr)
        {
            std::cout << l -> val << " -> ";
            l = l->next;
        }
        
       std::cout << "nullptr" << std::endl;
    }    
}