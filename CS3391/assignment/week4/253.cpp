#include <iostream>
#include <iomanip>
#include <string>
#include <vector>
#include <algorithm>
#include <sstream>
#include <queue>
#include <deque>
#include <bitset>
#include <iterator>
#include <list>
#include <stack>
#include <map>
#include <set>
#include <functional>
#include <numeric>
#include <utility>
#include <limits>
#include <time.h>
#include <math.h>
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <assert.h>
#include <cfloat>

#define rep(x, s, n) for(int x = s; x < n; x++)
#define repx(x, s, n) for(int x = s; x <= n; x++)
#define N 60


const double INF = 1e9; 
using namespace std;

struct state {
    int from, to, v;
    double t;
    
    bool operator<(const state& rhs) const {
        return t > rhs.t;
    }
};

bool vis[N];
double dist[N][N];
double sp[N][N];
double t[N][N][N];
void clear() {
    rep(i, 0, N) {
        rep(j, 0, N) {
            dist[i][j] = 0;
            rep(k, 0, N) {
               t[i][j][k] = INF; 
            }
        }
    }
}


double dijkstra(int s, int e, int n) {
    double res = INF;
    
    
    priority_queue<state>q;
    
    q.push({-1, s, 0, 0});
    
    while (!q.empty()) {
        state curr = q.top(); q.pop(); 
        for (int i = 1; i <= n; i++) {
            if (i != curr.from && dist[curr.to][i] != 0)
              for (int j = 1; j >= -1; --j) {
                state st = {curr.to, i, curr.v + j, 0};
                if (st.v > 0 && st.v <= sp[st.from][st.to]) {
                  st.t = curr.t + (double) dist[st.from][st.to] / st.v;
                  if (t[st.from][st.to][st.v] > st.t) {
                    t[st.from][st.to][st.v] = st.t;
                    q.push(st);
                  }
                }
              }
          }
    }
    
    for (int i = 1; i <= n; i++)
		res = min(res, t[i][e][1]);
	
	if(res == INF)
	    cout << "unreachable" << endl;
    else
        cout << fixed << setprecision(5) << res<< endl;
            
}


void m() {
    int n, m;
    while(cin >> n >> m) {
        if(!n && !m) return;
        clear();
        int s, e;
        cin >> s >> e;
        for(int i = 0; i < m; i++) {
            int a, b, c, d;
            cin >> a >> b >> c >> d;
            dist[a][b] = dist[b][a] = c;
            sp[a][b] = sp[b][a] = d;
        }
        
        dijkstra(s, e, n);
    }
}

int main()
{
    m();
    return 0;
}
