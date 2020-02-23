#include <iostream>
#include <vector>
#include <queue>
#define N 10020
using namespace std;
struct State {
    int digit[4];
    int num;
    int dist;
};



bool primes[N];
void SoE() {
    std::fill_n(primes, N, true);
    
    for(int i = 2; i * i <= N; i++) {
        if(primes[i]) {
            for(int j = i * i; j <= N; j += i)
                primes[j] = 0;
        }
    }
}

int getPrimeCode(int digit[4]) {
    return digit[0] + digit[1] * 10 + digit[2] * 100 + digit[3] * 1000;    
}

void setDigit(State &s) {
    int i = 0;
    int num = s.num;
    while(num) {
        s.digit[i++] = num % 10;
        num /= 10;
    }
}

void mFun() {
    SoE();
    int t, s, d;
    
    while(cin >> t) {
        while(t--) {
            cin >> s >> d;
            if(s > d) { // assert s <= d
                int tmp = s;
                s = d;
                d = tmp;
            }
            
            bool v[N];
            std::fill_n(v, N, false);
            
            State p;
            p.num = s;
            p.dist = 0;
            setDigit(p);
            queue<State> q;
            q.push(p);
            
            bool hasPath = false;
            
            int res = 0;
            while(!q.empty()) {
                State curr = q.front(); q.pop();
                
                if(curr.num == d)
                {
                    hasPath = true;
                    res = curr.dist;
                    break;
                }
                
                
                if(!v[curr.num]) {
                    vector<int> y;
                    for(int i = 0; i < 4; i++) {
                        for(int j = 0; j <= 9; j++) {
                            int tmp[4] = {curr.digit[0], curr.digit[1], curr.digit[2], curr.digit[3]};
                            if(i == 3 && j == 0) continue;
                            
                            tmp[i] = j;
                            
                            if(primes[getPrimeCode(tmp)] && !v[getPrimeCode(tmp)])
                                q.push({{tmp[0], tmp[1], tmp[2], tmp[3]}, getPrimeCode(tmp), curr.dist + 1});
                        }
                    }
                    
                    int a = 10;
                    
                    v[curr.num] = 1;
                }
            }
            
            if(hasPath) {
                cout << res << endl;
            }else{
                cout << "Impossible" << endl;
            }
        }
    }
}

int main()
{
    mFun();

    return 0;
}
