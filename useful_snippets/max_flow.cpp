#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>
#define INF 1e9
using namespace std;

#define N 300
int cap[N][N];
int flow[N];
int pre[N];

int bfs(int s, int t, int n) {
   
    fill(pre, pre + n, -1);
    queue<int> q;
    q.push(s);
    
    flow[s] = INF;
    
    while(!q.empty()) {
        int curr = q.front(); q.pop();
        
        if(curr == t) break;
        
        for(int i = 0; i < n; i++) {
            if(curr == i) continue;
            
            if(pre[i] == -1 && cap[curr][i] > 0) {
                flow[i] = min(flow[curr], cap[curr][i]);
                pre[i] = curr;
                q.push(i);
            }
        }
    }
    
    if(pre[t] == -1) return 0;
    
    int dest = t;
    
    while(dest != s) {
        int from = pre[dest];
        cap[from][dest] -= flow[t];
        cap[dest][from] += flow[t];
        dest = from;
    }
    
    return flow[t];
}


int max_flow(int s, int t, int n) {
    int tmp_flow = INF;
    int res = 0;
    do {
        tmp_flow = bfs(s, t, n);
        res += tmp_flow;
    }while(tmp_flow);
}

int main()
{
    cout<<"Hello World";

    return 0;
}
