#include <iostream>
#include <vector>
using namespace std;

#define NUM_VERTICES 4

void greedyColoring(vector<int> adj[], int V) {
    vector<int> result(V, -1);
    result[0] = 0;

    vector<bool> available(V, false);

    for (int u = 1; u < V; u++) {
        for (int i : adj[u])
            if (result[i] != -1)
                available[result[i]] = true;

        int cr;
        for (cr = 0; cr < V; cr++)
            if (!available[cr]) break;

        result[u] = cr;
        fill(available.begin(), available.end(), false);
    }

    for (int u = 0; u < V; u++)
        cout << "Vertex " << u << " ---> Color " << result[u] << endl;
}

int main() {
    #ifdef ONLINEJUDGE
        clock_t tStart = clock();
        freopen("input.txt","r",stdin);
        freopen("output.txt","w",stdout);
    #endif

    vector<int> adj[NUM_VERTICES];
    adj[0] = {1, 2};
    adj[1] = {0, 2, 3};
    adj[2] = {0, 1};
    adj[3] = {1};

    greedyColoring(adj, NUM_VERTICES);

    #ifdef ONLINEJUDGE
        fprintf(stderr, "\n>> Runtime: %.10fs\n", (double) (clock() - tStart) / CLOCKS_PER_SEC);
    #endif

    return 0;
}
