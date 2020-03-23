#include <iostream>
#include <string.h>
#include <queue>
#include <utility> 
#include <algorithm>
#define rep(x, s, n) for(int x = s; x < n; x++)
#define INF 2e7
#define N 300
using namespace std;

typedef vector<pair<int,int>>VII;
typedef pair<int,int>PII;

bool vis[N];
int dist[N];
int g[N][N];

void clear() {
    rep(i, 0, N) {
        vis[i] = false;
        dist[i] = INF;
        rep(j, 0, N) {
            if(i == j) g[i][j] = 0;
            else g[i][j] = INF;
        }
    }
}


int dijkstra(int s, int e, int n) {
    int res = 0;
    dist[s] = 0;
        
    priority_queue<PII,VII,greater<PII> >q;
    q.push(make_pair(dist[s], s));
    
    while(!q.empty()) {
        PII curr = q.top(); q.pop();
        
        vis[curr.second] = 1;
        
        if(curr.second == e) {
            res = curr.first;
            break;
        }
        
        for(int i = 1; i <= n; i++) {
            int d = curr.first + g[curr.second][i];
            if(!vis[i] && d < dist[i]) {
                dist[i] = d;
                q.push(make_pair(dist[i], i));
            }
        }
        
    }
    
    return res;
}



void mFun() {
    int n, m;
    while(cin >> n >> m && n && m) {
        clear();
        
        int s = 1;
        int e = n;
        
        for(int i = 0; i < m; i++) {
            int a, b, c;
            cin >> a >> b >> c;
            g[a][b] = g[b][a] = c; // from a -> b with cost c
        }
        
        // for(int i = 1; i <= n; i++) {
        //     for(int j = 1; j <= n; j++) {
        //         cout << g[i][j] << " ";
        //     }
        //     cout << endl;
        // }
        
        cout << dijkstra(s, e, n) << endl;
    }
}


int main()
{
    mFun();
    return 0;
}