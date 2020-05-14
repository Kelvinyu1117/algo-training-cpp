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
#define maxn 40000


using namespace std;

const long long INF  = 1e9+1e5;

struct Edge {
  int from, to, cap, flow;
  Edge(int u, int v, int c, int f) : from(u), to(v), cap(c), flow(f) {}
};

struct Dinic {
  int n, m, s, t;
  vector<Edge> edges;
  vector<int> G[maxn];
  int d[maxn], cur[maxn];
  bool vis[maxn];

  void init(int n) {
    for (int i = 0; i < n; i++) G[i].clear();
    edges.clear();
  }

  void AddEdge(int from, int to, int cap) {
    edges.push_back(Edge(from, to, cap, 0));
    edges.push_back(Edge(to, from, 0, 0));
    m = edges.size();
    G[from].push_back(m - 2);
    G[to].push_back(m - 1);
  }

  bool BFS() {
    memset(vis, 0, sizeof(vis));
    queue<int> Q;
    Q.push(s);
    d[s] = 0;
    vis[s] = 1;
    while (!Q.empty()) {
      int x = Q.front();
      Q.pop();
      for (int i = 0; i < G[x].size(); i++) {
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

  int DFS(int x, int a) {
    if (x == t || a == 0) return a;
    int flow = 0, f;
    for (int& i = cur[x]; i < G[x].size(); i++) {
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

  int Maxflow(int s, int t) {
    this->s = s;
    this->t = t;
    int flow = 0;
    while (BFS()) {
      memset(cur, 0, sizeof(cur));
      flow += DFS(s, INF);
    }
    return flow;
  }
};

int tA[maxn];
int tB[maxn];

void m() {
    int L, W, N, D, cnt;
    
    cnt = 1;
    while(cin >> L >> W >> N >> D) {
        if(!L && !W && !N && !D) return;
        Dinic dinic;
        
        int s = 2 * N;
        int t = 2 * N + 1;
        
        for(int i = 0; i < N; i++)
            cin >> tA[i] >> tB[i];
        
        
        for(int i = 0; i < N; i++) {
            int tmpA = i * 2;
            dinic.AddEdge(tmpA, tmpA + 1, 1);
            
            if(tB[i] - D <= 0) {
              
                dinic.AddEdge(s, tmpA, 1);
                dinic.AddEdge(tmpA, s, 0);
            }
            if(tB[i] + D >= W) {
                dinic.AddEdge(tmpA + 1, t, 1);
                dinic.AddEdge(t, tmpA + 1, 0);
            }
            
            for (int j = 0; j < i; j++) {
                int tmpB = j * 2;
                if((tA[i] - tA[j]) * (tA[i] - tA[j]) + (tB[i] - tB[j]) * (tB[i] - tB[j]) <= D * D * 4) {
                    dinic.AddEdge(tmpA + 1, tmpB, 1);
					dinic.AddEdge(tmpB + 1, tmpA, 1);
                }
            }
        }
        
        
        
        cout << "Case " << cnt << ": " << dinic.Maxflow(s, t) << endl;
        cnt++;
    }
}

int main()
{
    ios_base::sync_with_stdio(false);
	  cin.tie(NULL);  
   
    m();
    return 0;
}