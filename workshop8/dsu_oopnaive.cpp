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

    void join(int x, int y) {
        parent[find(y)] = find(x);
    }

    bool check(int x, int y) {
        return find(x) == find(y);
    }
};



int main() {
    DSU d(10);

    
    return 0;
}