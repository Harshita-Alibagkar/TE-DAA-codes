#include<iostream>
#include<limits.h>

using namespace std;

// Define a structure to represent an edge
struct Edge {
    int src, dest, weight;
};

// Define a structure to represent a graph
struct Graph {
    int V, E; // Number of V and edges
    struct Edge* edge; // Array of edges
};

// Create a new graph with V V and E edges
struct Graph* createGraph(int V, int E) {
    struct Graph* graph = new Graph;
    graph->V = V;
    graph->E = E;
    graph->edge = new Edge[E];
    return graph;
}

// Perform Bellman-Ford algorithm to find shortest paths from src
void bellmanFord(struct Graph* graph, int src) {
    int V = graph->V;
    int E = graph->E;
    int dist[V];

    // Initialize distances from the src to all V as infinite
    for (int i = 0; i < V; i++) {
        dist[i] = INT_MAX;
    }
    dist[src] = 0;

    // Relax all edges |V| - 1 times
    for (int i = 1; i <= V - 1; i++) {
        for (int j = 0; j < E; j++) {
            int u = graph->edge[j].src;
            int v = graph->edge[j].dest;
            int weight = graph->edge[j].weight;
            if (dist[u] != INT_MAX && dist[u] + weight < dist[v]) {
                dist[v] = dist[u] + weight;
            }
        }
    }

    // Check for negative-weight cycles
    for (int i = 0; i < E; i++) {
        int u = graph->edge[i].src;
        int v = graph->edge[i].dest;
        int weight = graph->edge[i].weight;
        if (dist[u] != INT_MAX && dist[u] + weight < dist[v]) {
            cout << "Graph contains negative-weight cycle!" << endl;
            return;
        }
    }

    // Print the distance array
    cout << "Vertex\tDistance from src" << endl;
    for (int i = 0; i < V; i++) {
        cout << i << "\t" << dist[i] << endl;
    }
}

int main() {
    int V = 5; // Number of V
    int E = 8; // Number of edges
    struct Graph* graph = createGraph(V, E);

    // Add edges
    graph->edge[0] = {0, 1, -1};
    graph->edge[1] = {0, 2, 4};
    graph->edge[2] = {1, 2, 3};
    graph->edge[3] = {1, 3, 2};
    graph->edge[4] = {1, 4, 2};
    graph->edge[5] = {3, 2, 5};
    graph->edge[6] = {3, 1, 1};
    graph->edge[7] = {4, 3, -3};

    int src = 2; // src vertex

    bellmanFord(graph, src);

    return 0;
}

#include <iostream>
#include <vector>
#include <climits>

using namespace std;

struct Edge {
    int src, destination, weight;
}; 

void BellmanFord(vector<Edge>& edges, int V, int src) {
    vector<int> distance(V, INT_MAX); //distance(initial_size, value of each element)
    distance[src] = 0;

    for (int i = 0; i < V - 1; i++) {
        for (Edge& edge : edges) {
            if (distance[edge.src] != INT_MAX && distance[edge.src] + edge.weight < distance[edge.destination]) {
                distance[edge.destination] = distance[edge.src] + edge.weight;
            }
        }
    }

    for (Edge& edge : edges) {
        if (distance[edge.src] != INT_MAX && distance[edge.src] + edge.weight < distance[edge.destination]) {
            cout << "Negative cycle detected. Bellman-Ford algorithm does not work in this case." << endl;
            return;
        }
    }

    cout << "Vertex\tDistance from src" << endl;
    for (int i = 0; i < V; i++) {
        cout << i << "\t" << distance[i] << endl;
    }
}

int main() {
    int V, edgesCount;
    cout << "Enter the number of V: ";
    cin >> V;
    cout << "Enter the number of edges: ";
    cin >> edgesCount;

    vector<Edge> edges(edgesCount);

    for (int i = 0; i < edgesCount; i++) {
        cout << "Enter src, destination, and weight of edge " << i + 1 << ": ";
        cin >> edges[i].src >> edges[i].destination >> edges[i].weight;
    }

    int src;
    cout << "Enter the src vertex: ";
    cin >> src;

    BellmanFord(edges, V, src);

    return 0;
}
