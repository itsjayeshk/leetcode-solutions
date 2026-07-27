#include "support/lc_test.hpp"

namespace lc3532 {
#include "3532-path-existence-queries-in-a-graph-i/3532-path-existence-queries-in-a-graph-i.cpp"
}
namespace lc207 {
#include "lc207_course_scheduler.cpp"
}
namespace lc1971 {
#include "lc1971_find_if_path_exists_in_graph.cpp"
}
namespace lc2492 {
#include "2492-minimum-score-of-a-path-between-two-cities/2492-minimum-score-of-a-path-between-two-cities.cpp"
}

LC_TEST(lc207_course_schedule, accepts_acyclic_prerequisites) {
    lc207::Solution s;
    vector<vector<int>> simple{{1, 0}};
    LC_EXPECT_TRUE(s.canFinish(2, simple));

    vector<vector<int>> chain{{1, 0}, {2, 1}, {3, 2}};
    LC_EXPECT_TRUE(s.canFinish(4, chain));

    vector<vector<int>> none;
    LC_EXPECT_TRUE(s.canFinish(3, none));
}

LC_TEST(lc207_course_schedule, rejects_cyclic_prerequisites) {
    lc207::Solution s;
    vector<vector<int>> cycle{{1, 0}, {0, 1}};
    LC_EXPECT_FALSE(s.canFinish(2, cycle));

    vector<vector<int>> longerCycle{{0, 1}, {1, 2}, {2, 0}};
    LC_EXPECT_FALSE(s.canFinish(3, longerCycle));
}

LC_TEST(lc1971_find_if_path_exists_in_graph, finds_a_connecting_path) {
    lc1971::Solution s;
    vector<vector<int>> edges{{0, 1}, {1, 2}, {2, 0}};
    LC_EXPECT_TRUE(s.validPath(3, edges, 0, 2));

    vector<vector<int>> selfOnly;
    LC_EXPECT_TRUE(s.validPath(1, selfOnly, 0, 0));
}

LC_TEST(lc1971_find_if_path_exists_in_graph, reports_disconnected_components) {
    lc1971::Solution s;
    vector<vector<int>> edges{{0, 1}, {0, 2}, {3, 5}, {5, 4}, {4, 3}};
    LC_EXPECT_FALSE(s.validPath(6, edges, 0, 5));
    LC_EXPECT_TRUE(s.validPath(6, edges, 3, 4));
}

LC_TEST(lc2492_minimum_score_of_a_path_between_two_cities, returns_min_edge_on_component_of_city_one) {
    lc2492::Solution s;
    vector<vector<int>> roads{{1, 2, 9}, {2, 3, 6}, {2, 4, 5}, {1, 4, 7}};
    LC_EXPECT_EQ(s.minScore(4, roads), 5);

    vector<vector<int>> other{{1, 2, 2}, {1, 3, 4}, {3, 4, 7}};
    LC_EXPECT_EQ(s.minScore(4, other), 2);
}

LC_TEST(lc3532_path_existence_queries_in_a_graph_i, answers_queries_within_max_diff) {
    lc3532::Solution s;
    vector<int> nums{1, 3, 6, 8};
    vector<vector<int>> queries{{0, 3}, {0, 2}, {1, 3}};
    LC_EXPECT_EQ(s.pathExistenceQueries(4, nums, 1, queries), (vector<bool>{false, false, false}));
}

LC_TEST(lc3532_path_existence_queries_in_a_graph_i, connects_neighbours_within_tolerance) {
    lc3532::Solution s;
    vector<int> nums{2, 5, 6, 8};
    vector<vector<int>> queries{{0, 1}, {0, 2}, {1, 3}, {2, 3}};
    LC_EXPECT_EQ(s.pathExistenceQueries(4, nums, 3, queries),
                 (vector<bool>{true, true, true, true}));
}
