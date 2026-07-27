#include "support/lc_test.hpp"

namespace lc0001 {
#include "0001-two-sum/0001-two-sum.cpp"
}
namespace lc0041 {
#include "0041-first-missing-positive/0041-first-missing-positive.cpp"
}
namespace lc26 {
#include "lc26_remove_duplicates.cpp"
}
namespace lc27 {
#include "lc27_remove_element.cpp"
}
namespace lc53 {
#include "lc53_maximum_subarray.cpp"
}
namespace lc75 {
#include "lc75_sort_colours.cpp"
}
namespace lc88 {
#include "lc88_merge_sorted_array.cpp"
}
namespace lc121 {
#include "lc121_best_time_to_buy_sell.cpp"
}
namespace lc169 {
#include "lc169_majority_element.cpp"
}
namespace lc217 {
#include "lc217_contains_duplicate.cpp"
}
namespace lc238 {
#include "lc238_product_of_array_except_self.cpp"
}
namespace lc283 {
#include "lc283_move_zeroes.cpp"
}
namespace lc347 {
#include "lc347_top_k_frequent_elements.cpp"
}

LC_TEST(lc0001_two_sum, finds_the_pair_of_indices) {
    lc0001::Solution s;
    vector<int> nums{2, 7, 11, 15};
    LC_EXPECT_EQ(s.twoSum(nums, 9), (vector<int>{0, 1}));
}

LC_TEST(lc0001_two_sum, matches_non_adjacent_and_negative_values) {
    lc0001::Solution s;
    vector<int> nums{-3, 4, 3, 90};
    LC_EXPECT_EQ(s.twoSum(nums, 0), (vector<int>{0, 2}));

    vector<int> duplicates{3, 3};
    LC_EXPECT_EQ(s.twoSum(duplicates, 6), (vector<int>{0, 1}));
}

LC_TEST(lc0041_first_missing_positive, returns_smallest_absent_positive) {
    lc0041::Solution s;
    vector<int> unsorted{3, 4, -1, 1};
    LC_EXPECT_EQ(s.firstMissingPositive(unsorted), 2);

    vector<int> contiguous{1, 2, 0};
    LC_EXPECT_EQ(s.firstMissingPositive(contiguous), 3);

    vector<int> withDuplicates{7, 8, 9, 11, 12};
    LC_EXPECT_EQ(s.firstMissingPositive(withDuplicates), 1);
}

LC_TEST(lc0041_first_missing_positive, handles_full_permutation_and_single_element) {
    lc0041::Solution s;
    vector<int> permutation{1, 2, 3, 4};
    LC_EXPECT_EQ(s.firstMissingPositive(permutation), 5);

    vector<int> single{1};
    LC_EXPECT_EQ(s.firstMissingPositive(single), 2);
}

LC_TEST(lc26_remove_duplicates, compacts_unique_prefix) {
    lc26::Solution s;
    vector<int> nums{0, 0, 1, 1, 1, 2, 2, 3, 3, 4};
    int k = s.removeDuplicates(nums);
    LC_EXPECT_EQ(k, 5);
    LC_EXPECT_EQ((vector<int>(nums.begin(), nums.begin() + k)), (vector<int>{0, 1, 2, 3, 4}));
}

LC_TEST(lc26_remove_duplicates, keeps_already_unique_input_untouched) {
    lc26::Solution s;
    vector<int> nums{1, 2, 3};
    LC_EXPECT_EQ(s.removeDuplicates(nums), 3);
    LC_EXPECT_EQ(nums, (vector<int>{1, 2, 3}));

    vector<int> single{7};
    LC_EXPECT_EQ(s.removeDuplicates(single), 1);
}

LC_TEST(lc27_remove_element, drops_every_occurrence_of_val) {
    lc27::Solution s;
    vector<int> nums{0, 1, 2, 2, 3, 0, 4, 2};
    int k = s.removeElement(nums, 2);
    LC_EXPECT_EQ(k, 5);
    LC_EXPECT_EQ((vector<int>(nums.begin(), nums.begin() + k)), (vector<int>{0, 1, 3, 0, 4}));
}

LC_TEST(lc27_remove_element, returns_zero_when_all_elements_match) {
    lc27::Solution s;
    vector<int> nums{3, 3, 3};
    LC_EXPECT_EQ(s.removeElement(nums, 3), 0);

    vector<int> empty;
    LC_EXPECT_EQ(s.removeElement(empty, 1), 0);
}

LC_TEST(lc53_maximum_subarray, finds_best_contiguous_sum) {
    lc53::Solution s;
    vector<int> mixed{-2, 1, -3, 4, -1, 2, 1, -5, 4};
    LC_EXPECT_EQ(s.maxSubArray(mixed), 6);

    vector<int> ascending{5, 4, -1, 7, 8};
    LC_EXPECT_EQ(s.maxSubArray(ascending), 23);
}

LC_TEST(lc53_maximum_subarray, handles_all_negative_input) {
    lc53::Solution s;
    vector<int> negatives{-2, -3, -1, -5};
    LC_EXPECT_EQ(s.maxSubArray(negatives), -1);

    vector<int> single{-1};
    LC_EXPECT_EQ(s.maxSubArray(single), -1);
}

LC_TEST(lc75_sort_colors, groups_zeros_ones_and_twos) {
    lc75::Solution s;
    vector<int> nums{2, 0, 2, 1, 1, 0};
    s.sortColors(nums);
    LC_EXPECT_EQ(nums, (vector<int>{0, 0, 1, 1, 2, 2}));

    vector<int> already{0, 1, 2};
    s.sortColors(already);
    LC_EXPECT_EQ(already, (vector<int>{0, 1, 2}));
}

LC_TEST(lc88_merge_sorted_array, merges_second_array_into_first) {
    lc88::Solution s;
    vector<int> nums1{1, 2, 3, 0, 0, 0};
    vector<int> nums2{2, 5, 6};
    s.merge(nums1, 3, nums2, 3);
    LC_EXPECT_EQ(nums1, (vector<int>{1, 2, 2, 3, 5, 6}));
}

LC_TEST(lc88_merge_sorted_array, handles_empty_second_array) {
    lc88::Solution s;
    vector<int> nums1{1};
    vector<int> nums2;
    s.merge(nums1, 1, nums2, 0);
    LC_EXPECT_EQ(nums1, (vector<int>{1}));
}

LC_TEST(lc121_best_time_to_buy_and_sell_stock, returns_max_single_transaction_profit) {
    lc121::Solution s;
    vector<int> prices{7, 1, 5, 3, 6, 4};
    LC_EXPECT_EQ(s.maxProfit(prices), 5);
}

LC_TEST(lc121_best_time_to_buy_and_sell_stock, returns_zero_on_monotonic_decline) {
    lc121::Solution s;
    vector<int> declining{7, 6, 4, 3, 1};
    LC_EXPECT_EQ(s.maxProfit(declining), 0);

    vector<int> single{5};
    LC_EXPECT_EQ(s.maxProfit(single), 0);
}

LC_TEST(lc169_majority_element, finds_element_appearing_more_than_half) {
    lc169::Solution s;
    vector<int> nums{3, 2, 3};
    LC_EXPECT_EQ(s.majorityElement(nums), 3);

    vector<int> longer{2, 2, 1, 1, 1, 2, 2};
    LC_EXPECT_EQ(s.majorityElement(longer), 2);

    vector<int> single{1};
    LC_EXPECT_EQ(s.majorityElement(single), 1);
}

LC_TEST(lc217_contains_duplicate, detects_repeated_values) {
    lc217::Solution s;
    vector<int> withDuplicate{1, 2, 3, 1};
    LC_EXPECT_TRUE(s.containsDuplicate(withDuplicate));

    vector<int> unique{1, 2, 3, 4};
    LC_EXPECT_FALSE(s.containsDuplicate(unique));

    vector<int> single{1};
    LC_EXPECT_FALSE(s.containsDuplicate(single));
}

LC_TEST(lc238_product_of_array_except_self, multiplies_all_other_elements) {
    lc238::Solution s;
    vector<int> nums{1, 2, 3, 4};
    LC_EXPECT_EQ(s.productExceptSelf(nums), (vector<int>{24, 12, 8, 6}));
}

LC_TEST(lc238_product_of_array_except_self, handles_zeros_and_negatives) {
    lc238::Solution s;
    vector<int> nums{-1, 1, 0, -3, 3};
    LC_EXPECT_EQ(s.productExceptSelf(nums), (vector<int>{0, 0, 9, 0, 0}));
}

LC_TEST(lc283_move_zeroes, shifts_zeros_to_the_end_preserving_order) {
    lc283::Solution s;
    vector<int> nums{0, 1, 0, 3, 12};
    s.moveZeroes(nums);
    LC_EXPECT_EQ(nums, (vector<int>{1, 3, 12, 0, 0}));
}

LC_TEST(lc283_move_zeroes, handles_all_zeros_and_no_zeros) {
    lc283::Solution s;
    vector<int> zeros{0, 0};
    s.moveZeroes(zeros);
    LC_EXPECT_EQ(zeros, (vector<int>{0, 0}));

    vector<int> none{1, 2, 3};
    s.moveZeroes(none);
    LC_EXPECT_EQ(none, (vector<int>{1, 2, 3}));
}

LC_TEST(lc347_top_k_frequent_elements, returns_k_most_frequent_in_descending_frequency) {
    lc347::Solution s;
    vector<int> nums{1, 1, 1, 2, 2, 3};
    LC_EXPECT_EQ(s.topKFrequent(nums, 2), (vector<int>{1, 2}));

    vector<int> single{1};
    LC_EXPECT_EQ(s.topKFrequent(single, 1), (vector<int>{1}));
}
