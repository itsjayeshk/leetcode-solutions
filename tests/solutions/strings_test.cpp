#include "support/lc_test.hpp"

namespace lc0071 {
#include "0071-simplify-path/0071-simplify-path.cpp"
}
namespace lc0316 {
#include "0316-remove-duplicate-letters/0316-remove-duplicate-letters.cpp"
}
namespace lc14 {
#include "lc14_longest_common_prefix.cpp"
}
namespace lc20 {
#include "lc20_valid_parenthisis.cpp"
}
namespace lc125 {
#include "lc125_valid_pallindrome.cpp"
}
namespace lc242 {
#include "lc242_valid_anagram.cpp"
}
namespace lc344 {
#include "lc344_reverse_string.cpp"
}

LC_TEST(lc0071_simplify_path, collapses_dots_and_redundant_slashes) {
    lc0071::Solution s;
    LC_EXPECT_EQ(s.simplifyPath("/home/"), "/home");
    LC_EXPECT_EQ(s.simplifyPath("/home//foo/"), "/home/foo");
    LC_EXPECT_EQ(s.simplifyPath("/a/./b/../../c/"), "/c");
}

LC_TEST(lc0071_simplify_path, cannot_go_above_root) {
    lc0071::Solution s;
    LC_EXPECT_EQ(s.simplifyPath("/../"), "/");
    LC_EXPECT_EQ(s.simplifyPath("/..hidden"), "/..hidden");
    LC_EXPECT_EQ(s.simplifyPath("/"), "/");
}

LC_TEST(lc0316_remove_duplicate_letters, returns_lexicographically_smallest_result) {
    lc0316::Solution s;
    LC_EXPECT_EQ(s.removeDuplicateLetters("bcabc"), "abc");
    LC_EXPECT_EQ(s.removeDuplicateLetters("cbacdcbc"), "acdb");
}

LC_TEST(lc0316_remove_duplicate_letters, handles_single_and_repeated_letters) {
    lc0316::Solution s;
    LC_EXPECT_EQ(s.removeDuplicateLetters("a"), "a");
    LC_EXPECT_EQ(s.removeDuplicateLetters("aaaa"), "a");
    LC_EXPECT_EQ(s.removeDuplicateLetters("abacb"), "abc");
}

LC_TEST(lc14_longest_common_prefix, returns_shared_leading_characters) {
    lc14::Solution s;
    vector<string> shared{"flower", "flow", "flight"};
    LC_EXPECT_EQ(s.longestCommonPrefix(shared), "fl");

    vector<string> identical{"abab", "abab", "abab"};
    LC_EXPECT_EQ(s.longestCommonPrefix(identical), "abab");
}

LC_TEST(lc14_longest_common_prefix, returns_empty_when_nothing_is_shared) {
    lc14::Solution s;
    vector<string> disjoint{"dog", "racecar", "car"};
    LC_EXPECT_EQ(s.longestCommonPrefix(disjoint), "");

    vector<string> single{"alone"};
    LC_EXPECT_EQ(s.longestCommonPrefix(single), "alone");
}

LC_TEST(lc14_longest_common_prefix, stops_at_first_difference_beyond_input_count) {
    // The prefix (5 chars) is longer than the number of strings (2), which is
    // where an index-bounded loop would stop too early.
    lc14::Solution s;
    vector<string> strs{"abcdef", "abcdeX"};
    LC_EXPECT_EQ(s.longestCommonPrefix(strs), "abcde");
}

LC_TEST(lc20_valid_parentheses, accepts_correctly_nested_brackets) {
    lc20::Solution s;
    LC_EXPECT_TRUE(s.isValid("()"));
    LC_EXPECT_TRUE(s.isValid("()[]{}"));
    LC_EXPECT_TRUE(s.isValid("{[()]}"));
}

LC_TEST(lc20_valid_parentheses, rejects_mismatched_or_unclosed_brackets) {
    lc20::Solution s;
    LC_EXPECT_FALSE(s.isValid("(]"));
    LC_EXPECT_FALSE(s.isValid("([)]"));
    LC_EXPECT_FALSE(s.isValid("("));
    LC_EXPECT_FALSE(s.isValid("]"));
}

LC_TEST(lc125_valid_palindrome, ignores_case_and_non_alphanumerics) {
    lc125::Solution s;
    LC_EXPECT_TRUE(s.isPalindrome("A man, a plan, a canal: Panama"));
    LC_EXPECT_TRUE(s.isPalindrome("."));
    LC_EXPECT_TRUE(s.isPalindrome("0P0"));
}

LC_TEST(lc125_valid_palindrome, rejects_non_palindromes) {
    lc125::Solution s;
    LC_EXPECT_FALSE(s.isPalindrome("race a car"));
    LC_EXPECT_FALSE(s.isPalindrome("0P"));
}

LC_TEST(lc242_valid_anagram, accepts_permutations_of_the_same_letters) {
    lc242::Solution s;
    LC_EXPECT_TRUE(s.isAnagram("anagram", "nagaram"));
    LC_EXPECT_TRUE(s.isAnagram("", ""));
}

LC_TEST(lc242_valid_anagram, rejects_different_letters_or_lengths) {
    lc242::Solution s;
    LC_EXPECT_FALSE(s.isAnagram("rat", "car"));
    LC_EXPECT_FALSE(s.isAnagram("a", "ab"));
    LC_EXPECT_FALSE(s.isAnagram("aacc", "ccac"));
}

LC_TEST(lc344_reverse_string, reverses_in_place) {
    lc344::Solution s;
    vector<char> word{'h', 'e', 'l', 'l', 'o'};
    s.reverseString(word);
    LC_EXPECT_EQ(word, (vector<char>{'o', 'l', 'l', 'e', 'h'}));

    vector<char> even{'H', 'a', 'n', 'n', 'a', 'h'};
    s.reverseString(even);
    LC_EXPECT_EQ(even, (vector<char>{'h', 'a', 'n', 'n', 'a', 'H'}));
}
