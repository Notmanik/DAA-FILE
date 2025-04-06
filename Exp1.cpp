#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef vector<int> vi;
typedef pair<int, int> pii;

const int INF = 1e9;
const ll LINF = 1e18;

// Debugging
#define debug(x) cout << #x << " = " << (x) << endl;
#define print_vec(v) for (auto x : v) cout << x << " "; cout << endl;
// Linear Search 
int linearSearch(int arr[], int n, int key) { 

    for (int i = 0; i < n; i++) { 

        if (arr[i] == key) 

            return i; // Found at index i 

    } 

    return -1; // Not found 

} 

// Binary Search 

int binarySearch(int arr[], int n, int key) { 

    int low = 0, high = n - 1; 

    while (low <= high) { 

        int mid = (low + high) / 2; 

        if (arr[mid] == key) 

            return mid; // Found 

        else if (arr[mid] < key) 

            low = mid + 1; 

        else 

            high = mid - 1; 

    } 

    return -1; // Not found 

} 

int main() {
    ios_base::sync_with_stdio(0); cin.tie(0);
        #ifdef ONLINEJUDGE
        clock_t tStart = clock();
        freopen("input.txt","r",stdin); //can need to change file . this one for taking input
        freopen("output.txt","w",stdout); // this one for output
        #endif
        // code starts
        int arr[] = {1,6,4,2,7,8,2,3,16,14};
        cout<<"Array Before Starting the linearSearch && The key is 8"<<endl;
        print_vec(arr);
        int index = linearSearch(arr,10,8);
        cout<<"Element 8 is at "<<index<<endl;
        int a[] = {1,2,2,3,4,6,7,8,14,16};
        cout<<"Array Before Starting the binarySearch && The key is 8"<<endl;
        print_vec(a);
        index = binarySearch(a,10,8);
        cout<<"Element 8 is at "<<index<<endl;
        
        // code ends
    #ifdef ONLINEJUDGE
        fprintf(stderr, "\n>> Runtime: %.10fs\n", (double) (clock() - tStart) / CLOCKS_PER_SEC); // this line gives your code runtime
    #endif
    return 0;
}
