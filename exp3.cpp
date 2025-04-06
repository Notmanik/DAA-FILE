#include <iostream>
using namespace std;

void multiplyMatrices(int A[][10], int B[][10], int C[][10], int m, int n, int p) {
    // Initialize result matrix with 0
    for (int i = 0; i < m; i++)
        for (int j = 0; j < p; j++)
            C[i][j] = 0;

    // Multiply A and B, store result in C
    for (int i = 0; i < m; i++)
        for (int j = 0; j < p; j++)
            for (int k = 0; k < n; k++)
                C[i][j] += A[i][k] * B[k][j];
}

int main() {
    #ifdef ONLINEJUDGE
       clock_t tStart = clock();
       freopen("input.txt","r",stdin); //can need to change file . this one for taking input
       freopen("output.txt","w",stdout); // this one for output
  #endif
    int A[10][10], B[10][10], C[10][10];
    int m, n, p;

    cout << "Enter rows and columns of Matrix A: ";
    cin >> m >> n;
    cout << "Enter elements of Matrix A:\n";
    for (int i = 0; i < m; i++)
        for (int j = 0; j < n; j++)
            cin >> A[i][j];

    cout << "Enter columns of Matrix B (rows will be " << n << "): ";
    cin >> p;
    cout << "Enter elements of Matrix B:\n";
    for (int i = 0; i < n; i++)
        for (int j = 0; j < p; j++)
            cin >> B[i][j];

    multiplyMatrices(A, B, C, m, n, p);

    cout << "\nResultant Matrix C (A x B):\n";
    for (int i = 0; i < m; i++) {
        for (int j = 0; j < p; j++)
            cout << C[i][j] << " ";
        cout << "\n";
    }
    #ifdef ONLINEJUDGE
     fprintf(stderr, "\n>> Runtime: %.10fs\n", (double) (clock() - tStart) / CLOCKS_PER_SEC); // this line gives your code runtime
  #endif
    return 0;
}
