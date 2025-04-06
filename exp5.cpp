#include <iostream> 
#include <queue> 
#include <unordered_map> 
using namespace std; 
 
struct Node { 
    char ch; 
    int freq; 
    Node *left, *right; 
    Node(char c, int f) : ch(c), freq(f), left(nullptr), right(nullptr) {} 
}; 
 
struct Compare { 
    bool operator()(Node* a, Node* b) { 
        return a->freq > b->freq; 
    } 
}; 
 
void printCodes(Node* root, string code) { 
    if (!root) return; 
    if (!root->left && !root->right) 
        cout << root->ch << ": " << code << endl; 
    printCodes(root->left, code + "0"); 
    printCodes(root->right, code + "1"); 
} 
 
void HuffmanCoding(unordered_map<char, int>& freqMap) { 
    priority_queue<Node*, vector<Node*>, Compare> pq; 
    for (auto& pair : freqMap) 
        pq.push(new Node(pair.first, pair.second)); 
 
    while (pq.size() > 1) { 
        Node* left = pq.top(); pq.pop(); 
        Node* right = pq.top(); pq.pop(); 
        Node* merged = new Node('\0', left->freq + right->freq); 
        merged->left = left; 
        merged->right = right; 
        pq.push(merged); 
    } 
 
    Node* root = pq.top(); 
    printCodes(root, ""); 
}
int main() {
    #ifdef ONLINEJUDGE
       clock_t tStart = clock();
       freopen("input.txt","r",stdin); //can need to change file . this one for taking input
       freopen("output.txt","w",stdout); // this one for output
  #endif

    unordered_map<char, int> freq = {{'a', 5}, {'b', 9}, {'c', 12}, {'d', 13}, {'e', 16}, {'f', 45}}; 
    HuffmanCoding(freq);       
              
  #ifdef ONLINEJUDGE
     fprintf(stderr, "\n>> Runtime: %.10fs\n", (double) (clock() - tStart) / CLOCKS_PER_SEC); // this line gives your code runtime
  #endif
    return 0;
}
