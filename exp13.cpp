#include <iostream> 
#include <vector> 
using namespace std; 
#define N 8 
 
bool isSafe(vector<vector<int>>& board, int row, int col) { 
    for (int i = 0; i < col; i++) 
        if (board[row][i]) return false; 
 
    for (int i = row, j = col; i >= 0 && j >= 0; i--, j--) 
        if (board[i][j]) return false; 
 
    for (int i = row, j = col; i < N && j >= 0; i++, j--) 
        if (board[i][j]) return false; 
 
    return true; 
} 
 
bool solveNQUtil(vector<vector<int>>& board, int col) { 
    if (col >= N) return true; 
 
    for (int i = 0; i < N; i++) { 
        if (isSafe(board, i, col)) { 
            board[i][col] = 1; 
            if (solveNQUtil(board, col + 1)) return true; 
            board[i][col] = 0; 
        } 
    } 
    return false; 
} 
 
void solveNQ() { 
    vector<vector<int>> board(N, vector<int>(N, 0)); 
    if (!solveNQUtil(board, 0)) { 
        cout << "Solution does not exist" << endl; 
        return; 
    } 
 
    for (auto row : board) { 
        for (int x : row) cout << x << " "; 
        cout << endl; 
    } 
} 
int main() {
    #ifdef ONLINEJUDGE
       clock_t tStart = clock();
       freopen("input.txt","r",stdin); //can need to change file . this one for taking input
       freopen("output.txt","w",stdout); // this one for output
  #endif

    solveNQ();       
  #ifdef ONLINEJUDGE
     fprintf(stderr, "\n>> Runtime: %.10fs\n", (double) (clock() - tStart) / CLOCKS_PER_SEC); // this line gives your code runtime
  #endif
    return 0;
}