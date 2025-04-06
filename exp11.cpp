#include <iostream> 
#include <vector> 
#include <algorithm> 
using namespace std; 
 
struct Edge { 
    int u, v, weight; 
}; 
 
bool cmp(Edge a, Edge b) { 
    return a.weight < b.weight; 
} 
 
int find(int parent[], int i) { 
    if (parent[i] == -1) 
        return i; 
    return parent[i] = find(parent, parent[i]); 
} 
 
void unionSet(int parent[], int x, int y) { 
    int xset = find(parent, x); 
    int yset = find(parent, y); 
    parent[xset] = yset; 
} 
 
void kruskalMST(vector<Edge>& edges, int V) { 
    sort(edges.begin(), edges.end(), cmp); 
    int parent[V]; 
    fill(parent, parent + V, -1); 
 
    cout << "Edge \tWeight\n"; 
    for (Edge e : edges) { 
        int u = find(parent, e.u); 
        int v = find(parent, e.v); 
        if (u != v) { 
            cout << e.u << " - " << e.v << "\t" << e.weight << "\n"; 
            unionSet(parent, u, v); 
        } 
    } 
}
int main() {
    #ifdef ONLINEJUDGE
       clock_t tStart = clock();
       freopen("input.txt","r",stdin); //can need to change file . this one for taking input
       freopen("output.txt","w",stdout); // this one for output
  #endif

    vector<Edge> edges = {{0, 1, 10}, {0, 2, 6}, {0, 3, 5}, {1, 3, 15}, {2, 3, 4}}; 
    kruskalMST(edges, 4);
  
  #ifdef ONLINEJUDGE
     fprintf(stderr, "\n>> Runtime: %.10fs\n", (double) (clock() - tStart) / CLOCKS_PER_SEC); // this line gives your code runtime
  #endif
    return 0;
}
