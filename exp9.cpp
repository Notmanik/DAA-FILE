#include <iostream> 
using namespace std; 
#define INF 99999 
#define V 4 
 
void floydWarshall(int graph[V][V]) { 
    int dist[V][V]; 
    for (int i = 0; i < V; i++) 
        for (int j = 0; j < V; j++) 
            dist[i][j] = graph[i][j]; 
 
    for (int k = 0; k < V; k++) 
        for (int i = 0; i < V; i++) 
            for (int j = 0; j < V; j++) 
                if (dist[i][k] + dist[k][j] < dist[i][j]) 
                    dist[i][j] = dist[i][k] + dist[k][j]; 
 
    cout << "Shortest distances between every pair:\n"; 
    for (int i = 0; i < V; i++) { 
        for (int j = 0; j < V; j++) { 
            if (dist[i][j] == INF) 
                cout << "INF "; 
            else 
                cout << dist[i][j] << " "; 
        } 
        cout << endl; 
    } 
}
int main() {
    #ifdef ONLINEJUDGE
       clock_t tStart = clock();
       freopen("input.txt","r",stdin); //can need to change file . this one for taking input
       freopen("output.txt","w",stdout); // this one for output
  #endif

        int graph[V][V] = { 
        {0, 5, INF, 10}, 
        {INF, 0, 3, INF}, 
        {INF, INF, 0, 1}, 
        {INF, INF, INF, 0}}; 
    floydWarshall(graph);   

  #ifdef ONLINEJUDGE
     fprintf(stderr, "\n>> Runtime: %.10fs\n", (double) (clock() - tStart) / CLOCKS_PER_SEC); // this line gives your code runtime
  #endif
    return 0;
}
