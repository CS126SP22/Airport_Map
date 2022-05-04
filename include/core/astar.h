//
// Created by Shuo Wang on 4/29/22.
//

#pragma once

#include "cinder/gl/gl.h"
#include <vector>

using ci::vec2;
using std::vector;

namespace path_finding {

    class AStar {

    public:

        /**
         * Creates An array of nodes given a 2D vector of characters
         * @param graph       2D Vector of Chars
         * @param start_pos   Position of start point in the graph
         * @param end_pos     Position of end point in the graph
         */
        AStar(const vector<vector<char>> &graph, const vec2 &start,
              const vec2 &end);

        /**
         * Finds the shortest path from the start point to end point
         */
        void ShortestPath();

        /**
         * Returns the map held by the algorithm, whether solved or unsolved
         * @return the map
         */
        vector<vector<char>> GetGraph() const;

    private:
        struct Node {
            //Is the Node an obstacle
            bool obstacle = false;
            //Have the Node been visited
            bool visited = false;
            float_t global_dist;
            float_t local_dist;
            //The Node's x coordinate
            float_t x;
            //The Node's y coordinate
            float_t y;
            //The Node's neighboring nodes
            vector<Node *> neighbors;
            //In the shortest path, the Node's parent node
            Node *parent;
        };

        //The array of nodes
        Node *nodes_;
        //The pointer to the starting node in the array
        Node *start_node_ = nullptr;
        //The pointer to the ending node in the array
        Node *end_node_ = nullptr;
        //The height of graph
        size_t graph_height_;
        //The width of graph
        size_t graph_width_;
        /** 2D array of chars representing the graph
         * 's': staring node
         * 'w': empty node
         * 'e': end node
         * 'b': the shortest path node
         * '#': the obstacle node
         */
        vector<vector<char>> graph_;

        /**
         * After Solving the algorithm, it updates the 2D vector of chars to show the path found by the algo
         */
        void UpdateGraph();

    };

} // namespace path_finding

