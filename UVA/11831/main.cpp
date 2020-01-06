#include <iostream>

using namespace std;

void move(char map[101][101], int n, int m, int &x, int &y, char &ori, char cmd, int &cnt) {
    if(cmd == 'D') {
        if(ori == 'N') {
            ori = 'L';
        }else if(ori == 'S') {
            ori = 'O';
        }else if(ori == 'L') {
            ori = 'S';
        }else if(ori == 'O') {
            ori = 'N';
        }
    }else if(cmd == 'E') {
         if(ori == 'N') {
            ori = 'O';
        }else if(ori == 'S') {
            ori = 'L';
        }else if(ori == 'L') {
            ori = 'N';
        }else if(ori == 'O') {
            ori = 'S';
        }
    }else if(cmd == 'F') {
        if(ori == 'N') {
            if(x - 1 >= 0 && map[x - 1][y] != '#')
                x -= 1;
        }else if(ori == 'S') {
            if(x + 1 < n && map[x + 1][y] != '#') 
                x += 1;
            
        }else if(ori == 'L') {
             if(y + 1 < m && map[x][y + 1] != '#')
                y += 1;
        }else if(ori == 'O') {
             if(y - 1 >= 0 && map[x][y - 1] != '#')
                y -= 1;
        }
         
        if(map[x][y] == '*') {
            cnt++;
            map[x][y] = '.';
        }
    }
}


int main()
{
    int n, m , s;
    while(cin >> n >> m >> s) {
        if(!n && !m && !s)
            return 0;
        
        char map[101][101] = {0};
        
        int x , y;
        char ori;
        int cnt = 0;
        for(int i = 0; i < n; i++) {
            for(int j = 0; j < m; j++) {
                cin >> map[i][j]; 
                if(map[i][j] != '.' && map[i][j] != '*' && map[i][j] != '#') {
                    x = i;
                    y = j;
                    ori = map[i][j];
                }
            }
        }
        
        
        for(int i = 0; i < s; i++) {
            char cmd;
            cin >> cmd;
            move(map, n, m, x, y, ori, cmd, cnt);
        }
        
        cout << cnt << endl;
    }

    return 0;
}