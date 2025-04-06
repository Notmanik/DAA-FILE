#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef vector<int> vi;
typedef pair<int, int> pii;

const int INF = 1e9;
const ll LINF = 1e18;

// Sorting Functions
// MERGE SORT
void merge(int arr[], int l, int m, int r) { 

    int n1 = m - l + 1, n2 = r - m; 

    int L[n1], R[n2]; 
    for (int i = 0; i < n1; i++) L[i] = arr[l + i]; 

    for (int j = 0; j < n2; j++) R[j] = arr[m + 1 + j]; 
    int i = 0, j = 0, k = l; 
    while (i < n1 && j < n2) 

        arr[k++] = (L[i] <= R[j]) ? L[i++] : R[j++]; 

    while (i < n1) arr[k++] = L[i++]; 

    while (j < n2) arr[k++] = R[j++]; 

} 
void mergeSort(int arr[], int l, int r) { 

    if (l < r) { 

        int m = l + (r - l) / 2; 

        mergeSort(arr, l, m); 

        mergeSort(arr, m + 1, r); 

        merge(arr, l, m, r); 

    } 

} 

// QUICK SORT
int partition(int arr[], int low, int high) { 

    int pivot = arr[high], i = low - 1; 

    for (int j = low; j < high; j++) { 

        if (arr[j] < pivot) 

            std::swap(arr[++i], arr[j]); 

    } 

    std::swap(arr[i + 1], arr[high]); 

    return i + 1; 

} 
void quickSort(int arr[], int low, int high) { 

    if (low < high) { 

        int pi = partition(arr, low, high); 

        quickSort(arr, low, pi - 1); 

        quickSort(arr, pi + 1, high); 

    } 

} 

// QUICK SORT END

// BUBBLE SORT
void bubbleSort(int arr[], int n) { 

    for (int i = 0; i < n - 1; i++) 

        for (int j = 0; j < n - i - 1; j++) 

            if (arr[j] > arr[j + 1]) 

                std::swap(arr[j], arr[j + 1]); 

} 
// BUBBLE SORT END
  
// BUCKET SORT
void bucketSort(float arr[], int n) { 

    std::vector<float> bucket[n]; 

    for (int i = 0; i < n; i++) 

        bucket[int(n * arr[i])].push_back(arr[i]); 

  

    for (int i = 0; i < n; i++) 

        std::sort(bucket[i].begin(), bucket[i].end()); 

  

    int index = 0; 

    for (int i = 0; i < n; i++) 

        for (float val : bucket[i]) 

            arr[index++] = val; 

}

// BUCKET SORT END

// RADIX SORT
int getMax(int arr[], int n) {
    int mx = arr[0];
    for (int i = 1; i < n; i++) if (arr[i] > mx) mx = arr[i];
    return mx;
}

void countSort(int arr[], int n, int exp) {
    int output[n], count[10] = {0};
    for (int i = 0; i < n; i++) count[(arr[i] / exp) % 10]++;
    for (int i = 1; i < 10; i++) count[i] += count[i - 1];
    for (int i = n - 1; i >= 0; i--)
        output[--count[(arr[i] / exp) % 10]] = arr[i];
    for (int i = 0; i < n; i++) arr[i] = output[i];
}

void radixSort(int arr[], int n) {
    int m = getMax(arr, n);
    for (int exp = 1; m / exp > 0; exp *= 10)
        countSort(arr, n, exp);
}


// RADIX SORT END
 

// SHELL SORT
void shellSort(int arr[], int n) { 

    for (int gap = n / 2; gap > 0; gap /= 2) { 

        for (int i = gap; i < n; i++) { 

            int temp = arr[i], j; 

            for (j = i; j >= gap && arr[j - gap] > temp; j -= gap) 

                arr[j] = arr[j - gap]; 

            arr[j] = temp; 

        } 

    } 

}

// SHELL SORT END

// SELECTION SORT
void selectionSort(int arr[], int n) { 

    for (int i = 0; i < n - 1; i++) { 

        int minIdx = i; 

        for (int j = i + 1; j < n; j++) 

            if (arr[j] < arr[minIdx]) minIdx = j; 

        std::swap(arr[minIdx], arr[i]); 

    } 

} 
// SELECTION SORT END

// HEAP SORT 
void heapify(int arr[], int n, int i) 

 { 

 int largest = i, l = 2 * i + 1, r = 2 * i + 2;  

if (l < n && arr[l] > arr[largest])  largest = l; 

if (r < n && arr[r] > arr[largest]) largest = r;  

if (largest != i) { 

 std::swap(arr[i], arr[largest]); heapify(arr, n, largest);  

} 

 } 

void heapSort(int arr[], int n) { 

 for (int i = n / 2 - 1; i >= 0; i--) heapify(arr, n, i); 

for (int i = n - 1; i > 0; i--) { 

 std::swap(arr[0], arr[i]);  

heapify(arr, i, 0);  

} 

} 
// HEAP SORT END 

void printArray(int arr[], int n) {
    for (int i = 0; i < n; i++) cout << arr[i] << " ";
    cout << endl;
cout<<"------------------------------------------"<<endl;
}


// Debugging
#define debug(x) cout << #x << " = " << (x) << endl;
#define print_vec(v) for (auto x : v) cout << x << " "; cout << endl;

int main() {
    ios_base::sync_with_stdio(0); cin.tie(0);
       #ifdef ONLINEJUDGE
       clock_t tStart = clock();
       freopen("input.txt","r",stdin); //can need to change file . this one for taking input
       freopen("output.txt","w",stdout); // this one for output
  #endif

       //Your Code

       // VERY BIG TEST CASE 
	int sample[] = {
    382, 928, 194, 625, 813, 45, 220, 999, 349, 601,
    123, 485, 746, 537, 808, 912, 57, 666, 351, 71,
    234, 302, 753, 888, 110, 640, 519, 787, 400, 81,
    209, 303, 55, 1001, 1000, 14, 322, 87, 643, 293,
    753, 491, 775, 376, 905, 111, 215, 30, 678, 999,
    456, 789, 632, 843, 900, 701, 122, 12, 981, 70,
    51, 102, 300, 431, 224, 876, 349, 601, 722, 418,
    193, 334, 615, 909, 498, 314, 111, 666, 775, 622,
    44, 292, 511, 999, 67, 85, 66, 744, 33, 2,
    19, 93, 410, 228, 891, 341, 650, 621, 321, 741
};
    int n = sizeof(sample) / sizeof(sample[0]);

    int arr1[n], arr2[n], arr3[n], arr4[n], arr5[n], arr6[n], arr7[n];
    copy(sample, sample + n, arr1);
    copy(sample, sample + n, arr2);
    copy(sample, sample + n, arr3);
    copy(sample, sample + n, arr4);
    copy(sample, sample + n, arr5);
    copy(sample, sample + n, arr6);
    copy(sample, sample + n, arr7);

    mergeSort(arr1, 0, n - 1);
    cout << "Merge Sort: "; printArray(arr1, n);

    quickSort(arr2, 0, n - 1);
    cout << "Quick Sort: "; printArray(arr2, n);

    bubbleSort(arr3, n);
    cout << "Bubble Sort: "; printArray(arr3, n);

    selectionSort(arr4, n);
    cout << "Selection Sort: "; printArray(arr4, n);

    heapSort(arr5, n);
    cout << "Heap Sort: "; printArray(arr5, n); 


    shellSort(arr6, n);
    cout << "Shell Sort: "; printArray(arr6, n);

    // For Bucket Sort, input should be float in [0, 1). We'll use a different array:
    float floatArr[] = {0.897, 0.565, 0.656, 0.1234, 0.665, 0.3434};
    int nf = sizeof(floatArr)/sizeof(floatArr[0]);
    bucketSort(floatArr, nf);
    cout << "Bucket Sort: ";
    for (int i = 0; i < nf; i++) cout << floatArr[i] << " ";
    cout << endl;
	
       
  #ifdef ONLINEJUDGE
     fprintf(stderr, "\n>> Runtime: %.10fs\n", (double) (clock() - tStart) / CLOCKS_PER_SEC); // this line gives your code runtime
  #endif
    return 0;
}