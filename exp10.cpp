#include <iostream> 
#include <vector> 
#include <climits> 
using namespace std; 
#define V 5 
 
int minKey(vector<int>& key, vector<bool>& mstSet) { 
    int min = INT_MAX, min_index; 
    for (int v = 0; v < V; v++) 
        if (!mstSet[v] && key[v] < min) 
            min = key[v], min_index = v; 
    return min_index; 
} 
 
void primMST(int graph[V][V]) { 
    vector<int> parent(V); 
    vector<int> key(V, INT_MAX); 
    vector<bool> mstSet(V, false); 
 
    key[0] = 0; 
    parent[0] = -1; 
 
    for (int count = 0; count < V - 1; count++) { 
        int u = minKey(key, mstSet); 
        mstSet[u] = true; 
 
        for (int v = 0; v < V; v++) 
            if (graph[u][v] && !mstSet[v] && graph[u][v] < key[v]) 
                parent[v] = u, key[v] = graph[u][v]; 
    } 
 
    cout << "Edge \tWeight\n"; 
    for (int i = 1; i < V; i++) 
        cout << parent[i] << " - " << i << "\t" << graph[i][parent[i]] << "\n"; 
}
int main() {
    #ifdef ONLINEJUDGE
       clock_t tStart = clock();
       freopen("input.txt","r",stdin); //can need to change file . this one for taking input
       freopen("output.txt","w",stdout); // this one for output
  #endif

           int graph[V][V] = { 
        {0, 2, 0, 6, 0}, 
        {2, 0, 3, 8, 5}, 
        {0, 3, 0, 0, 7}, 
        {6, 8, 0, 0, 9}, 
        {0, 5, 7, 9, 0}}; 
 
    primMST(graph); 
    return 0;
       


       
  #ifdef ONLINEJUDGE
     fprintf(stderr, "\n>> Runtime: %.10fs\n", (double) (clock() - tStart) / CLOCKS_PER_SEC); // this line gives your code runtime
  #endif
    return 0;
}
