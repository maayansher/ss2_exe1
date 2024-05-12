//name: Maayan Sher
//id: 208731091
//Email: maayan1sher@gmail.com
#pragma once

#include <iostream>
#include <vector>

using namespace std;

namespace ariel{
    class Graph{
        // representation of the graph by adjency matrix
        vector<vector<int>> matrix; 

    public:
        /**
         * loads a new graph from an adjacency matrix.
         */
        void loadGraph(const vector<vector<int>>& graph);

        /**
         * return a string  of the adjacency matrix.
         */
        string printGraph() const;

        /**
         * return the number of vertices in the graph.
         */
        unsigned int size() const;

        /**
         * return  the weight of the edge between two vertices. 
         * If no edge  returns 0.
         */
        const int getEdge(unsigned int x, unsigned int y) const;

        /**
         * return all vertices that connected to specidific vertex 
         */
        vector<unsigned int> getAllVertices(unsigned int vertex) const;

        /**
         * Transposes the graph by swapping the rows and columns of the adjacency matrix.
         */
        void transpose();
    };
}