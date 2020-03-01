#include <iostream>
#include <string>
#include <queue>
using namespace std;

struct state {
    int r;
    int c;
    int dist;
};


bool isValid(int r, int c) {
    return r >= 0 && r < 8 && c >= 0 && c < 8;
}

void input(bool v[8][8], state &s, state &e) {
    for(int i = 0; i < 8; i++) {
            string str;
            cin >> str;
            for(int j = 0; j < 8; j++) {
                if(str[j] == '#') {
                    s.r = i;
                    s.c = j;
                } else if(str[j] == '@') {
                    e.r = i;
                    e.c = j;
                }else if(str[j] == '-') {
                    v[i][j] = 0;
                }else if(str[j] == '*'){
                    v[i][j] = 1;
                }
            }
        }
}
void mFun() {
    int t;
    cin >> t;
    for(int k = 1; k <= t; k++) {
        state s;
        state e;
        bool v[8][8] = {0};
        
        input(v, s, e);
        
        queue<state> q;
        s.dist = 0;
        e.dist = 0;
        
        q.push(s);
        
        bool done = false;
        int res = 0;
        
        while(!q.empty()) {
            state curr = q.front(); q.pop();
            
            if(curr.r == e.r && curr.c == e.c) {
                done = true;
                res = curr.dist;
                break;
            }
            
            int dir[8][2] ={{-2, -1}, {2, -1}, {-1, -2}, {1, -2}, {-2, 1}, {2, 1}, {-1, 2}, {1, 2}};
            
            if(!v[curr.r][curr.c]) {
                for(int i = 0; i < 8; i++) {
                    state tmp = {curr.r, curr.c, curr.dist + 1};
                    tmp.r += dir[i][0];
                    tmp.c += dir[i][1];
                    if(isValid(tmp.r, tmp.c)) {
                        if(!v[tmp.r][tmp.c])
                            q.push({tmp.r, tmp.c, tmp.dist});
                    }
                }
                
                v[curr.r][curr.c] = 1;
            }
        }
        
        if(done) {
            cout << "Case " << k << ": " << res;
        }else {
            cout << "Case " << k << ": IMPOSSIBLE"; 
        }
        
        
        cout << endl;
    }
}
int main()
{   
    mFun();
    return 0;
}