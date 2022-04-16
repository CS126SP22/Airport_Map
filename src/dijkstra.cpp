//
// Created by Shuo Wang on 4/15/22.
//

#include "dijkstra.h"
#include <ctime>
#include <iostream>
#include <string>
#include <vector>
#include "graph.h"
#include <cmath>
#include <map>
#include <queue>
#include <limits>

using namespace std;

namespace path_finding{


    Dijkstra::Dijkstra(Graph & g) : g_(g){
    }

    std::pair<int, std::vector<Vertex> > Dijkstra::shortestPath(Vertex source, Vertex dest){
        return shortestPath_(g_, source, dest);
    }


    std::pair<int, std::vector<Vertex> > Dijkstra::shortestPath_(Graph g, Vertex source, Vertex dest){
        int distances = 0;
        std::map<Vertex, Vertex> previous;
        priority_queue<std::pair<Vertex, int>, vector<std::pair<Vertex, int>>, Dijkstra::myComparator> q;
        std::map<Vertex, int> node_to_dist;
        std::vector<Vertex> vertices = g.getVertices();
        for(Vertex & v : vertices){
            if(v != source){
                node_to_dist[v] = std::numeric_limits<int>::max();
            }else{
                node_to_dist[v] = 0;
            }
        }
        q.push(std::make_pair(source, 0));
        std::vector<Vertex> visited;
        while (q.top().first != dest){
            std::pair<Vertex, int> cur = q.top();
            q.pop();
            std::vector<Vertex> neighbors = g.getAdjacent(cur.first);
            for(Vertex & v : neighbors){
                if(std::find(visited.begin(), visited.end(), v) == visited.end()){
                    int cur_distance = node_to_dist[cur.first] + g.getEdgeWeight(cur.first, v);
                    if(cur_distance < node_to_dist[v]){
                        node_to_dist[v] = cur_distance;
                        auto it = node_to_dist.find(v);
                        q.push(*it);
                        previous[v] = cur.first;
                    }
                }
            }
            visited.push_back(cur.first);
        }
        distances = node_to_dist[dest];
        Vertex cur = dest;
        vector<Vertex> path;
        path.push_back(dest);
        while (previous[cur] != source){
            cur = previous[cur];
            path.push_back(cur);
        }
        if(path.back() != source){
            path.push_back(source);
        }

        std::reverse(path.begin(),path.end());
        return std::make_pair(distances, path);
    }



/**
 * Returns a constant reference to the state space graph.
 *
 * @returns A constant reference to the state space graph.
 */
    const Graph & Dijkstra::getGraph() const {
        return g_;
    }


}