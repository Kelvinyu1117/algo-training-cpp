
#include <iostream>

using namespace std;


void m() {
    int k, a, b, v;
    while(cin >> k >> a >> b >> v) {
        bool done = false;
        
        int res = 0;
        
        while(!done) {
            int cnt = res + min((k - 1) * res, b);
            if(cnt * v >= a)
                done = true;
            else
                res++;    
        }
        
        cout << res << endl;
    }
}


int main()
{
    m();

    return 0;
}
