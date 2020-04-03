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
#define INF 2e8
#define N 2000
using namespace std;


map<int, string> i2s;
map<string, int> s2i;
vector<vector<string>> paths(2);

typedef vector<pair<int,int> >VII;
typedef pair<int,int>PII;

bool vis[N];
int dist[N];
int g[N][N];
int pre[N];

void parseInput(string line) {
    int i = 0;
    int len = line.length();
    for(; i < len; i++)
        if(line[i] == ':') break;
    
        
    string s1 = line.substr(0, i);
    
    int j = i;
    for(; j < len - 1; j++)
        if(isspace(line[j]) && isdigit(line[j + 1])) break;
    
    string s2 = line.substr(i + 1, j - i - 1);
    j++;
    
    line = line.substr(j);
    
    stringstream ss;
    ss << line;
    
    int c = 0;
    int a;
    while(ss >> a) {
        if(c == 0) 
            g[s2i[s1]][s2i[s2]] = a;
        else 
            g[s2i[s2]][s2i[s1]] = a;
        c++;
    }
}


void clear() {
    i2s.clear();
    s2i.clear();
    paths[0].clear();
    paths[1].clear();
    paths.clear();
    
    rep(i, 0, N) {
        pre[i] = i;
        vis[i] = false;
        dist[i] = INF;
        rep(j, 0, N) {
            g[i][j] = INF;
        }
    }
    
}


void backtrack(int i, vector<string> &s, bool re) {
    int j = i;
    s.push_back(i2s[i]);
    
    while(pre[j] != j) {
        s.push_back(i2s[pre[j]]);
        j = pre[j];
    }
    
    if(re)
        reverse(s.begin(), s.end());
}


int dijkstra(int s, int e, int n, bool re) {
    int res = 0;
    dist[s] = 0;
    
    priority_queue<PII,VII,greater<PII> >q;
    q.push(make_pair(dist[s], s));
    
    while(!q.empty()) {
        PII curr = q.top(); q.pop();
        
        vis[curr.second] = 1;
        
        if(curr.second == e) {
            res = curr.first;
            break;
        }
        
        for(int i = 1; i <= n; i++) {
            int ds = curr.first + g[curr.second][i];
            if(!vis[i] && ds < dist[i]) {
                dist[i] = ds;
                pre[i] = curr.second;
                q.push(make_pair(dist[i], i));
            }
        }
        
    }
    
    // backtrack the path
    
    vector<string> p;
    
    backtrack(e, p, re);
    
    paths.push_back(p);
    
    return res;
}


void m() {

    int n;
    int t = 0;
    while(~scanf("%d\n", &n)) {
        clear();
            
        int s, e;
        for(int i = 1; i <= n; i++) {
            string a;
            getline(cin, a);
            
            if(a == "office")
                s = i;
            if(a == "hall")
                e = i;
                
            s2i[a] = i;
            i2s[i] = a;
        }
        
        int m;
        scanf("%d\n", &m);
        
        for(int i = 0; i < m; i++) {
            string s;
            getline(cin, s);
            parseInput(s);
        }
        
        
        int res = dijkstra(s, e, n, true);
        
        rep(i, 0, N) {
             pre[i] = i;
            vis[i] = false;
            dist[i] = INF;
        }
        
        res += dijkstra(e, s, n, false);
        
        cout << res << endl;
        
        for(auto c: paths[0]) {
            cout << c << " -> ";
        }
        
        for(int i = paths[1].size() - 2; i >= 0; i--) {
            cout << paths[1][i];
            if(i) {
                cout << " -> ";
            }
        }
        
        cout << endl << endl;
    }
}



int main()
{
    m();
    
    return 0;
}
