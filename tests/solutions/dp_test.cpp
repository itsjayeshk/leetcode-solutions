#include "support/lc_test.hpp"

namespace lc0064 {
#include "0064-minimum-path-sum/0064-minimum-path-sum.cpp"
}
namespace lc0120 {
#include "0120-triangle/0120-triangle.cpp"
}
namespace lc70 {
#include "lc70_climbing_stairs.cpp"
}
namespace lc198 {
#include "lc198_house_robber.cpp"
}
namespace lc300 {
#include "lc300_longest_increaing_subsequence.cpp"
}
namespace lc1143 {
#include "lc1143_longest_common_subsequence.cpp"
}

LC_TEST(lc0064_minimum_path_sum, finds_cheapest_path_to_bottom_right) {
    lc0064::Solution s;
    vector<vector<int>> grid{{1, 3, 1}, {1, 5, 1}, {4, 2, 1}};
    LC_EXPECT_EQ(s.minPathSum(grid), 7);

    vector<vector<int>> wide{{1, 2, 3}, {4, 5, 6}};
    LC_EXPECT_EQ(s.minPathSum(wide), 12);
}

LC_TEST(lc0064_minimum_path_sum, handles_single_row_column_and_cell) {
    lc0064::Solution s;
    vector<vector<int>> row{{1, 2, 3, 4}};
    LC_EXPECT_EQ(s.minPathSum(row), 10);

    vector<vector<int>> column{{1}, {2}, {3}};
    LC_EXPECT_EQ(s.minPathSum(column), 6);

    vector<vector<int>> cell{{5}};
    LC_EXPECT_EQ(s.minPathSum(cell), 5);
}

LC_TEST(lc0120_triangle, finds_minimum_top_down_path_sum) {
    lc0120::Solution s;
    vector<vector<int>> triangle{{2}, {3, 4}, {6, 5, 7}, {4, 1, 8, 3}};
    LC_EXPECT_EQ(s.minimumTotal(triangle), 11);
}

LC_TEST(lc0120_triangle, handles_single_row_and_negative_values) {
    lc0120::Solution s;
    vector<vector<int>> single{{-10}};
    LC_EXPECT_EQ(s.minimumTotal(single), -10);

    vector<vector<int>> negatives{{1}, {2, 3}, {1, -1, -3}};
    LC_EXPECT_EQ(s.minimumTotal(negatives), 1);
}

LC_TEST(lc70_climbing_stairs, counts_distinct_ways) {
    lc70::Solution s;
    LC_EXPECT_EQ(s.climbStairs(1), 1);
    LC_EXPECT_EQ(s.climbStairs(2), 2);
    LC_EXPECT_EQ(s.climbStairs(3), 3);
    LC_EXPECT_EQ(s.climbStairs(5), 8);
    LC_EXPECT_EQ(s.climbStairs(10), 89);
}

LC_TEST(lc198_house_robber, maximizes_non_adjacent_sum) {
    lc198::Solution s;
    vector<int> small{1, 2, 3, 1};
    LC_EXPECT_EQ(s.rob(small), 4);

    vector<int> larger{2, 7, 9, 3, 1};
    LC_EXPECT_EQ(s.rob(larger), 12);
}

LC_TEST(lc198_house_robber, handles_one_and_two_houses) {
    lc198::Solution s;
    vector<int> one{5};
    LC_EXPECT_EQ(s.rob(one), 5);

    vector<int> two{2, 1};
    LC_EXPECT_EQ(s.rob(two), 2);
}

LC_TEST(lc300_longest_increasing_subsequence, returns_length_of_longest_run) {
    lc300::Solution s;
    vector<int> nums{10, 9, 2, 5, 3, 7, 101, 18};
    LC_EXPECT_EQ(s.lengthOfLIS(nums), 4);

    vector<int> withDuplicates{0, 1, 0, 3, 2, 3};
    LC_EXPECT_EQ(s.lengthOfLIS(withDuplicates), 4);
}

LC_TEST(lc300_longest_increasing_subsequence, handles_flat_and_single_element_input) {
    lc300::Solution s;
    vector<int> flat{7, 7, 7, 7};
    LC_EXPECT_EQ(s.lengthOfLIS(flat), 1);

    vector<int> single{1};
    LC_EXPECT_EQ(s.lengthOfLIS(single), 1);
}

LC_TEST(lc1143_longest_common_subsequence, measures_shared_subsequence_length) {
    lc1143::Solution s;
    LC_EXPECT_EQ(s.longestCommonSubsequence("abcde", "ace"), 3);
    LC_EXPECT_EQ(s.longestCommonSubsequence("abc", "abc"), 3);
    LC_EXPECT_EQ(s.longestCommonSubsequence("abc", "def"), 0);
}

LC_TEST(lc1143_longest_common_subsequence, handles_empty_input) {
    lc1143::Solution s;
    LC_EXPECT_EQ(s.longestCommonSubsequence("", "abc"), 0);
    LC_EXPECT_EQ(s.longestCommonSubsequence("abc", ""), 0);
}
