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
#define MAX_N 40000
#define INF 1e8+1e5
using namespace std;
typedef long long lld;

struct Node
{
    vector<lld> adj;
};
Node graf[MAX_N];

struct Edge
{
    lld u, v, cap;
    lld flow;
};
vector<Edge> E;

lld v, e;
lld s, t;
lld dist[MAX_N];
lld upTo[MAX_N];

lld idd = 0;

inline bool BFS()
{
    for (lld i=1;i<=v;i++) dist[i] = -1;
    queue<lld> bfs_queue;
    bfs_queue.push(s);
    dist[s] = 0;
    while (!bfs_queue.empty())
    {
        lld xt = bfs_queue.front();
        bfs_queue.pop();
        for (lld i=0;i<graf[xt].adj.size();i++)
        {
            lld currID = graf[xt].adj[i];
            lld xt1 = E[currID].v;
            if (dist[xt1] == -1 && E[currID].flow < E[currID].cap)
            {
                bfs_queue.push(xt1);
                dist[xt1] = dist[xt] + 1;
            }
        }
    }
    return (dist[t] != -1);
}

inline lld DFS(lld xt, lld minCap)
{
    if (minCap == 0) return 0;
    if (xt == t) return minCap;
    while (upTo[xt] < graf[xt].adj.size())
    {
        lld currID = graf[xt].adj[upTo[xt]];
        lld xt1 = E[currID].v;
        if (dist[xt1] != dist[xt] + 1)
        {
            upTo[xt]++;
            continue;
        }
        lld aug = DFS(xt1, min(minCap, E[currID].cap - E[currID].flow));
        if (aug > 0)
        {
            E[currID].flow += aug;
            if (currID&1) currID--; else currID++;
            E[currID].flow -= aug;
            return aug;
        }
        upTo[xt]++;
    }
    return 0;
}

inline lld Dinic()
{
    lld flow = 0;
    while (true)
    {
        if (!BFS()) break;
        for (lld i=1;i<=v;i++) upTo[i] = 0;
        while (true)
        {
            lld currFlow = DFS(s, INF);
            if (currFlow == 0) break;
            flow += currFlow;
        }
    }
    return flow;
}

inline void addEdge(lld u, lld v, lld cap)
{
    Edge E1, E2;
    
    E1.u = u, E1.v = v, E1.cap = cap, E1.flow = 0;
    E2.u = v, E2.v = u, E2.cap = 0, E2.flow = 0;
    
    graf[u].adj.push_back(idd++);
    E.push_back(E1);
    graf[v].adj.push_back(idd++);
    E.push_back(E2);
}

inline void clear(lld n) {
  for(lld i = 1; i <= n; i++) {
      graf[i].adj.clear();
  }
  
  E.clear();
}

int main()
{
    lld n, m;
    
    while(cin >> n >> m) {
        
        v = n;
        e = m;
        s = 1;
        t = n;
        
        
        for(lld i = 0; i < m; i++) {
            lld u, v, c;
            cin >> u >> v >> c;
            
            addEdge(u, v, c);
            addEdge(v, u, c);
        }

        cout << Dinic() << endl;
    }

    return 0;
}
