# ss2_exe1
## Descrtiption:
The following project implementing an algorithms for graph analysis such as: find the shortest path,detecting cycles,
check if theres negative cycle, check if the graph is connected and check if a graph is bipartite.

The algorithms supports weighted/unweighted graphs and also directed/undirected graphs.
Noted that the algorithms accpets adjacency matrix only means it can only get square matrix as input.

## How to run the project
Use the provided `makefile` to build and run the project:
    
   - To build main:
        ```bash
        make all
        ```
  - To build tests:
      ```bash
      make test
      ```
  - To check for memory leaks using Valgrind:
      ```bash
      make valgrind
      ```

### Run the project
After compiling and building the wanted file:

- To run the demo
  ```bash
  ./demo
  ```
- To run the tests
  ```bash
  ./test
  ```

### Clean compiled files
To clean compiled files, run the command:
```bash
  make clean
  ```
## File included
`Graph.cpp` and `Graph.hpp` - implementation file and header file for graph data structure.

`Algorithms.cpp` and `Algorithms.hpp` - implementation file and header file for graph algorithms.

`demo.cpp` - demo file show the cases of implmented algorithms.

`Test.cpp` - inside the test file we are checking different cases of each graph to show correctness and to detect fails. 

`TestCounter.cpp` - the TestCounter checks if we implemented at lease 20 tests.

## Functions
- Graph functions:
  
`loadGraph` - Load a matrix to present a graph. The loadGraph supports square matrix only (otherwise throw error).

`printGraph` - Print how many vertices and edges in the following graph.

`size` - Return the number of vertices in the graph.

`getEdge` - Return the weight of the edge between two vertices.

`getAllVertices` - Return all vertices that connected to a specific vertex.

`transpose` - Transpose the graph by swapping the row and columns of the matrix.

- Algorithms functions:
  

`isConnected` - Determine if the graph is strongly connected, which means theres a path between each 2 vertices.

`shortestPath` - Finding the shortest path between any 2 vertices using the Bellman-ford algorithms, since the function can get a graph with negative weights as well.

`isContainsCycle` - Checks if the graph contains a cycle in it, if so, return the vertices who build the cycle.

`isBipartite` - Checks if the graph is bipartite which mean we can seperate the vertices to two colors that no two adjacent verices share the same color.

`negativeCycle` - Checks if the graph contain a negative cycle.
