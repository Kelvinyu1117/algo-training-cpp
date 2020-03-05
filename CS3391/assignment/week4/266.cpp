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
#define INF 1e6;
using namespace std;
bool g[200][200];

void floyd(int n) {
    for(int k = 1; k <= n; k++) {
        for(int i = 1; i <= n; i++) {
            for(int j = 1; j <= n; j++) { 
                g[i][j] = g[i][j] || g[i][k] && g[k][j];  // if cow i fight with cow k and cow k fight with cow j = cow i fight with cow j
            }
        }
    }
}

int getNumOfConfirmedRank(int n) {
    int res = 0;

    repx(i, 1, n) {
        int cnt = 0;
        repx(j, 1, n) {
            if(g[i][j] || g[j][i])
                cnt++;
        }
            
        if(cnt == n - 1)
            res++;
    }
    
    return res;
}
void mFun() {
    int n, m;
    while(cin >> n >> m) {
        repx(i, 1, n) {
            repx(j, 1, n) {
                g[i][j] = 0;
            }
        }
        
        rep(i, 0, m) {
            int a, b;
            cin >> a >> b;
            g[a][b] = 1;
        }
        
        floyd(n);
        
        cout << getNumOfConfirmedRank(n) << endl;    
    }
}


int main()
{
    std::ios::sync_with_stdio(false);
    std::cin.tie(0);
    mFun();
    return 0;
}