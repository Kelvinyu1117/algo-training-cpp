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

#define MAXN 25
using namespace std;

/*
       s1        s2
    'abcde' -> 'bcgfe'
    let m, n be the len of the string
    Base case:
    if(m == 0)
        return n; // if it is a s1 is empty string, the cost for s1 -> s2 must = len(s2) = n;
    if(n == 0)  
        return m; // if it is a s2 is empty string, the cost for s1 -> s2 must = len(s1) = m; 
    if(s1[m] == s2[n]) -> no cost return dist(m - 1, n - 1)  
    if(s1[m] != s2[n])
        ->return min{three operations}
        -> insert s2[n] to s1 -> assume it is inserted in position m + 1, 
            position m is actually the next position for processing alredy, 
            as we compare s2[n] and s1[m + 1] and it is matched, so we
            return 1 + dist(m, n - 1)
        
        -> delete s1[m] -> so the pointer m should --, and s1[m] and s2[n] is not matched
            so, return 1 + dist(m - 1, n)
        
        -> replace s1[m] by s2[n], then s1[m] will = s2[n], so m--, n--
            return 1 + dist(m - 1, n - 1);
*/

void getPath(int p[MAXN][MAXN], string s1, string s2, int i, int j) {
    if ( !i && !j ) 
        return;
	if(p[i][j] == 0) {
	    getPath(p, s1, s2, i-1, j-1 );
	}
	else if ( p[i][j] == 1 ) {
		getPath(p, s1, s2, i-1, j );
		
		printf("D%c%02d",s1[i-1],j+1);
	}else if ( p[i][j] == 2 ) {
		getPath(p, s1, s2, i, j-1 );
		
		printf("I%c%02d",s2[j-1],j);
	}else if ( p[i][j] == 3 ){
		getPath(p, s1, s2, i-1, j-1 );
		
		printf("C%c%02d",s2[j-1],j);
	}
}


void solve(string a, string b){
    int dp[MAXN][MAXN];
    int p[MAXN][MAXN];
    int m = a.length();
    int n = b.length();
    // initialization
    for(int i = 0; i < MAXN; i++) {
        for(int j = 0; j < MAXN; j++) {
            p[i][j] = 0;
        }
    }
    for(int i = 0; i < MAXN; i++) {
        dp[0][i] = dp[i][0] = i;
        p[0][i] = 2; // delete a[i] 
        p[i][0] = 1; // insert b[i] to a[i + 1]
    }
    
    for(int i = 1; i <= m; i++) {
        for(int j = 1; j <= n; j++) {
            if(a[i - 1] == b[j - 1])
                dp[i][j] = dp[i - 1][j - 1];
            else 
                dp[i][j] = 1 + min(dp[i][j - 1], min(dp[i - 1][j], dp[i - 1][j - 1]));
        
            if(dp[i][j] == dp[i - 1][j - 1]) {
                p[i][j] = 0;
            }
            if(dp[i][j] == 1 + dp[i][j - 1]) { // insert
                p[i][j] = 2;
            }
            
            if(dp[i][j] == 1 + dp[i - 1][j]) { // delete
                p[i][j] = 1;
            }
            if(dp[i][j] == 1 + dp[i - 1][j - 1]) { // replace
                p[i][j] = 3;
            }
        }
    }
    
    getPath(p, a, b, m, n);
}



void mFun() {
    
    string s1, s2;
    while(cin >> s1 >> s2 && s1 != "#") {
        solve(s1, s2);
        printf("E\n");
    }
}



int main()
{
    mFun();

    return 0;
}