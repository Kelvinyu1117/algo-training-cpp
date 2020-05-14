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


using namespace std;

void m() {
    int n, m;
    while(cin >> n >> m) {
        if(!n && !m) return;
        vector<vector<int>> v(100);
        
        for(int i = 0; i < n; i++) {
            for(int j = 0; j < m; j++) {
                int a;
                cin >> a;
                v[i].push_back(a);
            }
        }
        
        bool f = true;
        for(int i = 0; i < n && f; i++) {
            for(int j = 0; j < m && f; j++) {
                if(v[i][j] == 1) {
                    if(i == 0 || j == 0 || i == n - 1 || j == m - 1)
                        f = false;
                }
            }
        }
        
        
        if(f) 
            cout << "4" << endl;
        else
            cout << "2" << endl;
    }
}


int main()
{
    m();
    return 0;
}
