#pragma once

#include "cinder/gl/gl.h"
#include "core/astar.h"

using glm::vec2;
using std::vector;

namespace path_finding {

    class Map {
    public:

        /**
         * Creates a map
         * @param top_left_corner top left position relative to the window
         * @param num_pixels_per_side how large graph should be
         * @param graph_size How large graph will be in real pixels
         */
        Map(const vec2 &top_left_corner, const vec2 &num_pixels_per_side,
              const vec2 &graph_size);

        /**
         * Draws the graph as a visual representation
         * @param array which graph to draw
         */
        void Draw(std::vector<std::vector<char>> array) const;

        /**
         * Colors cells on the graph if clicked on
         * @param brush_screen_coords coordinates of the mouse
         * @param draw_point whether to draw a point or obstacle
         * @param start_point whether to draw the start or end point
         */
        void Brush(const glm::vec2 &brush_screen_coords, bool draw_point, bool start_point);

        /**
         * Set all of the sketchpad pixels to an unshaded state.
         */
        void Clear();

        /**
         * Runs the A star algorithm and finds a path between the 2 points
         */
        void DrawPath();

        /**
         * Show or Hide the shortest Path if the button is clicked
         */
        void ShowPath();

        /**
         * Calls Draw on either the graph or solved graph
         */
        void DrawHelper() const;

        /**
         * The overloading insertion operator. Write the current map to stream
         * @param os ostream output
         * @param graph the map instance
         */
        friend std::ostream &operator<<(std::ostream &os, Map &map);

        /**
         * The overloading extraction operator. Read the stream into a map
         * @param in istream input
         * @param map the map instance
         */
        friend std::istream &operator>>(std::istream &is, Map &map);

        /**
         * For testing purposes, returns the drawing
         * @return the graph
         */
        std::vector<std::vector<char>> GetGraph();

    private:
        vec2 top_left_corner_;
        vec2 num_pixels_per_side_;
        size_t pixel_side_length_;
        //The coordinate of starting point
        vec2 start_point_coords_;
        //The coordinate of ending point
        vec2 end_point_coords_;
        //The 2D char array representing the graph without the shortest path
        vector<vector<char>> graph_;
        //The 2D char array representing the graph with the shortest path
        vector<vector<char>> solved_graph_;
        bool show_path_ = false;

    };

}