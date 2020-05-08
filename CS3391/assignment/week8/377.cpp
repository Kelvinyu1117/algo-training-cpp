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
    
    while(cin >> n >> m) {
        if(!n && !m) return;
        Dinic dinic;
        
        long long s = 0;
        long long t = n + 1;
        
        dinic.n = n;
        dinic.m = m;
        dinic.s = s;
        dinic.t = t;
        
        long long total = 0;
        
        for(long long i = 1; i <= n; i++) {
            long long c;
            cin >> c;
            if(c >= 0) {
                dinic.AddEdge(s, i, c);
                total += c;
            }else if(c < 0) {
                dinic.AddEdge(i, t, -c);
            }
        }
        
        for(long long i = 0; i <  m; i++) {
            long long f, g;
            cin >> f >> g;
            dinic.AddEdge(f, g, INF);
        }
        
        long long flow = dinic.Maxflow(s, t);
        long long max_profit = total - flow;
        dinic.backtrack(s);
        
        
        long long cnt = 0;
        for(long long i = 1; i <= n; i++) {
            if(dinic.vis[i])
                cnt++;
        }
        
        cout << cnt << " " << max_profit << endl;
    }
}

int main()
{
   
    m();
    return 0;
}