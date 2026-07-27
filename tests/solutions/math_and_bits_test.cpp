#include "support/lc_test.hpp"

namespace lc1979 {
#include "1979-find-greatest-common-divisor-of-array/1979-find-greatest-common-divisor-of-array.cpp"
}
namespace lc7 {
#include "lc7_reverse_number.cpp"
}
namespace lc9 {
#include "lc9_pallindrome_number.cpp"
}
namespace lc136 {
#include "lc136_single_number.cpp"
}
namespace lc191 {
#include "lc191_number_of_1_bits.cpp"
}
namespace lc231 {
#include "lc231_power_of_2.cpp"
}

LC_TEST(lc7_reverse_integer, reverses_digits_keeping_sign) {
    lc7::Solution s;
    LC_EXPECT_EQ(s.reverse(123), 321);
    LC_EXPECT_EQ(s.reverse(-123), -321);
    LC_EXPECT_EQ(s.reverse(120), 21);
    LC_EXPECT_EQ(s.reverse(0), 0);
}

LC_TEST(lc9_palindrome_number, accepts_digit_palindromes) {
    lc9::Solution s;
    LC_EXPECT_TRUE(s.isPalindrome(121));
    LC_EXPECT_TRUE(s.isPalindrome(0));
    LC_EXPECT_TRUE(s.isPalindrome(1221));
}

LC_TEST(lc9_palindrome_number, rejects_negatives_and_asymmetric_numbers) {
    lc9::Solution s;
    LC_EXPECT_FALSE(s.isPalindrome(-121));
    LC_EXPECT_FALSE(s.isPalindrome(10));
    LC_EXPECT_FALSE(s.isPalindrome(123));
}

LC_TEST(lc136_single_number, finds_the_unpaired_value) {
    lc136::Solution s;
    vector<int> nums{4, 1, 2, 1, 2};
    LC_EXPECT_EQ(s.singleNumber(nums), 4);

    vector<int> withNegatives{-1, -1, -3};
    LC_EXPECT_EQ(s.singleNumber(withNegatives), -3);

    vector<int> single{1};
    LC_EXPECT_EQ(s.singleNumber(single), 1);
}

LC_TEST(lc191_number_of_1_bits, counts_set_bits) {
    lc191::Solution s;
    LC_EXPECT_EQ(s.hammingWeight(11), 3);
    LC_EXPECT_EQ(s.hammingWeight(128), 1);
    LC_EXPECT_EQ(s.hammingWeight(0), 0);
    LC_EXPECT_EQ(s.hammingWeight(INT_MAX), 31);
}

LC_TEST(lc231_power_of_two, accepts_exact_powers) {
    lc231::Solution s;
    LC_EXPECT_TRUE(s.isPowerOfTwo(1));
    LC_EXPECT_TRUE(s.isPowerOfTwo(16));
    LC_EXPECT_TRUE(s.isPowerOfTwo(1 << 30));
}

LC_TEST(lc231_power_of_two, rejects_non_powers_and_non_positives) {
    lc231::Solution s;
    LC_EXPECT_FALSE(s.isPowerOfTwo(3));
    LC_EXPECT_FALSE(s.isPowerOfTwo(0));
    LC_EXPECT_FALSE(s.isPowerOfTwo(-16));
}

LC_TEST(lc1979_find_greatest_common_divisor_of_array, uses_smallest_and_largest_values) {
    lc1979::Solution s;
    vector<int> nums{2, 5, 6, 9, 10};
    LC_EXPECT_EQ(s.findGCD(nums), 2);

    vector<int> multiples{7, 5, 6, 8, 3};
    LC_EXPECT_EQ(s.findGCD(multiples), 1);

    vector<int> coincident{3, 3};
    LC_EXPECT_EQ(s.findGCD(coincident), 3);
}
