// solution to https://vjudge.net/problem/Kattis-islandhopping

#include <bits/stdc++.h>
#define fi first 
#define se second
#define pb push_back
#define FOR(i,s,e) for(int i=s;i<e;i++)
#define FOREV(i,s,e) for(int i=s; i>=e;i--)
#define in(var) cin >> var;
#define ps(x) cout << x << " ";
#define pss(x) cout << x << '\n';
#define arrin(arr, n) for(int i = 0; i < n; i++) cin >> arr[i];
#define arr2din(arr, n, m) for(int i = 0; i < n; i++) \
    for(int j = 0; j < m; j++) cin >> arr[i][j];
#define fastio ios_base::sync_with_stdio(false); cin.tie(NULL);
using namespace std;
typedef long long ll;
typedef long double ld;
typedef unsigned long long ull;
typedef vector<int> vi;
typedef vector<char> vc;
typedef vector<long long> vll;
typedef vector<vector<char>> vvc;
typedef vector<vector<int>> vvi;

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

struct Node {
    double x, y;

    Node(double x, double y) {
        this->x = x;
        this->y = y;
    }
};

class Graph {
public:
    vector<tuple<double, int, int>> el;
    vector<Node*> nodes;
    int n;

    Graph(int n) {
        this->n = n;
    }

    void addEdge(double w, int x, int y) {
        el.push_back({w, x, y});
    }

    void addNode(double x, double y) {
        nodes.push_back(new Node(x, y));
    }

    double kruskal() {
        sort(el.begin(), el.end());

        DSU d(n);

        double mst = 0;
        int taken = 0;
        for (auto& [w, n1, n2] : el) {
            if(d.check(n1, n2)) continue;
            mst += w;
            d.uni(n1, n2);
            taken++;
            if(taken >= n - 1) break;
        }
        return mst;
    }

    void constructCompleteGraph() {
        for(int i = 0; i < n; i++) {
            for(int j = 0; j < n; j++) {
                if(i == j) continue;
                double dist = this->euclidean(nodes[i], nodes[j]);
                this->addEdge(dist, i, j);
            }
        }
    }

    double euclidean(Node* n1, Node* n2) {
        return sqrt(pow(abs(n1->x - n2->x),2) + pow(abs(n1->y - n2->y),2));
    }
};


int main(){
    

    int t;
    cin >> t;
    for(int i = 0; i < t; i++) {
        int n;
        cin >> n;
        Graph* g = new Graph(n);
        for(int i = 0; i < n; i++) {
            double x, y;
            cin >> x >> y;
            g->addNode(x, y);
        } 

        g->constructCompleteGraph();

        printf("%.03f\n", g->kruskal());
    }

    return 0;
}