#include <iostream>

using namespace std;

int solve(int n) {
    if(n == 1)
        return 2;
    return 3 * solve(n - 1) + 2;
}
int main()
{
    int n;
    
    while(cin >> n) {

        cout << solve(n) << endl;
    }
    return 0;
}
