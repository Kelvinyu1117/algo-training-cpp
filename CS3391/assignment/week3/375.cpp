// not yet corret
#include <iostream>
#include <queue>
using namespace std;

struct state {
    int cup[4];
    int dist;
};

int state_encode(state s) {
    return s.cup[0] * 2 + s.cup[1] * 4 + s.cup[2] * 8 + s.cup[3] * 16;
}

bool isFound(state s, int t) {
    return s.cup[0] == t || s.cup[1] == t || s.cup[2] == t || s.cup[3] == t;
}

int main()
{
    int c[4], t;
    
    while(cin >> c[0] >> c[1] >> c[2] >> c[3] >> t) {
        bool v[1000] = {false};
        queue<state> q;
        state s0 = {{0, 0, 0, 0}, 0};
        state res;
        q.push(s0);
        bool done = false;
        while(!q.empty()) {
            state curr = q.front(); q.pop();
            
            if(isFound(curr, t)) {
                res = curr;
                done = true;
                break;
            }
            // empty one of the cup
            if(!v[state_encode(curr)]) {
                q.push({{0, curr.cup[1], curr.cup[2], curr.cup[3]}, curr.dist + 1});
                q.push({{curr.cup[0], 0, curr.cup[2], curr.cup[3]}, curr.dist + 1});
                q.push({{curr.cup[0], curr.cup[1], 0, curr.cup[3]}, curr.dist + 1});
                q.push({{curr.cup[0], curr.cup[1], curr.cup[2], 0}, curr.dist + 1});
                
                // fill in one of the cup
                q.push({{c[0], curr.cup[1], curr.cup[2], curr.cup[3]}, curr.dist + 1});
                q.push({{curr.cup[0], c[1], curr.cup[2], curr.cup[3]}, curr.dist + 1});
                q.push({{curr.cup[0], curr.cup[1], c[2], curr.cup[3]}, curr.dist + 1});
                q.push({{curr.cup[0], curr.cup[1], curr.cup[2], c[3]}, curr.dist + 1});
                
                for(int i = 0; i < 4; i++) {
                    if(curr.cup[i] != 0) {
                        for(int j = 0; j < 4; j++) {
                            if(i != j) {
                                int diff = c[j] - curr.cup[j];
                                int tmp_s[4] = {curr.cup[0], curr.cup[1], curr.cup[2], curr.cup[3]};
                                if(curr.cup[i] - diff < 0) {
                                    tmp_s[i] = 0;
                                }else {
                                    tmp_s[i] -= diff;
                                }
                                
                                if(curr.cup[i] + curr.cup[j] >= c[j]) {
                                    tmp_s[j] = c[j];
                                }else {
                                    tmp_s[j] += curr.cup[i];
                                }
                                
                                q.push({{tmp_s[0], tmp_s[1], tmp_s[2], tmp_s[3]}, curr.dist + 1});
                            }
                        }
                    }
                }
            }
            
            v[state_encode(curr)] = 1;
        }
        
        if(!done)
            cout << -1 << endl;
        else
            cout << res.dist << endl;
    }
    return 0;
}
