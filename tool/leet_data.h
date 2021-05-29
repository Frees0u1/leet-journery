#pragma once

namespace leet
{
    struct ListNode {
        int val;
        ListNode *next;
        ListNode(int x = 0) : val(x), next(nullptr) {}
        ListNode(int x, ListNode *next) : val(x), next(next) {}
    };
} // namespace leetdata
