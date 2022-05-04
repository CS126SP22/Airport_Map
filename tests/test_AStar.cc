#include <catch2/catch.hpp>
#include "core/astar.h"
/**
 * 's': staring node
 * 'w': empty node
 * 'e': end node
 * 'b': the shortest path node
 * '#': the obstacle node
 */
TEST_CASE("Algorithm Tests") {
    vector<vector<char>> test_graph = {{'s', '#', '#'},
                                       {'w', '#', '#'},
                                       {'w', 'w', 'e'}};

    vector<vector<char>> solved_test_graph = {{'s', '#', '#'},
                                              {'b', '#', '#'},
                                              {'b', 'b', 'e'}};

    vec2 start = vec2(0, 0);
    vec2 end = vec2(2, 2);

    path_finding::AStar astar(test_graph, start, end);

    SECTION("Unsolved Graph Test") {
        vector<vector<char>> unsolved = astar.GetGraph();

        REQUIRE(unsolved == test_graph);
    }

    SECTION("Solved Graph Test") {
        astar.ShortestPath();

        vector<vector<char>> solved = astar.GetGraph();

        REQUIRE(solved == solved_test_graph);

    }

}