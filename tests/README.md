# Tests

Unit tests for the solutions in this repository. No external dependencies — a
C++17 compiler and `make` are all that is needed.

```bash
cd tests
make test     # build and run
make clean
```

## Layout

| Path | Purpose |
| --- | --- |
| `support/lc_prelude.hpp` | Recreates the LeetCode judge environment: standard headers, `using namespace std;`, `ListNode`/`TreeNode`, plus list/tree builders (`makeList`, `makeTree`, `listToVector`, `treeToVector`) and RAII guards that free them. |
| `support/lc_test.hpp` | Header-only test framework: `LC_TEST`, `LC_EXPECT_EQ`, `LC_EXPECT_TRUE`, `LC_EXPECT_FALSE`. |
| `main.cpp` | Runs every registered test; exits non-zero if any assertion fails. |
| `solutions/*_test.cpp` | Tests grouped by topic. |

## Adding tests for another solution

Solution files are raw LeetCode submissions (just `class Solution`), so a test
`#include`s the solution inside a namespace to keep the many `Solution` classes
apart:

```cpp
#include "support/lc_test.hpp"

namespace lc704 {
#include "lc704_binary_search.cpp"
}

LC_TEST(lc704_binary_search, finds_target_index) {
    lc704::Solution s;
    vector<int> nums{-1, 0, 3, 5, 9, 12};
    LC_EXPECT_EQ(s.search(nums, 9), 4);
}
```

Include paths are relative to the repository root (`-I..`), and new
`solutions/*.cpp` files are picked up by the `Makefile` automatically.
