#pragma once

// Minimal header-only test framework: no external dependencies so the suite
// builds with nothing but a C++17 compiler.
//
//   LC_TEST(lc704_binary_search, finds_target) {
//       lc704::Solution s;
//       vector<int> nums{-1, 0, 3, 5, 9, 12};
//       LC_EXPECT_EQ(s.search(nums, 9), 4);
//   }

#include "lc_prelude.hpp"

namespace lctest {

struct TestCase {
    const char* suite;
    const char* name;
    void (*fn)();
};

inline std::vector<TestCase>& registry() {
    static std::vector<TestCase> tests;
    return tests;
}

inline int& currentFailures() {
    static int failures = 0;
    return failures;
}

struct Registrar {
    Registrar(const char* suite, const char* name, void (*fn)()) {
        registry().push_back(TestCase{suite, name, fn});
    }
};

// ---------------------------------------------------------------------------
// Value formatting
// ---------------------------------------------------------------------------

inline std::string describe(bool value) { return value ? "true" : "false"; }
inline std::string describe(char value) { return std::string("'") + value + "'"; }
inline std::string describe(const std::string& value) { return "\"" + value + "\""; }
inline std::string describe(const char* value) { return describe(std::string(value)); }

template <typename T>
std::string describe(const T& value) {
    std::ostringstream out;
    out << value;
    return out.str();
}

template <typename T>
std::string describe(const std::optional<T>& value) {
    return value.has_value() ? describe(*value) : "null";
}

template <typename T>
std::string describe(const std::vector<T>& values) {
    std::string out = "[";
    for (std::size_t i = 0; i < values.size(); i++) {
        if (i > 0) {
            out += ", ";
        }
        out += describe(values[i]);
    }
    return out + "]";
}

template <typename A, typename B>
std::string describe(const std::pair<A, B>& value) {
    return "(" + describe(value.first) + ", " + describe(value.second) + ")";
}

// ---------------------------------------------------------------------------
// Assertions
// ---------------------------------------------------------------------------

inline void reportFailure(const char* file, int line, const std::string& message) {
    currentFailures()++;
    std::cout << "    FAIL " << file << ":" << line << " " << message << "\n";
}

template <typename Actual, typename Expected>
void expectEq(const Actual& actual, const Expected& expected, const char* actualExpr,
              const char* expectedExpr, const char* file, int line) {
    if (actual == expected) {
        return;
    }
    reportFailure(file, line, std::string(actualExpr) + " == " + expectedExpr + "\n      actual:   " +
                                  describe(actual) + "\n      expected: " + describe(expected));
}

inline void expectTrue(bool value, const char* expr, const char* file, int line) {
    if (!value) {
        reportFailure(file, line, std::string("expected ") + expr + " to be true");
    }
}

inline void expectFalse(bool value, const char* expr, const char* file, int line) {
    if (value) {
        reportFailure(file, line, std::string("expected ") + expr + " to be false");
    }
}

inline int runAll() {
    std::size_t failedTests = 0;
    for (const TestCase& test : registry()) {
        currentFailures() = 0;
        std::cout << "[ RUN  ] " << test.suite << "." << test.name << "\n";
        test.fn();
        if (currentFailures() > 0) {
            failedTests++;
            std::cout << "[ FAIL ] " << test.suite << "." << test.name << "\n";
        }
    }
    std::cout << "\n" << registry().size() << " test(s) run, " << failedTests << " failed\n";
    return failedTests == 0 ? 0 : 1;
}

}  // namespace lctest

#define LC_TEST(suite, name)                                                          \
    static void suite##_##name##_body();                                              \
    static ::lctest::Registrar suite##_##name##_registrar(#suite, #name,              \
                                                          &suite##_##name##_body);    \
    static void suite##_##name##_body()

#define LC_EXPECT_EQ(actual, expected) \
    ::lctest::expectEq((actual), (expected), #actual, #expected, __FILE__, __LINE__)
#define LC_EXPECT_TRUE(value) ::lctest::expectTrue((value), #value, __FILE__, __LINE__)
#define LC_EXPECT_FALSE(value) ::lctest::expectFalse((value), #value, __FILE__, __LINE__)
