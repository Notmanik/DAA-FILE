#include <iostream> 
#include <vector> 
#include <climits> 
using namespace std; 
 
int optimalBST(vector<int>& keys, vector<int>& freq, int n) { 
    vector<vector<int>> cost(n, vector<int>(n)); 
 
    for (int i = 0; i < n; i++) 
        cost[i][i] = freq[i]; 
 
    for (int L = 2; L <= n; L++) { 
        for (int i = 0; i <= n - L; i++) { 
            int j = i + L - 1; 
            cost[i][j] = INT_MAX; 
 
            int sum = 0; 
            for (int k = i; k <= j; k++) sum += freq[k]; 
 
            for (int r = i; r <= j; r++) { 
                int c = ((r > i) ? cost[i][r - 1] : 0) + 
                        ((r < j) ? cost[r + 1][j] : 0) + sum; 
                cost[i][j] = min(cost[i][j], c); 
            } 
        } 
    } 
    return cost[0][n - 1]; 
}
int main() {
    #ifdef ONLINEJUDGE
       clock_t tStart = clock();
       freopen("input.txt","r",stdin); //can need to change file . this one for taking input
       freopen("output.txt","w",stdout); // this one for output
  #endif

           vector<int> keys = {10, 12, 20}; 
    vector<int> freq = {34, 8, 50}; 
    int n = keys.size(); 
    cout << "Cost of Optimal BST is " << optimalBST(keys, freq, n) << endl;

  #ifdef ONLINEJUDGE
     fprintf(stderr, "\n>> Runtime: %.10fs\n", (double) (clock() - tStart) / CLOCKS_PER_SEC); // this line gives your code runtime
  #endif
    return 0;
}
