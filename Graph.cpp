//name: Maayan Sher
//id: 208731091
//Email: maayan1sher@gmail.com
#include "Graph.hpp"

using namespace ariel;


// Load the graph
void Graph::loadGraph(const std::vector<std::vector<int>>& graph) {

    // Check if  the matrix is square
    //if the matrix is square we throw error
    for(unsigned int i = 0; i < graph.size(); i++){
        if (graph.size() != graph[i].size()) {
            throw invalid_argument("Invalid graph: The graph is not a square matrix.");
        }

		if (graph[i][i] != 0){
			throw invalid_argument("Invalid graph.");
		}
    }
    matrix = graph;
}

// Return string of the graph 
string Graph::printGraph() const {
    int count_all_edge_connected = 0;

    for (const auto& edge : matrix) {
        for (int num : edge) {
            if (num != 0) {
                count_all_edge_connected++;
            }
        }
    }

    string result = "Graph with " + std::to_string(matrix.size()) + " vertices and " + to_string(count_all_edge_connected) + " edges.";
    return result;
}

unsigned int Graph::size() const{
    return matrix.size();
}


const int Graph::getEdge(unsigned int x, unsigned int y) const{

    // Check if we present in the bounds of the matrix
    if (x >= matrix.size() || y >= matrix[0].size()) {
        throw out_of_range("Index out of range in the matrix");
    }

    return matrix[x][y];
}


vector<unsigned int> Graph::getAllVertices(unsigned int vertex) const {

    vector<unsigned int> all_vertices;

   
    if (vertex >= matrix.size()) {
        throw out_of_range("Index out of range in the matrix");
    }

    const vector<int>& count_all_edge_connected = matrix[vertex];
    for (unsigned int i = 0; i < count_all_edge_connected.size(); ++i) {
        if (count_all_edge_connected[i] != 0) {
            all_vertices.push_back(i);//it is a coonected vertice to the vertex so add to the vector 
        }
    }

    return all_vertices;
}


// Transpose the vertices of the graph
void Graph::transpose() {
    for (size_t i = 0; i < matrix.size(); i++) {
        for (size_t j = i + 1; j < matrix.size(); j++) {

            // Swap elements at position (i, j) and (j, i)
            int temp = matrix[i][j];
            matrix[i][j] = matrix[j][i];
            matrix[j][i] = temp;
        }
    }
}