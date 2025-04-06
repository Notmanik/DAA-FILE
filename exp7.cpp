#include <iostream> 
#include <vector> 
using namespace std; 
 
struct Edge { 
    int u, v, wt; 
}; 
 
void bellmanFord(int V, int E, vector<Edge>& edges, int src) { 
    vector<int> dist(V, 1e9); 
    dist[src] = 0; 
 
    for (int i = 1; i <= V - 1; i++) { 
        for (auto& edge : edges) { 
            if (dist[edge.u] + edge.wt < dist[edge.v]) 
                dist[edge.v] = dist[edge.u] + edge.wt; 
        } 
    } 
 
    // Check for negative-weight cycles 
    for (auto& edge : edges) { 
        if (dist[edge.u] + edge.wt < dist[edge.v]) { 
            cout << "Graph contains negative weight cycle" << endl; 
            return; 
        } 
    } 
 
    for (int i = 0; i < V; i++) 
        cout << "Distance from source to " << i << " is " << dist[i] << endl; 
}

int main() {
    #ifdef ONLINEJUDGE
       clock_t tStart = clock();
       freopen("input.txt","r",stdin); //can need to change file . this one for taking input
       freopen("output.txt","w",stdout); // this one for output
  #endif
           int V = 5, E = 8; 
    vector<Edge> edges = { 
        {0, 1, -1}, {0, 2, 4}, {1, 2, 3}, {1, 3, 2}, 
        {1, 4, 2}, {3, 2, 5}, {3, 1, 1}, {4, 3, -3} 
    }; 
    bellmanFord(V, E, edges, 0);


       
  #ifdef ONLINEJUDGE
     fprintf(stderr, "\n>> Runtime: %.10fs\n", (double) (clock() - tStart) / CLOCKS_PER_SEC); // this line gives your code runtime
  #endif
    return 0;
}
