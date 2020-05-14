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
    int t;
    cin >> t;
    while(t--) {
        string s;
        cin >> s;
        
        int res = 0;
        int sum = 0;
        vector<int> st;
        vector<int> ed;
        int n = 0;
        int strLen = s.length();
        for (int i = 0; i < strLen; ++i) {
		    sum += min(s[i] - 'A', 26 - (s[i] - 'A'));
		    
		    if(i >= 1 && s[i] == 'A') {
		        int j = i + 1;
		        while(j < strLen && s[j] == 'A')
		            j++;
		        
		        st.push_back(i);
		        ed.push_back(j);
		        n++;
		    }
        }
        
        res = sum + strLen - 1;
        
      
        for(int i = 0; i < n; i++) {
            res = min(res, sum + min(((st[i] - 1) * 2) + strLen - ed[i], ((strLen - ed[i]) * 2) + st[i] - 1));
        }
        
        cout << res << endl;
    }
}



int main()
{
    m();

    return 0;
}
