/**
 * You are given two non-empty linked lists representing two non-negative integers. The digits are stored in reverse order, and each of their nodes contains a single digit. Add the two numbers and return the sum as a linked list.
    You may assume the two numbers do not contain any leading zero, except the number 0 itself.

Example 1:
Input: l1 = [2,4,3], l2 = [5,6,4]
Output: [7,0,8]
Explanation: 342 + 465 = 807.
Example 2:

Input: l1 = [0], l2 = [0]
Output: [0]
Example 3:

Input: l1 = [9,9,9,9,9,9,9], l2 = [9,9,9,9]
Output: [8,9,9,9,0,0,0,1]

 * 
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */

#include "../tool/leet_data.h"
#include "../tool/leet_tool.h"
#include <iostream>
using namespace leet;
using namespace std;

class Solution {
public:
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        int carry = 0;
        ListNode dummyNode;
        ListNode* cur = &dummyNode;
        while(l1 != nullptr || l2 != nullptr || carry != 0) {
            int sum = curValue(l1) + curValue(l2) + carry;
            int remainder = sum % 10;
            carry = sum / 10;
            
            cur -> next = new ListNode(remainder);;
            cur = cur->next;
            l1 = toNext(l1);
            l2 = toNext(l2);
        }
        
        return dummyNode.next;
    }
    
private:
    int curValue(ListNode* l) {
        if(l == nullptr) return 0;
        return l->val;
    }
    
    ListNode* toNext(ListNode* l) {
        if(l == nullptr) return l;
        return l -> next;
    }
};

int main()
{
    Solution sol;
    ListNode n11(9);
    ListNode n12(9);
    ListNode n13(9);
    n11.next = &n12; n12.next = &n13;

    ListNode n21(9);
    ListNode n22(9);
    n21.next = &n22;

    cout << "l1: "; printList(&n11);
    cout << "l2: "; printList(&n21);

    cout << "l1 + l2: "; 
    ListNode* result = sol.addTwoNumbers(&n11, &n21);
    printList(result);

    return 0;
}
