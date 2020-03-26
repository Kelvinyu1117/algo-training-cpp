
#include <iostream>
#include <math.h>
using namespace std;

#define INF 1e4 + 3;
int dp[100005];
int nums[100005];



int solve(int n) {
    for(int i = 0; i <= n; i++) {
        dp[i] = 0;
    }
    dp[0] = 0;
    dp[1] = abs(nums[1] - nums[0]);

    for(int i = 2; i < n; i++) {
        dp[i] = min(dp[i - 1] + abs(nums[i] - nums[i - 1]), dp[i - 2] + abs(nums[i] - nums[i - 2]));        
    }
    
    return dp[n - 1];
}

int main()
{
    int n;
    cin >> n;
    
    for(int i = 0; i < n; i++)
        cin >> nums[i];
        
    cout << solve(n) << endl;

    return 0;
}
