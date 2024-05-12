//name: Maayan Sher
//id: 208731091
//Email: maayan1sher@gmail.com

#include "doctest.h"
#include "Algorithms.hpp"
#include "Graph.hpp"


using namespace std;

TEST_CASE("ALL FUNCTIONS")
{
    ariel::Graph g;
    vector<vector<int>> graph = {
        {0, 1, 0, 0},
        {1, 0, 1, 0},
        {0, 1, 0, 1},
        {0, 0, 1, 0}};
    g.loadGraph(graph);
    CHECK(ariel::Algorithms::isConnected(g) == true);
    CHECK(ariel::Algorithms::shortestPath(g, 0, 3) == "0->1->2->3");
    CHECK(ariel::Algorithms::shortestPath(g, 0, 2) == "0->1->2");
    CHECK(ariel::Algorithms::isContainsCycle(g) == "0");
    CHECK(ariel::Algorithms::isBipartite(g) == "The graph is bipartite: color1={0, 2}, color2={1, 3}.");
  //  CHECK(ariel::Algorithms::negativeCycle(g) == "The graph contains negative cycle");
    CHECK(ariel::Algorithms::shortestPath(g, 1, 2) == "1->2");
}

TEST_CASE("Test Function isConnected")
{
    ariel::Graph g;

    vector<vector<int>> graph = {
        {0, 1, 0},
        {1, 0, 1},
        {0, 1, 0}};
    g.loadGraph(graph);
    CHECK(ariel::Algorithms::isConnected(g) == true);

	// Not connected
    vector<vector<int>> graph2 = {
        {0, 1, 1, 0, 0},
        {1, 0, 1, 0, 0},
        {1, 1, 0, 1, 0},
        {0, 0, 1, 0, 0},
        {0, 0, 0, 0, 0}};
    g.loadGraph(graph2);
    CHECK(ariel::Algorithms::isConnected(g) == false);
    
}

TEST_CASE("Test shortestPath")
{
    ariel::Graph g;
    vector<vector<int>> graph = {
        {0, 1, 0},
        {1, 0, 1},
        {0, 1, 0}};
    g.loadGraph(graph);
    CHECK(ariel::Algorithms::shortestPath(g, 0, 2) == "0->1->2");

    vector<vector<int>> graph2 = {
        {0, 1, 1, 0, 0},
        {1, 0, 1, 0, 0},
        {1, 1, 0, 1, 0},
        {0, 0, 1, 0, 0},
        {0, 0, 0, 0, 0}};
    g.loadGraph(graph2);
    CHECK(ariel::Algorithms::shortestPath(g, 0, 4) == "-1");
    
    vector<vector<int>> graph3 = {
        {0, 2, 0, -1},
        {2, 0, 3, 0},
        {0, 3, 0, 4},
        {-1, 0, 4, 0}};
    g.loadGraph(graph3);
    CHECK(ariel::Algorithms::shortestPath(g, 0, 3) == "No shortest path because found negative cycle.");
}

TEST_CASE("Test isContainsCycle")
{
    ariel::Graph g;
    vector<vector<int>> graph = {
        {0, 1, 0},
        {1, 0, 1},
        {0, 1, 0}};
    g.loadGraph(graph);
    CHECK(ariel::Algorithms::isContainsCycle(g) == "0");

    vector<vector<int>> graph2 = {
        {0, 1, 1, 0, 0},
        {1, 0, 1, 0, 0},
        {1, 1, 0, 1, 0},
        {0, 0, 1, 0, 0},
        {0, 0, 0, 0, 0}};
    g.loadGraph(graph2);
    CHECK(ariel::Algorithms::isContainsCycle(g) == "The cycle is: 0->2->1->0");
}


TEST_CASE("Test negativeCycle")
{
    ariel::Graph g;
    vector<vector<int>> graph = {
        {0, -1, 1, 0, 0},
        {-1, 0, 1, 0, 0},
        {1, 1, 0, 1, 0},
        {0, 0, 1, 0, 0},
        {0, 0, 0, 0, 0}};
    g.loadGraph(graph);
    CHECK(ariel::Algorithms::negativeCycle(g) == "The graph contains negative cycle");

    vector<vector<int>> graph2 = {
        {0, 1, 1, 0, 0},
        {1, 0, 1, 0, 0},
        {1, 1, 0, 1, 0},
        {0, 0, 1, 0, 0},
        {0, 0, 0, 0, 0}};
    g.loadGraph(graph2);
    CHECK(ariel::Algorithms::negativeCycle(g) == "The graph not contains negative cycle");
}
TEST_CASE("Test isBipartite")
{
    ariel::Graph g;
    vector<vector<int>> graph = {
        {0, 1, 0},
        {1, 0, 1},
        {0, 1, 0}};
    g.loadGraph(graph);
    CHECK(ariel::Algorithms::isBipartite(g) == "The graph is bipartite: color1={0, 2}, color2={1}.");

    vector<vector<int>> graph1 = {
        {0, 1},
        {1, 0}};
    g.loadGraph(graph1);
    CHECK(ariel::Algorithms::isBipartite(g) == "The graph is bipartite: color1={0}, color2={1}.");

    vector<vector<int>> graph2 = {
        {0, 0},
        {0, 0}};
    g.loadGraph(graph2);
    CHECK(ariel::Algorithms::isBipartite(g) == "The graph is bipartite: color1={0, 1}, color2={}.");

    vector<vector<int>> graph3 = {
        {0, 1, 1, 1, 1},
        {1, 0, 1, 1, 1},
        {1, 1, 0, 1, 1},
        {1, 1, 1, 0, 1},
        {1, 1, 1, 1, 0}};
    g.loadGraph(graph3);
    CHECK(ariel::Algorithms::isBipartite(g) == "The graph is not bipartite");

}


TEST_CASE("Test negative cycles"){
   ariel::Graph g;

 
    vector<vector<int>> graph = {
        {0, -1, 2},
        {-1, 0, -3},
        {2, -3, 0}};

    g.loadGraph(graph);
     CHECK(ariel::Algorithms::negativeCycle(g) == "The graph contains negative cycle");
	
	vector<vector<int>> graph1 = {
        {0, 1, 0},
        {0, 0, 2},
        {-10, 0, 0}};

    g.loadGraph(graph1);
    CHECK(ariel::Algorithms::negativeCycle(g) == "The graph contains negative cycle");

}

TEST_CASE("Test no valid graph")
{
    ariel::Graph g;
    vector<vector<int>> graph = {
        {0, 1, 1, 0},
        {1, 0, 1, 0},
        {1, 1, 0, 1},
        {0, 0, 1, 0},
        {0, 0, 0, 1}};
    CHECK_THROWS(g.loadGraph(graph));
}

