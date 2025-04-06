#include <iostream> 
#include <vector> 
#include <queue> 
using namespace std; 
 
const int INF = 1e9; 
 
void dijkstra(int V, vector<pair<int, int>> adj[], int src) { 
    vector<int> dist(V, INF); 
    priority_queue<pair<int, int>, vector<pair<int, int>>, greater<>> pq; 
 
    dist[src] = 0; 
    pq.push({0, src}); 
 
    while (!pq.empty()) { 
        int u = pq.top().second; 
        pq.pop(); 
 
        for (auto& edge : adj[u]) { 
            int v = edge.first; 
            int wt = edge.second; 
            if (dist[u] + wt < dist[v]) { 
                dist[v] = dist[u] + wt; 
                pq.push({dist[v], v}); 
            } 
        } 
    } 
 
    for (int i = 0; i < V; i++) 
        cout << "Distance from " << src << " to " << i << ": " << dist[i] << endl; 
}
int main() {
    #ifdef ONLINEJUDGE
       clock_t tStart = clock();
       freopen("input.txt","r",stdin); //can need to change file . this one for taking input
       freopen("output.txt","w",stdout); // this one for output
  #endif

       int V = 5; 
    vector<pair<int, int>> adj[V]; 
    adj[0].push_back({1, 10}); 
    adj[0].push_back({4, 5}); 
    adj[1].push_back({2, 1}); 
    adj[1].push_back({4, 2}); 
    adj[2].push_back({3, 4}); 
    adj[3].push_back({0, 7}); 
    adj[4].push_back({1, 3}); 
    adj[4].push_back({2, 9}); 
    adj[4].push_back({3, 2}); 
 
    dijkstra(V, adj, 0);
       


       
  #ifdef ONLINEJUDGE
     fprintf(stderr, "\n>> Runtime: %.10fs\n", (double) (clock() - tStart) / CLOCKS_PER_SEC); // this line gives your code runtime
  #endif
    return 0;
}
