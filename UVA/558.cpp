#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>

#define MAX_N 2005
#define rep(x, s, n) for(int x = s; x < n; x++)
#define repx(x, s, n) for(int x = s; x <= n; x++)
#define INF 100000000

using namespace std;
struct Edge{
  int to;
  int weight;
};

int dist[MAX_N];

vector<vector<Edge>> g(MAX_N);


void clear() {
    rep(i, 0, MAX_N) {
        dist[i] = INF;
        g[i].clear();
    }
    
    g.clear();
}

bool bellmanFord(int n) {
    dist[0] = 0;
    
    rep(i, 0, n - 1) {
        rep(j, 0, n) {
            for(auto e: g[j]) {
               if(dist[j] + e.weight < dist[e.to]) {
                   dist[e.to] = dist[j] + e.weight; 
               }
            }
        }
    }
    
   
    rep(j, 0, n) {
        for(auto e: g[j]) 
            if(dist[j] + e.weight < dist[e.to]) 
                return true;
    }
    
    return false;
}


int main()
{
    int t;
    cin >> t;
    
    while(t--) {
        clear();
        
        int n, m;
        cin >> n >> m;
        for(int i = 0; i < m; i++) {
            int a, b, c;
            cin >> a >> b >> c;
            g[a].push_back({b, c});
        }
        
        bool res = bellmanFord(n);
        
        if(res) cout << "possible" << endl;
        else
            cout << "not possible" << endl;
    }
}