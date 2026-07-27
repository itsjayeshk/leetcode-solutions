#pragma once

// Solution files in this repository are raw LeetCode submissions: they contain
// only `class Solution` and rely on the headers, `using namespace std;` and the
// node definitions that the LeetCode judge injects. This header reproduces that
// environment so a solution file can be `#include`d straight into a test.

#include <algorithm>
#include <array>
#include <bitset>
#include <climits>
#include <cmath>
#include <cstdint>
#include <cstdlib>
#include <cstring>
#include <deque>
#include <functional>
#include <iostream>
#include <iterator>
#include <limits>
#include <map>
#include <numeric>
#include <optional>
#include <queue>
#include <set>
#include <sstream>
#include <stack>
#include <string>
#include <unordered_map>
#include <unordered_set>
#include <utility>
#include <vector>

using namespace std;

struct ListNode {
    int val;
    ListNode* next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode* next) : val(x), next(next) {}
};

struct TreeNode {
    int val;
    TreeNode* left;
    TreeNode* right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode* left, TreeNode* right) : val(x), left(left), right(right) {}
};

namespace lctest {

// A level-order tree slot: `nullopt` is LeetCode's `null`.
using Slot = std::optional<int>;

inline ListNode* makeList(const std::vector<int>& values) {
    ListNode head;
    ListNode* tail = &head;
    for (int v : values) {
        tail->next = new ListNode(v);
        tail = tail->next;
    }
    return head.next;
}

inline std::vector<int> listToVector(const ListNode* head) {
    std::vector<int> out;
    for (const ListNode* node = head; node != nullptr; node = node->next) {
        out.push_back(node->val);
    }
    return out;
}

inline ListNode* nodeAt(ListNode* head, std::size_t index) {
    while (head != nullptr && index-- > 0) {
        head = head->next;
    }
    return head;
}

inline void freeList(ListNode* head) {
    while (head != nullptr) {
        ListNode* next = head->next;
        delete head;
        head = next;
    }
}

// Builds a tree from a LeetCode level-order array, e.g. {3, 9, 20, nullopt, nullopt, 15, 7}.
inline TreeNode* makeTree(const std::vector<Slot>& values) {
    if (values.empty() || !values[0].has_value()) {
        return nullptr;
    }
    TreeNode* root = new TreeNode(*values[0]);
    std::queue<TreeNode*> pending;
    pending.push(root);
    std::size_t i = 1;
    while (!pending.empty() && i < values.size()) {
        TreeNode* node = pending.front();
        pending.pop();
        if (i < values.size()) {
            if (values[i].has_value()) {
                node->left = new TreeNode(*values[i]);
                pending.push(node->left);
            }
            i++;
        }
        if (i < values.size()) {
            if (values[i].has_value()) {
                node->right = new TreeNode(*values[i]);
                pending.push(node->right);
            }
            i++;
        }
    }
    return root;
}

// Serializes a tree back to a level-order array with trailing nulls trimmed.
inline std::vector<Slot> treeToVector(const TreeNode* root) {
    std::vector<Slot> out;
    if (root == nullptr) {
        return out;
    }
    std::queue<const TreeNode*> pending;
    pending.push(root);
    while (!pending.empty()) {
        const TreeNode* node = pending.front();
        pending.pop();
        if (node == nullptr) {
            out.push_back(std::nullopt);
            continue;
        }
        out.push_back(node->val);
        pending.push(node->left);
        pending.push(node->right);
    }
    while (!out.empty() && !out.back().has_value()) {
        out.pop_back();
    }
    return out;
}

inline void freeTree(TreeNode* root) {
    if (root == nullptr) {
        return;
    }
    freeTree(root->left);
    freeTree(root->right);
    delete root;
}

// Owns a tree for the duration of a test so assertions can bail out safely.
class TreeGuard {
public:
    explicit TreeGuard(const std::vector<Slot>& values) : root_(makeTree(values)) {}
    TreeGuard(const TreeGuard&) = delete;
    TreeGuard& operator=(const TreeGuard&) = delete;
    ~TreeGuard() { freeTree(root_); }

    TreeNode* get() const { return root_; }
    void release() { root_ = nullptr; }

private:
    TreeNode* root_;
};

// Owns a list for the duration of a test. `release()` hands ownership back when
// a solution rewires or deletes nodes itself.
class ListGuard {
public:
    explicit ListGuard(const std::vector<int>& values) : head_(makeList(values)) {}
    ListGuard(const ListGuard&) = delete;
    ListGuard& operator=(const ListGuard&) = delete;
    ~ListGuard() { freeList(head_); }

    ListNode* get() const { return head_; }
    void release() { head_ = nullptr; }

private:
    ListNode* head_;
};

}  // namespace lctest
