
#pragma once

#include <vector>
#include <algorithm>

#include "graph.h"
#include "edge.h"
using namespace std;


namespace path_finding{
    class Dijkstra {
    public:

        Dijkstra(Graph & g);

        /*
         * Helper function，calculating the shortest path between the source and dest airports
         * @param   source    source airport's name
         * @param   dest      destination airport's name
         * @param   g         input graph
         * @return  shortestPath_(g_, source, dest)    g_is the graph created, the vertex include source, destination, and stop's airportname
         */
        std::pair<int, std::vector<Vertex> > shortestPath(Vertex source, Vertex dest);


        const Graph & getGraph() const;



        class myComparator{
        public:
            int operator() (std::pair<Vertex, int> p1, std::pair<Vertex, int> p2){
                return p1.second > p2.second;
            }
        };

    private:
        Graph & g_;

        /*
         * Helper function，calculating the shortest path between the source and dest airports
         * @param   source    source node's name
         * @param   dest      destination node's name
         * @param   g         input graph
         * @return  pair<int,vertex>    int says the path length, the vertex include source, destination, and stop's airportname
         */
        std::pair<int, std::vector<Vertex> > shortestPath_(Graph g, Vertex source, Vertex dest);
    };
}
