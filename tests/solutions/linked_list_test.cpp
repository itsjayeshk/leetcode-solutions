#include "support/lc_test.hpp"

namespace lc0237 {
#include "0237-delete-node-in-a-linked-list/0237-delete-node-in-a-linked-list.cpp"
}
namespace lc21 {
#include "lc21_merge_2_linked_list.cpp"
}
namespace lc141 {
#include "lc141_linked_list_cycle.cpp"
}
namespace lc206 {
#include "lc206_reverse_linked_list.cpp"
}
namespace lc876 {
#include "lc876_middle_of_linked_list.cpp"
}

using lctest::freeList;
using lctest::listToVector;
using lctest::ListGuard;
using lctest::makeList;
using lctest::nodeAt;

LC_TEST(lc0237_delete_node_in_a_linked_list, overwrites_node_with_successor) {
    lc0237::Solution s;
    ListGuard list({4, 5, 1, 9});
    ListNode* orphaned = nodeAt(list.get(), 2);
    s.deleteNode(nodeAt(list.get(), 1));
    LC_EXPECT_EQ(listToVector(list.get()), (vector<int>{4, 1, 9}));
    delete orphaned;
}

LC_TEST(lc0237_delete_node_in_a_linked_list, can_delete_the_second_to_last_node) {
    lc0237::Solution s;
    ListGuard list({1, 2, 3});
    ListNode* orphaned = nodeAt(list.get(), 2);
    s.deleteNode(nodeAt(list.get(), 1));
    LC_EXPECT_EQ(listToVector(list.get()), (vector<int>{1, 3}));
    delete orphaned;
}

LC_TEST(lc21_merge_two_sorted_lists, interleaves_both_lists_in_order) {
    lc21::Solution s;
    ListGuard a({1, 2, 4});
    ListGuard b({1, 3, 4});
    ListNode* merged = s.mergeTwoLists(a.get(), b.get());
    LC_EXPECT_EQ(listToVector(merged), (vector<int>{1, 1, 2, 3, 4, 4}));
    a.release();
    b.release();
    freeList(merged);
}

LC_TEST(lc21_merge_two_sorted_lists, handles_empty_inputs) {
    lc21::Solution s;
    LC_EXPECT_EQ(s.mergeTwoLists(nullptr, nullptr), nullptr);

    ListGuard only({0});
    LC_EXPECT_EQ(listToVector(s.mergeTwoLists(nullptr, only.get())), (vector<int>{0}));
    LC_EXPECT_EQ(listToVector(s.mergeTwoLists(only.get(), nullptr)), (vector<int>{0}));
}

LC_TEST(lc141_linked_list_cycle, detects_a_cycle) {
    lc141::Solution s;
    ListNode* head = makeList({3, 2, 0, -4});
    nodeAt(head, 3)->next = nodeAt(head, 1);
    LC_EXPECT_TRUE(s.hasCycle(head));

    nodeAt(head, 3)->next = nullptr;
    freeList(head);
}

LC_TEST(lc141_linked_list_cycle, returns_false_for_acyclic_lists) {
    lc141::Solution s;
    ListGuard list({1, 2, 3});
    LC_EXPECT_FALSE(s.hasCycle(list.get()));
    LC_EXPECT_FALSE(s.hasCycle(nullptr));

    ListGuard single({1});
    LC_EXPECT_FALSE(s.hasCycle(single.get()));
}

LC_TEST(lc206_reverse_linked_list, reverses_the_whole_list) {
    lc206::Solution s;
    ListGuard list({1, 2, 3, 4, 5});
    ListNode* reversed = s.reverseList(list.get());
    list.release();
    LC_EXPECT_EQ(listToVector(reversed), (vector<int>{5, 4, 3, 2, 1}));
    freeList(reversed);
}

LC_TEST(lc206_reverse_linked_list, handles_empty_and_single_element_lists) {
    lc206::Solution s;
    LC_EXPECT_EQ(s.reverseList(nullptr), nullptr);

    ListGuard single({7});
    LC_EXPECT_EQ(listToVector(s.reverseList(single.get())), (vector<int>{7}));
}

LC_TEST(lc876_middle_of_the_linked_list, returns_second_middle_for_even_length) {
    lc876::Solution s;
    ListGuard even({1, 2, 3, 4, 5, 6});
    LC_EXPECT_EQ(listToVector(s.middleNode(even.get())), (vector<int>{4, 5, 6}));
}

LC_TEST(lc876_middle_of_the_linked_list, returns_exact_middle_for_odd_length) {
    lc876::Solution s;
    ListGuard odd({1, 2, 3, 4, 5});
    LC_EXPECT_EQ(listToVector(s.middleNode(odd.get())), (vector<int>{3, 4, 5}));

    ListGuard single({1});
    LC_EXPECT_EQ(listToVector(s.middleNode(single.get())), (vector<int>{1}));
}
