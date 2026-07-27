#include "support/lc_test.hpp"

namespace lc0515 {
#include "0515-find-largest-value-in-each-tree-row/0515-find-largest-value-in-each-tree-row.cpp"
}
namespace lc94 {
#include "lc94_binary_tree_inorder_traversal.cpp"
}
namespace lc98 {
#include "lc98_validate_binary_search_tree.cpp"
}
namespace lc102 {
#include "lc102_binary_tree_level_order_traversal.cpp"
}
namespace lc104 {
#include "lc104_maximum_depth_of_binary_tree.cpp"
}
namespace lc226 {
#include "lc226_invert_binary_tree.cpp"
}

using lctest::Slot;
using lctest::TreeGuard;
using lctest::treeToVector;

LC_TEST(lc0515_find_largest_value_in_each_tree_row, returns_row_maximums) {
    lc0515::Solution s;
    TreeGuard tree({1, 3, 2, 5, 3, std::nullopt, 9});
    LC_EXPECT_EQ(s.largestValues(tree.get()), (vector<int>{1, 3, 9}));
}

LC_TEST(lc0515_find_largest_value_in_each_tree_row, handles_empty_and_skewed_trees) {
    lc0515::Solution empty;
    LC_EXPECT_EQ(empty.largestValues(nullptr), (vector<int>{}));

    lc0515::Solution skewed;
    TreeGuard tree({1, std::nullopt, 2, std::nullopt, 3});
    LC_EXPECT_EQ(skewed.largestValues(tree.get()), (vector<int>{1, 2, 3}));
}

LC_TEST(lc94_binary_tree_inorder_traversal, visits_left_root_right) {
    lc94::Solution s;
    TreeGuard tree({1, std::nullopt, 2, 3});
    LC_EXPECT_EQ(s.inorderTraversal(tree.get()), (vector<int>{1, 3, 2}));

    TreeGuard balanced({4, 2, 6, 1, 3, 5, 7});
    LC_EXPECT_EQ(s.inorderTraversal(balanced.get()), (vector<int>{1, 2, 3, 4, 5, 6, 7}));
}

LC_TEST(lc94_binary_tree_inorder_traversal, handles_empty_tree) {
    lc94::Solution s;
    LC_EXPECT_EQ(s.inorderTraversal(nullptr), (vector<int>{}));
}

LC_TEST(lc98_validate_binary_search_tree, accepts_valid_search_trees) {
    lc98::Solution s;
    TreeGuard tree({2, 1, 3});
    LC_EXPECT_TRUE(s.isValidBST(tree.get()));

    TreeGuard single({INT_MIN});
    LC_EXPECT_TRUE(s.isValidBST(single.get()));

    LC_EXPECT_TRUE(s.isValidBST(nullptr));
}

LC_TEST(lc98_validate_binary_search_tree, rejects_locally_valid_but_globally_wrong_trees) {
    lc98::Solution s;
    TreeGuard tree({5, 1, 4, std::nullopt, std::nullopt, 3, 6});
    LC_EXPECT_FALSE(s.isValidBST(tree.get()));

    TreeGuard duplicates({2, 2, 2});
    LC_EXPECT_FALSE(s.isValidBST(duplicates.get()));
}

LC_TEST(lc102_binary_tree_level_order_traversal, groups_nodes_by_depth) {
    lc102::Solution s;
    TreeGuard tree({3, 9, 20, std::nullopt, std::nullopt, 15, 7});
    LC_EXPECT_EQ(s.levelOrder(tree.get()), (vector<vector<int>>{{3}, {9, 20}, {15, 7}}));
}

LC_TEST(lc102_binary_tree_level_order_traversal, handles_empty_and_single_node_trees) {
    lc102::Solution s;
    LC_EXPECT_EQ(s.levelOrder(nullptr), (vector<vector<int>>{}));

    TreeGuard single({1});
    LC_EXPECT_EQ(s.levelOrder(single.get()), (vector<vector<int>>{{1}}));
}

LC_TEST(lc104_maximum_depth_of_binary_tree, counts_longest_root_to_leaf_path) {
    lc104::Solution s;
    TreeGuard tree({3, 9, 20, std::nullopt, std::nullopt, 15, 7});
    LC_EXPECT_EQ(s.maxDepth(tree.get()), 3);

    TreeGuard skewed({1, std::nullopt, 2});
    LC_EXPECT_EQ(s.maxDepth(skewed.get()), 2);

    LC_EXPECT_EQ(s.maxDepth(nullptr), 0);
}

LC_TEST(lc226_invert_binary_tree, mirrors_children_recursively) {
    lc226::Solution s;
    TreeGuard tree({4, 2, 7, 1, 3, 6, 9});
    TreeNode* inverted = s.invertTree(tree.get());
    LC_EXPECT_EQ(treeToVector(inverted), (vector<Slot>{4, 7, 2, 9, 6, 3, 1}));
}

LC_TEST(lc226_invert_binary_tree, handles_empty_and_asymmetric_trees) {
    lc226::Solution s;
    LC_EXPECT_EQ(s.invertTree(nullptr), nullptr);

    TreeGuard tree({2, 1, 3});
    LC_EXPECT_EQ(treeToVector(s.invertTree(tree.get())), (vector<Slot>{2, 3, 1}));
}
