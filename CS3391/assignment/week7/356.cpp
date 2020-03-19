#include <iostream>
#include <string.h>
#include <queue>
#include <utility> 
#include <algorithm>
#define rep(x, s, n) for(int x = s; x < n; x++)
#define INF 2e7
#define N 600
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
        vis[i] = 0;
        g[i].clear();
    }
}


int dfs(int u, long long int max_ppa) {
    vis[u] = 1; 
    int cnt = 1;
    for(auto e: g[u]) {
        if(!vis[e.t] && e.w == max_ppa)
            cnt += dfs(e.t, max_ppa);
    }
    
    return cnt;
}


void M() {
    int n, m;
    while(cin >> n >> m) {
        if(!n && !m) return;
        clear();
        
        int max_ppa = -2147483648;
        for(int i = 0; i < m; i++) {
            int a, b, c;
            cin >> a >> b >> c;
            
            max_ppa = max(max_ppa, c);
            
            g[a].push_back({b, c});
            g[b].push_back({a, c});
        }
     
        int cnt = 0;
        
        for(int i = 1; i <= n; i++) {
            if(!vis[i]) 
                cnt = max(cnt, dfs(i, max_ppa));
        }
        
        cout << cnt << endl;
    }
}

int main()
{
    M();
    return 0;
}
