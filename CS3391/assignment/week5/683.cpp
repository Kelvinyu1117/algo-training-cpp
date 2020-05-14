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
