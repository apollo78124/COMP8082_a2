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
        /*
         * queued vertex will have indegree -1 instead of 0 to differentiate
         */
        vector<int>    indegrees;
        int graphSize;
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
        /*
         * Only returns vertexes with 0 indegrees
         * If there is no vertex with indegree 0, returns -2
         */
        int GetMinDegIndex() {
            int index = 0;
            for (int deg : indegrees) {
                if (deg == 0) {
                    return index;
                }
                index++;
            }
            return -2;
        }

        // Topological sort
        // Complete this function to perform the topological sort.
        // Use the method describe in the textbook using "indegrees".
        string TopologicalSort() {
            std::ostringstream os;
            // Use the GetMinDegIndex() function
            // Use cout to print out the index of each vertex in order.
            int queued = 0;
            while (queued < graphSize) {
                int minDegInd = GetMinDegIndex();

                if (minDegInd > -1) {
                    os << adjList[minDegInd].label << " ";
                    indegrees[minDegInd] = -1;
                    for (int i : adjList[minDegInd].adj) {
                        indegrees[i]--;
                    }
                    queued++;
                } else {
                    /*
                     * When there is no indegree 0 in the graph, return message it is a cyclic graph where topological sort is not possible.
                     */
                    os << "Cyclic graph; Topological Sort is not possible" << endl;
                    break;
                }
            }


            os << endl;
            return os.str();
        }

        template <size_t n>
        void CreateGraph(int (&adjacencyMatrix)[n][n]) {
            int outDegree;
            Vertex vertex;

            /**
             * Clears the adjList object before creating a new graph
             */
            adjList.clear();
            graphSize = n;
            Resize(n);
            for (int i = 0; i < n; i++) {
                outDegree = 0;
                for (int k = 0; k < n; k++) outDegree += adjacencyMatrix[i][k];
                vertex.label = i;
                for (int j = 0; j<n; j++) {
                    if (adjacencyMatrix[i][j] == 1)
                      vertex.adj.push_back(j);
                }
                Insert(vertex);
                vertex.adj.clear();
            }
        }
};

#endif //GRAPH_H
