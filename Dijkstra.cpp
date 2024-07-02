/*
Dijkstra Code
jcasilimas coder 
May 21, 2024 
*/

#include <iostream>
#include <vector>
#include <list>
#include <queue>
#include <limits>
#include <cstdlib>
#include <ctime>

using namespace std;

//graph class representing an undirected graph using an adjency list
class Graph{
private:
    int V;
    vector<list<pair<int, double>>> adjlist;

public:
    //constructor to initialize graph with a given number of vertices
    Graph(int vertices) : V(vertices), adjlist(vertices) {}
    //method to add and edge beetwen two vertices with a given weight
    void addedge(int u, int v, double weight) {
        adjlist[u].push_back(make_pair(v, weight));
        adjlist[v].push_back(make_pair(u, weight)); //since the graph is undirected
    }

    //method to get the neighbor of a vertex
    vector<pair<int, double>> neighbor(int u) const{
        return vector<pair<int, double>>(adjlist[u].begin(),adjlist[u].end());
    }

    //method the number of vertices in the graph
    int size() const{
        return V;
    }

    //method to print the graph
    void print() const{
        for (int i = 0; i < V; i++){
            cout << "vertex" << i << ", ";
            for (const auto& neighbor : adjlist[i]) {
                cout << " (" << neighbor.first << ", " << neighbor.second << ")";
            }
            cout << endl;
        }
    }
};

//shortest path class to implement dijkstra's algorithm
class shortestpath{
private:
    const Graph& graph; //reference to the graph

public:
    shortestpath(const Graph& g) : graph(g) {} //constructor to initialize given graph

    //method to compute the shortest path from src to dest using dijkstra's algorithm
    double dijkstra(int src, int dest){
        vector<double> dist(graph.size(), numeric_limits<double>::infinity());
        dist[src] = 0.0;

        //priority queue to store the shortest distance
        priority_queue<pair<double, int>, vector<pair<double, int>>, greater<>> pq;
        pq.push(make_pair(0.0, src));

        while(!pq.empty()) {
            int u = pq.top().second;
            pq.pop();

            for(const auto& neighbor : graph.neighbor(u)){
                int v = neighbor.first;
                double weight = neighbor.second;

                if(dist[u] + weight < dist[v]){
                    dist[v] = dist[u] + weight;
                    pq.push(make_pair(dist[v], v));
                }
            }        
        }

        return dist[dest];
    }

    //method to compute the average shortest path lenght from a given start vertex
    double averageshortestpath(int start){
        double totalpathlength = 0.0;
        int reachableNodes = 0;

        //compute shortest path from start to all other vertices
        for(int i = 0; i < graph.size(); i++){
            if(i != start){
                double pathlength = dijkstra(start, i);
                if(pathlength < numeric_limits<double>::infinity()){
                    totalpathlength += pathlength;
                    reachableNodes++;
                }
            }
        }

        return reachableNodes ? totalpathlength / reachableNodes : 0.0;
    }
};

//function to generate a random graph
Graph generaterandomgraph(int vertices, double density, double DistanceRangeMin, double DistanceRangeMax){
    Graph graph(vertices);
    srand(time(0));

    //iterate through all possible undirected edges
    for(int i = 0; i < vertices; ++i){
        for(int j = i + 1; j < vertices; j++){
            double prob = static_cast<double>(rand()) / RAND_MAX;
            if (prob < density){
                
                double distance = DistanceRangeMin + (static_cast<double>(rand()) / RAND_MAX) * (DistanceRangeMax - DistanceRangeMin);
                graph.addedge(i, j, distance);
            }
        }
    }
    return graph;
}

int main(){
    int vertices = 50;
    double density1 = 0.2;
    double density2 = 0.4;
    double DistanceRangeMin = 1.0;
    double DistanceRangeMax = 10.0;
    
    Graph graph1 = generaterandomgraph(vertices, density1, DistanceRangeMin, DistanceRangeMax);
    Graph graph2 = generaterandomgraph(vertices, density2, DistanceRangeMin, DistanceRangeMax);

    shortestpath sp1(graph1);
    shortestpath sp2(graph2);

    cout << "Graph 1 with 20% density:" << endl;
    graph1.print();
    cout << "Average shortest path lenght from vertex 1: " << sp1.averageshortestpath(1) << endl;

    cout << "Graph 2 with 40% density:" << endl;
    graph2.print();
    cout << "Average shortest path lenght from vertex 1: " << sp2.averageshortestpath(1) << endl;

    return 0;
}