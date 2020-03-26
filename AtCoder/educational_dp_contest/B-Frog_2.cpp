
#include <iostream>
#include <math.h>
using namespace std;

#define INF 1e9;
int dp[100005];
int nums[100005];



int solve(int n, int k) {
    for(int i = 0; i <= n; i++) {
        dp[i] = INF;
    }
    dp[0] = 0;

    for(int i = 1; i < n; i++) {
        for(int j = 1; j <= k; j++)
            if(i - j >= 0) dp[i] = min(dp[i - j] + abs(nums[i]-nums[i - j]), dp[i]);
    }
    
    return dp[n - 1];
}

int main()
{
    int n, k;
    cin >> n >> k;
    
    for(int i = 0; i < n; i++)
        cin >> nums[i];
        
    cout << solve(n, k) << endl;

    return 0;
}
