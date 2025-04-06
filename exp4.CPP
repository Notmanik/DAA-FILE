#include <iostream> 
#include <vector> 
using namespace std; 
 
int LCS(string A, string B) { 
    int m = A.length(); 
    int n = B.length(); 
    vector<vector<int>> dp(m + 1, vector<int>(n + 1, 0)); 
 
    for (int i = 1; i <= m; i++) { 
        for (int j = 1; j <= n; j++) { 
            if (A[i - 1] == B[j - 1]) 
                dp[i][j] = 1 + dp[i - 1][j - 1]; 
            else 
                dp[i][j] = max(dp[i - 1][j], dp[i][j - 1]); 
        } 
    } 
    return dp[m][n]; 
} 
int main() {
    #ifdef ONLINEJUDGE
       clock_t tStart = clock();
       freopen("input.txt","r",stdin); //can need to change file . this one for taking input
       freopen("output.txt","w",stdout); // this one for output
  #endif


    string A, B; 
    cout << "Enter first string: "; 
    cin >> A; cout<<A<<endl;
    cout << "Enter second string: "; 
    cin >> B; cout<<B<<endl;
 
    int length = LCS(A, B); 
    cout << "Length of LCS: " << length << endl; 




  #ifdef ONLINEJUDGE
     fprintf(stderr, "\n>> Runtime: %.10fs\n", (double) (clock() - tStart) / CLOCKS_PER_SEC); // this line gives your code runtime
  #endif
    return 0;
}
