#include <iostream>
#include <cstdio>
#include <iomanip>
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
#include <cfloat>

using namespace std;
const int MAXN = 1000005;

namespace SuffixArray {
    int n, sa[MAXN], rank[MAXN], height[MAXN];
    char str[MAXN];

    void buildSA(int m) {
        static int fir[MAXN], sec[MAXN], buc[MAXN], temp[MAXN];
        n = strlen(str);
        str[n++] = 0;

        std::fill(buc, buc + m, 0);
        for (int i = 0; i < n; i++) buc[(int) str[i]]++;
        for (int i = 1; i < m; i++) buc[i] += buc[i - 1];
        for (int i = 0; i < n; i++) rank[i] = buc[(int) str[i]] - 1;

        for (int l = 1; l < n; l <<= 1) {
            for (int i = 0; i < n; i++)
                fir[i] = rank[i], sec[i] = i + l < n ? rank[i + l] : 0;

            std::fill(buc, buc + n, 0);
            for (int i = 0; i < n; i++) buc[sec[i]]++;
            for (int i = 1; i < n; i++) buc[i] += buc[i - 1];
            for (int i = n - 1; ~i; i--) temp[--buc[sec[i]]] = i;

            std::fill(buc, buc + n, 0);
            for (int i = 0; i < n; i++) buc[fir[i]]++;
            for (int i = 1; i < n; i++) buc[i] += buc[i - 1];
            for (int i = n - 1; ~i; i--) sa[--buc[fir[temp[i]]]] = temp[i];

            rank[sa[0]] = 0;
            bool unique = true;
            for (int i = 1; i < n; i++) {
                rank[sa[i]] = rank[sa[i - 1]];
                if (fir[sa[i]] == fir[sa[i - 1]] && sec[sa[i]] == sec[sa[i - 1]])
                    unique = false;
                else rank[sa[i]]++;
            }

            if (unique) break;
        }
    }

    void getHeight() {
        int k = 0;
        for (int i = 0; i < n - 1; i++) {
            k ? k-- : 0;
            int j = sa[rank[i] - 1];
            while (str[i + k] == str[j + k]) k++;
            height[rank[i]] = k;
        }
    }
}


void m() {
    int t;
    cin >> t;
    while(t--) {
        char *s = SuffixArray::str;
        scanf("%s", s);
        
        SuffixArray::buildSA(128);
        int *sa = SuffixArray::sa, n = SuffixArray::n;
        
        SuffixArray::getHeight();
        int *height = SuffixArray::height + 1;
        
        int ans = 0, len = 0;
        
        for (int i = 1; i < n - 1; i++) 
            ans = max(ans,  height[i]);
            
        if(ans != 0) {
            for(int i = 1; i < n - 1; i++) {
                if(ans == height[i]) {
                    for(int j = 0; j < ans; j++)
                        printf("%c", s[sa[i]+j]);
                    while(i < n - 1 && ans == height[i])
                        len++, i++;
                    break;
                }
            }
            cout << " " << len+1 << endl;
        }else {
            cout << "No repetitions found!" << endl;
        }
    }
}




int main()
{
    m();

    return 0;
}
