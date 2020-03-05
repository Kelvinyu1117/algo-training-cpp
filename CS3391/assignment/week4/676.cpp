#include <iostream>
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

#define rep(x, s, n) for(int x = s; x < n; x++)
#define repx(x, s, n) for(int x = s; x <= n; x++)
#define INF 1e8;
#define N 210
using namespace std;
int dist[N][N];

void clear() {
    rep(i, 0, N) {
        rep(j, 0, N) {
            if(i == j) dist[i][j] = 0;
            else dist[i][j] = INF;
        }
    }
}

// Floyd–Warshall algorithm
// normal state transition: min(dis[i][j], dist[i][k] + dist[k][j])
void floyd(int n) {
    for(int k = 1; k <= n; k++) {
        for(int i = 1; i <= n; i++) {
            for(int j = 1; j <= n; j++) { 
                dist[i][j] = min(dist[i][j], dist[i][k] + dist[k][j]);
            }
        }
    }
}


void mFun() {
    int n, m;

    while(cin >> n >> m) {
        clear();
        for(int i = 0; i < m; i++){
            int a, b, c;
            cin >> a >> b >> c;
                
            dist[a][b] = dist[b][a] = c;
        }
        
        floyd(n);
        int cnt[N + 1] = {0};
        
        int label = 1;
        int res = 0;
        repx(i, 1, n) {
            repx(j, 1, n) {
                cnt[i] += dist[i][j];    
            }
            
            if(i == 1)
                res = cnt[i];
            else
                if(res > cnt[i]) {
                    res = cnt[i];
                    label = i;
                }
        }
        
        cout << label << endl;
    }

}


int main()
{
    std::ios::sync_with_stdio(false);
    std::cin.tie(0);
    mFun();
    return 0;
}
