#include "support/lc_test.hpp"

namespace lc33 {
#include "lc33_search_in_rotated_array.cpp"
}
namespace lc35 {
#include "lc35_search_insertion_position.cpp"
}
namespace lc704 {
#include "lc704_binary_search.cpp"
}
namespace lc735 {
#include "lc735_asteroid_collision.cpp"
}
namespace lc739 {
#include "lc739_daily_temperatures.cpp"
}
namespace lc875 {
#include "lc875_koko_eating_bananas.cpp"
}

LC_TEST(lc33_search_in_rotated_sorted_array, finds_target_in_either_half) {
    lc33::Solution s;
    vector<int> nums{4, 5, 6, 7, 0, 1, 2};
    LC_EXPECT_EQ(s.search(nums, 0), 4);
    LC_EXPECT_EQ(s.search(nums, 6), 2);
    LC_EXPECT_EQ(s.search(nums, 3), -1);
}

LC_TEST(lc33_search_in_rotated_sorted_array, handles_unrotated_and_single_element_input) {
    lc33::Solution s;
    vector<int> sorted{1, 2, 3, 4, 5};
    LC_EXPECT_EQ(s.search(sorted, 5), 4);

    vector<int> single{1};
    LC_EXPECT_EQ(s.search(single, 1), 0);
    LC_EXPECT_EQ(s.search(single, 0), -1);
}

LC_TEST(lc35_search_insert_position, returns_index_of_existing_target) {
    lc35::Solution s;
    vector<int> nums{1, 3, 5, 6};
    LC_EXPECT_EQ(s.searchInsert(nums, 5), 2);
    LC_EXPECT_EQ(s.searchInsert(nums, 1), 0);
}

LC_TEST(lc35_search_insert_position, returns_insertion_point_for_missing_target) {
    lc35::Solution s;
    vector<int> nums{1, 3, 5, 6};
    LC_EXPECT_EQ(s.searchInsert(nums, 2), 1);
    LC_EXPECT_EQ(s.searchInsert(nums, 7), 4);
    LC_EXPECT_EQ(s.searchInsert(nums, 0), 0);
}

LC_TEST(lc704_binary_search, finds_target_index) {
    lc704::Solution s;
    vector<int> nums{-1, 0, 3, 5, 9, 12};
    LC_EXPECT_EQ(s.search(nums, 9), 4);
    LC_EXPECT_EQ(s.search(nums, -1), 0);
    LC_EXPECT_EQ(s.search(nums, 12), 5);
}

LC_TEST(lc704_binary_search, returns_minus_one_when_absent) {
    lc704::Solution s;
    vector<int> nums{-1, 0, 3, 5, 9, 12};
    LC_EXPECT_EQ(s.search(nums, 2), -1);

    vector<int> empty;
    LC_EXPECT_EQ(s.search(empty, 1), -1);
}

LC_TEST(lc735_asteroid_collision, resolves_collisions_between_opposing_asteroids) {
    lc735::Solution s;
    vector<int> mixed{5, 10, -5};
    LC_EXPECT_EQ(s.asteroidCollision(mixed), (vector<int>{5, 10}));

    vector<int> equal{8, -8};
    LC_EXPECT_EQ(s.asteroidCollision(equal), (vector<int>{}));

    vector<int> chain{10, 2, -5};
    LC_EXPECT_EQ(s.asteroidCollision(chain), (vector<int>{10}));
}

LC_TEST(lc735_asteroid_collision, leaves_non_colliding_asteroids_alone) {
    lc735::Solution s;
    vector<int> diverging{-2, -1, 1, 2};
    LC_EXPECT_EQ(s.asteroidCollision(diverging), (vector<int>{-2, -1, 1, 2}));

    vector<int> single{1};
    LC_EXPECT_EQ(s.asteroidCollision(single), (vector<int>{1}));
}

LC_TEST(lc739_daily_temperatures, counts_days_until_a_warmer_temperature) {
    lc739::Solution s;
    vector<int> temps{73, 74, 75, 71, 69, 72, 76, 73};
    LC_EXPECT_EQ(s.dailyTemperatures(temps), (vector<int>{1, 1, 4, 2, 1, 1, 0, 0}));
}

LC_TEST(lc739_daily_temperatures, returns_zeros_for_non_increasing_input) {
    lc739::Solution s;
    vector<int> descending{30, 29, 28};
    LC_EXPECT_EQ(s.dailyTemperatures(descending), (vector<int>{0, 0, 0}));

    vector<int> flat{30, 30, 30};
    LC_EXPECT_EQ(s.dailyTemperatures(flat), (vector<int>{0, 0, 0}));
}

LC_TEST(lc875_koko_eating_bananas, finds_minimum_feasible_speed) {
    lc875::Solution s;
    vector<int> piles{3, 6, 7, 11};
    LC_EXPECT_EQ(s.minEatingSpeed(piles, 8), 4);

    vector<int> repeated{30, 11, 23, 4, 20};
    LC_EXPECT_EQ(s.minEatingSpeed(repeated, 5), 30);
    LC_EXPECT_EQ(s.minEatingSpeed(repeated, 6), 23);
}

LC_TEST(lc875_koko_eating_bananas, needs_only_one_banana_per_hour_when_time_is_ample) {
    lc875::Solution s;
    vector<int> piles{1, 1, 1, 1};
    LC_EXPECT_EQ(s.minEatingSpeed(piles, 4), 1);
}
