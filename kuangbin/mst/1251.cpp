#include <iostream>
#include <string.h>
#include <vector>
#include <queue>
#include <utility> 
#include <algorithm>
#define rep(x, s, n) for(int x = s; x < n; x++)
#define INF 2e7
#define N 300
using namespace std;

struct Edge {
    int f;
    int t;
    int w;
    
    Edge(int from, int to, int weight): f(from), t(to), w(weight) {}
    
    bool operator<(const Edge& rhs) const {
        return w < rhs.w;
    }
};

struct UnionFind {
    int size[N];
    int arr[N];
    int max_size;
    int min_size;
    UnionFind() {
        max_size = 1;
        min_size = 1;
        for(int i = 0; i < N; i++) {
            size[i] = 1;
            arr[i] = i;
        }
    }
    
    
    int root(int i) {
        while(arr[i] != i) {
            arr[i] = arr[arr[i]];
            i = arr[i];
        }
        
        return i;
    }
    
    void unify(int a, int b) {
        int root_A = root(a);
        int root_B = root(b); 
        
        if(root_A == root_B) return;
        
        if(size[root_A] < size[root_B]) {
            arr[ root_A ] = root_B;
            size[root_B] += size[root_A];
        }
        else{
            arr[root_B] = root_A;
            size[root_A] += size[root_B];
        }
        
        
        max_size = max(max_size, max(size[root_A], size[root_B]));
        min_size = min(min_size, min(size[root_A], size[root_B]));
    }
    
    bool find(int a, int b) {
        return root(a) == root(b);
    }
    
};


struct MST {
    vector<Edge> g[N];
    vector<Edge> g2;
    bool vis[N];
    
    MST() {
        g2.reserve(N);
        clear();
    }
    
    void clear() {
        rep(i, 0, N) {
            vis[i] = false;
            g[i].clear();
        }
        g2.clear();
    }
    
    
    void pushEdgesPQ(priority_queue<Edge> &q, int i) {
        vis[i] = 1;
        
        for(auto e: g[i]) 
            if(!vis[e.t]) 
                q.push(e);
    }
    
    int prim(int s, int n) {
        
        int m = n - 1, cnt = 0;
        int res = 0;
        priority_queue<Edge> pq;
        pushEdgesPQ(pq, s);
        
        while(!pq.empty() && cnt != m) {
            Edge ce = pq.top(); pq.pop();
            
            int i = ce.t;
            
            if(vis[ce.t]) continue;
            
            res += ce.w;
            cnt++;
            pushEdgesPQ(pq, i);
        }
        
        return res;
    }
    
    int kruskal(int n) {
        UnionFind uf;
        int res = 0;
        
        sort(g2.begin(), g2.begin() + n);
        
        for(int i = 0; i < n; i++) {
            int f = g2[i].f;
            int t = g2[i].t;
            int w = g2[i].w;
            
            if(!uf.find(f, t)) {
                uf.unify(f, t);
                res += w;        
            }
        }
        
        return res;
    }
};

int main()
{
    int n;
    while(cin >> n) {
        if(!n) return 0;
        MST mst;
        int m = 0;
        for(int i = 0; i < n - 1; i++) {
            char a;
            int b;
            cin >> a >> b;
            
            
            while(b--) {
                char c;
                int d;
                cin >> c >> d;
                mst.g2.push_back({a - 'A', c - 'A',  d});
                m++;
            }
        }
        
        int res = mst.kruskal(m);
        cout << res << endl;
    }

    return 0;
}
