#ifndef GRAPH_H
#define GRAPH_H
/*
  Finds a topological sort for a graph stored as adjacency list
  Since the STL priority queue does not support decrease key
  we use a vector of indegrees
  Assumes vertices are labeled 0 - (|V| -1)
*/
using namespace std;

#include<sstream>

// Define vertex in a graph
struct Vertex {
    int label;          // vertex label
    vector<int> adj;    // list of adjacent vertices
};

// Simple graph class
class Graph {
    private:
        vector<Vertex> adjList;
        vector<int>    indegrees;
    public:
        // Constructors
        explicit Graph(int size) : indegrees(size,0) {}
        Graph() = default;

        // Resize number of vertices
        void Resize(int size) {
            indegrees.resize(size);
            for (int i = 0; i < size; i++)
                indegrees[i] = 0;
        }

        // Add vertex V
        void Insert(const Vertex&  V) {
            adjList.push_back(V);
            for (int i : V.adj)
                indegrees[i]++;
        }

        // Get index of vertex with lowest indegree
        // Complete this function to find the index of the vertex
        //  with the lowest indegree.
        int GetMinDegIndex() {
            return 0;
        }

        // Topological sort
        // Complete this function to perform the topological sort.
        // Use the method describe in the textbook using "indegrees".
        string TopologicalSort() {
            std::ostringstream os;
            // Use the GetMinDegIndex() function
            // Use cout to print out the index of each vertex in order.
            os << endl;
            return os.str();
        }

        template <size_t n>
        void CreateGraph(int (&adjacencyMatrix)[n][n]) {
            int outDegree;
            Vertex vertex;
            Resize(n);
            for (int i = 0; i < n; i++) {
                outDegree = 0;
                for (int k = 0; k < n; k++) outDegree += adjacencyMatrix[i][k];
                vertex.label = i;
                for (int j = 0; j<outDegree; j++) {
                    if (adjacencyMatrix[i][j] == 1)
                      vertex.adj.push_back(j);
                }
                Insert(vertex);
                vertex.adj.clear();
            }
        }
};

#endif //GRAPH_H