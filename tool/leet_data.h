#pragma once
#include <iostream>
#include <map>
#include <set>
#include <string>
#include <stdexcept>
#include <sstream>

namespace leet
{
    template <typename T>
    struct ListNode
    {
        T val;
        ListNode *next;
        ListNode(T x) : val(x), next(nullptr) {}
    };

    template <typename T>
    struct TreeNode
    {
        T val;
        TreeNode *left;
        TreeNode *right;
        TreeNode(T val) : val(val), left(nullptr), right(nullptr) {}
    };

    template <typename T>
    class PolyTreeNode
    {
    public:
        T val;
        std::map<T, PolyTreeNode *> children;
        PolyTreeNode<T>(T val) : val(val) {}
        template <typename U>
        friend std::ostream& operator<<(std::ostream& os, const PolyTreeNode<U>& node);

        static void destoryRecursive(PolyTreeNode<T> *root)
        {
            if (root)
            {
                for (std::pair<T, PolyTreeNode *> pr : root->children)
                {
                    delete pr.second;
                }

                delete root;
            }
        }

        void addChild(PolyTreeNode<T> *child)
        {
            if (child == nullptr)
                return;
            if(children.find(child->val) != children.end()) {
                std::stringstream ss;
                ss << "child " << *child << " already exist!";
                throw std::runtime_error(ss.str());
            }
            children[child->val] = child;
        }

        void print()
        {
            std::set<int> hasSublingDepths;
            print(this, 0, hasSublingDepths, true);
        }

    private:
        const std::string INDENT = "    ";
        const std::string INDENT_DEFAULT = "├── ";
        const std::string INDENT_END = "└── ";
        const std::string INDENT_SUBLING = "│   ";        

        void print(PolyTreeNode<T> *node, int depth, std::set<int> &hasSublingDepths, bool isLastOne)
        {
            if (node == nullptr)
            {
                return;
            }

            for (int i = 0; i < depth - 1; i++)
            {
                std::string prefixUnit = (hasSublingDepths.find(i) != hasSublingDepths.end())
                                             ? INDENT_SUBLING
                                             : INDENT;
                std::cout << prefixUnit;
            }

            std::string prefix = depth > 0
                                     ? (isLastOne) ? INDENT_END : INDENT_DEFAULT
                                     : "";
            std::cout << prefix + node->val << std::endl;

            int i = 0;
            hasSublingDepths.insert(depth);
            for (auto iter = node->children.begin(); iter != node->children.end(); iter++)
            {
                bool isLastOne = i++ >= node->children.size() - 1;
                if (isLastOne)
                    hasSublingDepths.erase(depth);
                print(iter->second, depth + 1, hasSublingDepths, isLastOne);
            }
        }
    };

    template <typename T>
    std::ostream& operator<<(std::ostream& os, const PolyTreeNode<T>& node)
    {
        os << "[" << node.val << "," << &node << "]";
        return os;
    }
} // namespace air
