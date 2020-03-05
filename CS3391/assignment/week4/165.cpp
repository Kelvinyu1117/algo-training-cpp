#include <iostream>
#include <math.h>
#include <iomanip>

using namespace std;
struct state {
    int x;
    int y;
};


state stones[210];
double dist[210][210];


double calDist(int x1, int y1, int x2, int y2) {
    return sqrt((x1 - x2)*(x1 - x2) + (y1 - y2)*(y1 - y2));
}


// Floyd–Warshall algorithm
// normal state transition: min(dis[i][j], dist[i][k] + dist[k][j])
void floyd(int n) {
    for(int k = 0; k < n; k++) {
        for(int i = 0; i < n; i++) {
            for(int j = 0; j < n; j++) { 
                dist[i][j] = min(dist[i][j], max(dist[i][k], dist[k][j])); // shortest path with largest weighting, check max(segment i->j, segment j->k) 
            }
        }
    }
}


void mFun() {
    int n;
    int cnt = 0;
    cout << fixed << setprecision(3);
    while(cin >> n) {
        if(!n) return;
  
        for(int i = 0; i < n; i++) {
            cin >> stones[i].x >> stones[i].y;
        }
        
        for(int i = 0; i < n; i++) {
            for(int j = i + 1; j < n; j++) {
                dist[i][j] = dist[j][i] = calDist(stones[i].x, stones[i].y, stones[j].x, stones[j].y);
            }
        }
        
        floyd(n);
        
        cout << "Scenario #" << ++cnt << endl;;
        cout << "Frog Distance = " << dist[0][1] << endl << endl;
    }

}
int main()
{
    mFun();
    return 0;
}
