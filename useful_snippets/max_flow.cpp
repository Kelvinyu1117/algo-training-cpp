#include <vector>
#include <queue>
#include <algorithm>
#include <iostream>

#define INF 1e9
#define N 30050
using namespace std;

struct Edge {
    int next;
    int prev;
    int flow;
    int cap;

    Edge(int n, int p, int f, int c): next(n), prev(p), flow(f), cap(c) {}; 
};
vector<vector<Edge>> g(N);
vector<int> level(N);
vector<int> nextNode(N);

struct Dinic {    
    void addEdge(int prev, int next, int weight) {
        Edge forward = {next, g[next].size(), 0, weight};
        Edge backward = {prev, g[prev].size(), 0, weight};

        g[prev].push_back(forward);
        g[next].push_back(backward);
    }

    void clear() {
        for(int i = 0; i < N; i++) {
            g.clear();
        }
        level.clear();
        nextNode.clear();
        g.clear();
    }
    
    bool bfs(int s, int e) {
        fill(level.begin(), level.end(), -1);
        
        queue<int> q;
        q.push(s);
        level[s] = 0;

        while(!q.empty()) {
            int curr = q.front(); q.pop();

            for(int i = 0; i < g[curr].size(); i++) {
                Edge currEdge = g[curr][i];
                int next = currEdge.next;

                if(level[next] == -1 && currEdge.flow < currEdge.cap) {
                    level[next] = level[curr] + 1;
                    q.push(next);
                }
            }
        }

        return level[e] != -1;
    }

    int dfs(int s, int e, int currFlow) {
        if(s == e)
            return currFlow;

        for(nextNode[s]; nextNode[s] < g[s].size(); nextNode[s]++) {
            Edge ed = g[s][nextNode[s]];

            if(level[ed.next] == level[s] + 1 && ed.flow < ed.cap) {
                int nextFlow = min(currFlow, ed.cap - ed.flow);
                int dfs_val = dfs(ed.next, e, nextFlow);

                if(dfs_val > 0) {
                    ed.flow += dfs_val;
                    g[ed.next][ed.prev].flow -= dfs_val;
                    return dfs_val; 
                }
            }
        }

        return 0;
    }

    int max_flow(int s, int e) {
        int total_flow = 0;
        
        while(bfs(s, e)) {
            int flow = dfs(s, e, INF);
            fill(nextNode.begin(), nextNode.end(), 0);
            while(flow) {
                total_flow += flow;
                flow = dfs(s, e, INF);
            }
        }

        return total_flow;
    }
};


void m() {
    int n, m;
    Dinic dinic;
    while(cin >> n >> m) {
        dinic.clear();
        for(int i = 0; i < m; i++) {
            int a, b, c;
            cin >> a >> b >> c;
            a--;
            b--;
            dinic.addEdge(a, b, c);
        }
        
        int res = dinic.max_flow(0, n - 1);
    }
}
int main() {
    m();
}

