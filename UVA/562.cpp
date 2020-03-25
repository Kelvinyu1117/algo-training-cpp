#include <iostream>

#include <math.h>

#include <algorithm>


#define MAXN 105
using namespace std;

int dp[MAXN][MAXN * 500];
int w[MAXN];

int main() {
  int n;

  cin >> n;
  while (n--) {
    int t;
    int sum = 0;

    cin >> t;
    for (int i = 0; i < t; i++) {
      cin >> w[i];
      sum += w[i];
    }

    int target = sum >> 1; // most fair division is that they have the same amount

    for (int i = 0; i <= t; i++) {
      for (int j = 0; j <= target; j++) {
        if (i == 0 || j == 0)
          dp[i][j] = 0;
        else if (j >= w[i - 1])
          dp[i][j] = max(w[i - 1] + dp[i - 1][j - w[i - 1]], dp[i - 1][j]);
        else
          dp[i][j] = dp[i - 1][j];
      }
    }

    int res = dp[t][target];

    cout << abs(sum - res * 2) << endl; // absolute difference of (sum - res) - res 
  }

  return 0;
}