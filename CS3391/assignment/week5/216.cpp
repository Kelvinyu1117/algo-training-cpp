#include <iostream>
#include <string>
#define N 1050
using namespace std;

/* longest common subsequence lcs(s1, s2, m, n);

   if(m == 0 || n == 0) return 0;
   else
      if(s1[m] == s2[n]) return 1 + lcs(s1, s2, m - 1, n - 1);
      else  return max(lcs(s1, s2, m, n - 1), lcs(s1, s2, m - 1, n));
*/
int solve(string a, string b) {
    int m = a.length();
    int n = b.length();
    
    int dp[N][N];
    
    for(int i = 0; i < m; i++) {
        dp[i][0] = 0;
    }
    
    for(int j = 0; j < n; j++) {
        dp[0][j] = 0;
    }
    
    for(int i = 1; i <= m; i++) {
        for(int j = 1; j <= n; j++) {
            if(a[i - 1] == b[j - 1]) {
                dp[i][j] = dp[i - 1][j - 1] + 1;
            }else {
               dp[i][j] = max(dp[i - 1][j], dp[i][j - 1]);
            }
        }
    }
    
    return dp[m][n];
}

void mFun() {
    string s1 = "";
    string s2 = "";
    while(cin >> s1 >> s2) {
        int res = solve(s1, s2);
        cout << res << endl;
    }    
}


int main()
{
    mFun();

    return 0;
}
