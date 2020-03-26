#include <iostream>
#include <string.h>
#include <queue>
#include <utility> 
#include <algorithm>
#define rep(x, s, n) for(int x = s; x < n; x++)
#define INF 2e7
#define N 300
using namespace std;



bool vis[N][N];
int dist[N][N];
int g[N][N];

struct Node {
    int r, c;
    Node(int row, int col): r(row), c(col) {};
    bool operator<(const Node& rhs) const {
        return r < rhs.r;
    }
};

typedef vector<pair<int,Node>>VII;
typedef pair<int,Node>PII;

void clear() {
    rep(i, 0, N) {
        rep(j, 0, N) {
            dist[i][j] = INF;
            g[i][j] = INF;
            vis[i][j] = 0;
        }
    }
}

bool equals(Node i, Node j) {
    return i.r == j.r && i.c == j.c;
}

int dijkstra(Node s, Node e, int n) {
    int res = 0;
    dist[s.r][s.c] = 0;
        
    priority_queue<PII,VII,greater<PII> >q;
    q.push(make_pair(g[s.r][s.c], s));
    
    while(!q.empty()) {
        PII curr = q.top(); q.pop();
        Node cc = curr.second;
        vis[cc.r][cc.c] = 1;
        
        if(equals(cc, e)) {
            break;
        }
        
        // for(int i = 1; i <= n; i++) {
        //     int d = curr.first + g[curr.second][i];
        //     if(!vis[i] && d < dist[i]) {
        //         dist[i] = d;
        //         q.push(make_pair(dist[i], i));
        //     }
        // }
        
        int dir[4][2] = {{-1, 0}, {1, 0}, {0, -1}, {0, 1}};
        
       
        for(int i = 0; i < 4; i++) {
            Node tmp(cc.r + dir[i][0], cc.c + dir[i][1]);
            int d = curr.first + g[tmp.r][tmp.c];
            if(tmp.r >= 0 && tmp.r < n && tmp.c >= 0 && tmp.c < n) {
                if(!vis[tmp.r][tmp.c] && d < dist[tmp.r][tmp.c]) {
                    dist[tmp.r][tmp.c] = d;
                    q.push(make_pair(dist[tmp.r][tmp.c], tmp));
                }
            }
        }
        
    }
    
    return dist[n - 1][n - 1];
}



void mFun() {
    int n;
    int cnt = 1;
    while(cin >> n) {
        if(!n) return;
        clear();
        
        Node s(0,0);
        Node e(n - 1, n - 1);
        
        for(int i = 0; i < n; i++) {
           for(int j = 0; j < n; j++) {
               cin >> g[i][j];
           }
        }
        
        cout << "Problem " << cnt++ << ": "<< dijkstra(s, e, n) << endl;
    }
}


int main()
{
    mFun();
    return 0;
}