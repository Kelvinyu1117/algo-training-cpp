
#include <iostream>

using namespace std;

void solve(int a[], int n, int r) {
    int s = 1;
    int e = 2;
    
    int tmp_s = 1;
    int tmp_e = 2;
    
    int sum = 0;
    int tmp_sum = 0;
    
    for(int i = 1; i < n; i++) {
        if(tmp_sum >= 0) {
            tmp_sum += a[i];
        }else {
            tmp_sum = a[i];
            tmp_s = i;
        }
        
        tmp_e = i + 1;
        
        if (tmp_sum > sum || (tmp_sum == sum && tmp_e - tmp_s > e - s)) {
            sum = tmp_sum;
            s = tmp_s;
            e = tmp_e;
        }
    }
    
    if(sum > 0) {
        printf("The nicest part of route %d is between stops %d and %d\n", r, s, e);
    }else {
        printf("Route %d has no nice parts\n", r);
    }
}


int main()
{
    int b;
    int a[20002] = {0};
    while(cin >> b){
        for(int i = 1; i <= b; i++) {
            int s;
            cin >> s;
            a[0] = s;
            for(int i = 1; i < s; i++) {
                cin >> a[i];
            }
            
            solve(a, s, i);
        }
    }

    return 0;
}
