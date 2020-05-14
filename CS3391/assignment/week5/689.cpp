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

#define N 1000000
using namespace std;



vector<int> a(N);
void m() {
    int k;
    while(cin >> k) {
        if (k == 0) return;
        
        vector<int> v;
        
        for(int i = 0; i < k; i++) {
            cin >> a[i];
        }
        
        for (int i = 0; i < k; i++)
        {
            // find the first number > current number
            int index = upper_bound(v.begin(), v.end(), a[i]) - v.begin();
            if(index == v.size()) v.push_back(a[i]);
            else v[index] = a[i];
        }
         
        cout << v.size() << endl;
    }
}
int main()
{
    m();

    return 0;
}
