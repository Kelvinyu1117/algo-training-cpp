
#include <iostream>
#include <string.h>
#include <queue>
#include <utility> 
#include <algorithm>
#define rep(x, s, n) for(int x = s; x < n; x++)
#define INF 2e7
#define N 300
using namespace std;

struct Edge {
    int t;
    int w;
    
    Edge(int to, int weight): t(to), w(weight) {}
    
    bool operator<(const Edge& rhs) const {
        return w > rhs.w;
    }
};

vector<Edge> g[N];
bool vis[N];

void clear() {
    rep(i, 0, N) {
        vis[i] = false;
        g[i].clear();
    }
}


void pushEdgesPQ(priority_queue<Edge> &q, int i) {
    vis[i] = 1;
    
    for(auto e: g[i]) 
        if(!vis[e.t]) 
            q.push(e);
}

int primMST(int s, int n) {
    
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


void M() {
    
    int p, r;
    while(cin >> p >> r) {
        clear();
        if(!p) return;
        if(!r) {
            cout << 0 << endl;
            continue;
        }
        
        for(int i = 0; i < r; i++) {
            int a, b , c;
            cin >> a >> b >> c;
            g[a].push_back({b, c});
            g[b].push_back({a, c});
        }
        
        int res = primMST(1, p);
        cout << res << endl;
    }
}

int main()
{
    M();    

    return 0;
}
