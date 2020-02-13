#include <iostream>

using namespace std;

char kingdom[55][55];

// m = # of rows, n = # of columns
int dfs(int m, int n, int i, int j) {
    if(i < 0 || i > m || j < 0 || j > n || kingdom[i][j] != '#')
        return 0;
        
    kingdom[i][j] = 'X';
    
    int sum = 0;
    // six direction for hexagon
    
    if(i == 0) {
        if(j - 1 >= 0 && kingdom[i][j - 1] == '.')
            sum++;
            
        if(j + 1 < n && kingdom[i][j + 1] == '.')
            sum++;
            
        if(i + 1 < m && j - 1 >= 0 && kingdom[i + 1][j - 1] == '.')
            sum++;
            
        if(i + 1 < m && j + 1 < n && kingdom[i + 1][j] == '.')
            sum++;
            
        sum += dfs(m, n, i - 1, j - 1);
        sum += dfs(m, n, i - 1, j + 1);
        sum += dfs(m, n, i, j - 1);
        sum += dfs(m, n, i, j);
    }else if(i == m - 1) {
        if(i - 1 >= 0 && j - 1 >= 0 && kingdom[i - 1][j - 1] == '.')
            sum++;
            
        if(i - 1 >= 0 && j + 1 < n && kingdom[i - 1][j] == '.')
            sum++;
            
        if(j - 1 >= 0 && kingdom[i][j - 1] == '.')
            sum++;
            
        if(j + 1 < n && kingdom[i][j + 1] == '.')
            sum++;
        
        sum += dfs(m, n, i - 1, j - 1);
        sum += dfs(m, n, i - 1, j);
        sum += dfs(m, n, i, j - 1);
        sum += dfs(m, n, i, j + 1);
    }else {
        if(i - 1 >= 0 && j - 1 >= 0 && kingdom[i - 1][j - 1] == '.')
            sum++;
            
        if(i - 1 >= 0 && j + 1 < n && kingdom[i - 1][j + 1] == '.')
            sum++;
            
        if(j - 1 >= 0 && kingdom[i][j - 1] == '.')
            sum++;
            
        if(j + 1 < n && kingdom[i][j + 1] == '.')
            sum++;
            
        if(i + 1 < m && j - 1 >= 0 && kingdom[i + 1][j - 1] == '.')
            sum++;
            
        if(i + 1 < m && j + 1 < n && kingdom[i + 1][j + 1] == '.')
            sum++;
            
        sum += dfs(m, n, i - 1, j - 1);
        sum += dfs(m, n, i - 1, j + 1);
        sum += dfs(m, n, i, j - 1);
        sum += dfs(m, n, i, j + 1);
        sum += dfs(m, n, i + 1, j - 1);
        sum += dfs(m, n, i + 1, j + 1);
    }
    
    
    return sum;
}


int main()
{
    int i = 0;
    string s;
    while(true) {
        int len; 
        int m;
        int n;
        getline(cin, s);
        
        if(!cin)
            len = 0;
        else 
            len = s.length();
            
        if(len != 0) {
            for(int j = 0; j < len; j++) {
                kingdom[i][j] = s[j];
            }
            i++;
            n = len;
        }else {
            m = i;
            i = 0;
              
            int res = 0;
            for(int f = 0; f < m; f++) {
                for(int g = 0; g < n; g++) {
                    if(kingdom[f][g] == '#') {
                        res += dfs(m, n, f, g);
                    }
                }
            }
        
            cout << res << endl;
            if(!cin)
                break;
        }
    }

    return 0;
}
