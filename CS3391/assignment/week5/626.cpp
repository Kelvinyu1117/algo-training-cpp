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
vector<int> dp(1000005);
/* 
    the state dp[i] represents dp[i] different ways there are to hold those i items
    initially, the dp[i] must be 1, as the 2^x = 1, for x = 0, and x must be <= n
    for each i, the ways for holding i items += the ways for holding i - 2^x items
*/

int solve(int n, int m) {
    for(int i = 0; i <= n; i++)
        dp[i] = 0;
    
    dp[0] = 1;
    for(int i = 0; pow(m, i) <= n; i++) {
        int p = pow(m, i);
        for(int j = 1; j <= n; j++) {
            if(j >= p)
                dp[j] = (dp[j] + dp[j - p]) % 1000000007;
        }
    }
    return dp[n];
}
void m() {
    int n, m;
    while(cin >> n >> m) {
        cout << solve(n, m) << endl;
    }
}



int main()
{
    m();

    return 0;
}
