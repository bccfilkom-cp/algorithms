// Soal : https://tlx.toki.id/courses/competitive-1/chapters/10/problems/A/
#include <bits/stdc++.h>

using namespace std;

class DSU {
public:
    vector<int> parent;

    DSU(int n) {
        parent = vector<int>(n, 0);
        for(int i = 0; i < n; i++) {
            parent[i] = i;
        }
    }

    int find(int x) {
        if(parent[x] == x) {
            return x;
        }

        return find(parent[x]);
    }

    void uni(int x, int y) {
        parent[find(y)] = find(x);
    }

    bool check(int x, int y) {
        return find(x) == find(y);
    }
};

int main() {
    int n, q;
    cin >> n >> q;
    DSU* d = new DSU(n);
    
    for(int i = 0; i < q; i++) {
        int a, b, c; 
        cin >> a >> b >> c;
        if(a == 1) {
            d->uni(b, c);
        } else {
            if(d->check(b, c)) {
                cout << "Y\n";
            } else {
                cout << "T\n";
            }
            
        }
    }
}