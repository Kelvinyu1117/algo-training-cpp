#include <iostream>

using namespace std;

int a[55][55] = {0};

void dfs(int m, int n, int i, int j) {
    if(i < 0 || j < 0 || i >= m || j >= n || a[i][j] != 1)
        return;
    
    a[i][j] = 0;
    
    int dir[8][2] = {{-1, 0}, {1, 0}, {0, 1}, {0, -1}, {1, 1}, {1, -1}, {-1, 1}, {-1, -1}};
    
    for(int k = 0; k < 8; k++) {
        dfs(m, n, i + dir[k][0], j + dir[k][1]);
    }
    
}

int main()
{
   int m, n;
   while(cin >> n >> m && m && n) {
       for(int i = 0; i < m; i++) {
           for(int j = 0; j < n; j++) {
               cin >> a[i][j];
           }
       }
       
       int res = 0;
       for(int i = 0; i < m; i++) {
           for(int j = 0; j < n; j++) {
              if(a[i][j]) {
                  dfs(m, n, i, j);
                  res++;
              }
           }
       }
       
       cout << res << endl;
   }

    return 0;
}
