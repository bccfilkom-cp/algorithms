#include <bits/stdc++.h>
using namespace std; 

int representasi(int x, vector<int>& parent) {
    if (parent[x] == x) {
        return x;
    }
    return parent[x] = representasi(parent[x], parent); 
}

void join(int a, int b, vector<int>& parent, vector<int>& rank, vector<int>& size, int& num_components, int& max_size) {
    int kiri = representasi(a, parent); 
    int kanan = representasi(b, parent); 

    if (kiri != kanan) { 
        if (rank[kiri] < rank[kanan]) {
            parent[kiri] = kanan;
            size[kanan] += size[kiri];
            max_size = max(max_size, size[kanan]);
        } else if (rank[kiri] > rank[kanan]) {
            parent[kanan] = kiri;
            size[kiri] += size[kanan];
            max_size = max(max_size, size[kiri]);
        } else {
            parent[kiri] = kanan;
            size[kanan] += size[kiri];
            max_size = max(max_size, size[kanan]);
            rank[kanan]++;
        }
        num_components--; 
    }
}

int main() {
    int n, m; 
    cin >> n >> m; 

    vector<int> parent(n + 1); 
    vector<int> rank(n + 1, 0);
    vector<int> size(n + 1, 1); 
    int num_components = n; 
    int max_size = 1; 

    for (int i = 0; i <= n; i++) {
        parent[i] = i; 
    }

    while (m--) {
        int a, b;
        cin >> a >> b;

        join(a, b, parent, rank, size, num_components, max_size); 
        
        cout << num_components << " " << max_size << endl; 
    }

    return 0;
}