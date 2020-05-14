#include <stdio.h>
#include <math.h>
#include <string.h>
#include <iostream>
#include <vector>
#include <list>
#include <string>
#include <algorithm>
#include <queue>
#include <stack>
#include <set>
#include <map>
#include <complex>
#define maxn 80000


using namespace std;

const long long INF  = 1e9;

struct Edge {
  long long from, to, cap, flow;
  Edge(long long u, long long v, long long c, long long f) : from(u), to(v), cap(c), flow(f) {}
};

struct Dinic {
  long long n, m, s, t;
  vector<Edge> edges;
  vector<long long> G[maxn];
  long long d[maxn], cur[maxn];
  bool vis[maxn];

  void init(long long n) {
    for (long long i = 0; i < n; i++) G[i].clear();
    edges.clear();
  }

  void AddEdge(long long from, long long to, long long cap) {
    edges.push_back(Edge(from, to, cap, 0));
    edges.push_back(Edge(to, from, 0, 0));
    m = edges.size();
    G[from].push_back(m - 2);
    G[to].push_back(m - 1);
  }

  bool BFS() {
    memset(vis, 0, sizeof(vis));
    queue<long long> Q;
    Q.push(s);
    d[s] = 0;
    vis[s] = 1;
    while (!Q.empty()) {
      long long x = Q.front();
      Q.pop();
      for (long long i = 0; i < G[x].size(); i++) {
        Edge& e = edges[G[x][i]];
        if (!vis[e.to] && e.cap > e.flow) {
          vis[e.to] = 1;
          d[e.to] = d[x] + 1;
          Q.push(e.to);
        }
      }
    }
    return vis[t];
  }

  long long DFS(long long x, long long a) {
    if (x == t || a == 0) return a;
    long long flow = 0, f;
    for (long long& i = cur[x]; i < G[x].size(); i++) {
      Edge& e = edges[G[x][i]];
      if (d[x] + 1 == d[e.to] && (f = DFS(e.to, min(a, e.cap - e.flow))) > 0) {
        e.flow += f;
        edges[G[x][i] ^ 1].flow -= f;
        flow += f;
        a -= f;
        if (a == 0) break;
      }
    }
    return flow;
  }

  long long Maxflow(long long s, long long t) {
    this->s = s;
    this->t = t;
    long long flow = 0;
    while (BFS()) {
      memset(cur, 0, sizeof(cur));
      flow += DFS(s, INF);
    }
    return flow;
  }
  
  void backtrack(long long s) {
    vis[s] = 1;
    for (long long& i = cur[s]; i < G[s].size(); i++) {
        Edge& e = edges[G[s][i]];
        if(e.cap - e.flow > 0 && !vis[e.to])
            backtrack(e.to);
    }
  }
};



void m() {
    long long n, m;
    
    while(cin >> n) {
        if(!n) return;
        Dinic dinic;
        
        long long s = 2 * n + 1;
        long long t = 2 * n + 2;
        
        dinic.n = n;
        
        for(int i = 1; i <= n ; i++) {
            int c;
            cin >> c;
            dinic.AddEdge(i, i + n, c);
        }
        
        cin >> m;
        dinic.m = m;
        
        for(long long i = 1; i <= m; i++) {
            int a, b, c;
            cin >> a >> b >> c;
            dinic.AddEdge(a + n, b, c);
        }
        
        int f, g;
        cin >> f >> g;
        for(int i = 1; i <= f; i++) {
            int a;
            cin >> a;
            dinic.AddEdge(s, a, INF);
        }
        
        for(int i = 1; i <= g; i++) {
            int a;
            cin >> a;
            dinic.AddEdge(a + n, t, INF);
        }
        
        
        cout << dinic.Maxflow(s, t) << endl;
    }
}

int main()
{
    ios_base::sync_with_stdio(false);
	  cin.tie(NULL);  
   
    m();
    return 0;
}