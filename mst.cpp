/*
MST Kruskal 
jcasilimas coder 
May 28, 2024 
*/

#include <iostream>
#include <vector>
#include <fstream>
#include <algorithm>

using namespace std;

class Edge {
public:
    int src, dest, weight;
    Edge(int s, int d, int w) : src(s), dest(d), weight(w) {}
};

// Compare two edges according to their weight.
bool compareEdge(Edge a, Edge b) {
    return a.weight < b.weight;
}

class Graph {
public:
    int V;
    vector<Edge> edges;

    // Constructor that reads the graph from a file.
    Graph(const string &filename) {
        ifstream infile(filename);
        if (!infile) {
            cerr << "Could not open the file." << endl;
            exit(1);
        }
        infile >> V;
        int src, dest, weight;
        while (infile >> src >> dest >> weight) {
            edges.push_back(Edge(src, dest, weight));
        }
        infile.close();
    }

    // Method to find the MST using Kruskal's algorithm.
    void kruskalMST() {
        // Sort the edges by weight.
        sort(edges.begin(), edges.end(), compareEdge);

        // Create a vector to represent the subset of each vertex.
        vector<int> parent(V);
        for (int i = 0; i < V; ++i)
            parent[i] = i;

        vector<Edge> result; // Stores the resulting MST.

        int e = 0; // Initialize the counter for edges in the MST.
        int i = 0; // Initialize the counter for the sorted edges.

        // Number of edges in an MST is V-1.
        while (e < V - 1 && i < edges.size()) {
            Edge next_edge = edges[i++];

            int x = find(parent, next_edge.src);
            int y = find(parent, next_edge.dest);

            // If including this edge does not cause a cycle,
            // include it in the result and update the subset.
            if (x != y) {
                result.push_back(next_edge);
                Union(parent, x, y);
                e++;
            }
        }

        // Print the resulting MST.
        cout << "The edges in the MST are:" << endl;
        int minimumCost = 0;
        for (i = 0; i < result.size(); ++i) {
            cout << result[i].src << " -- " << result[i].dest << " == " << result[i].weight << endl;
            minimumCost += result[i].weight;
        }
        cout << "Minimum cost of the MST: " << minimumCost << endl;
    }

private:
    // Find the set of an element i.
    int find(vector<int> &parent, int i) {
        if (parent[i] != i)
            parent[i] = find(parent, parent[i]);
        return parent[i];
    }

    // Union of two subsets.
    void Union(vector<int> &parent, int x, int y) {
        int xroot = find(parent, x);
        int yroot = find(parent, y);
        parent[xroot] = yroot;
    }
};

int main() {
    Graph g("SampleTestData.txt");
    g.kruskalMST();
    return 0;
}
