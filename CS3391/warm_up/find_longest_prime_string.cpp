#include <iostream>
#include <math.h>
#include <string>

using namespace std;
#define N 100001

bool m[N + 1];

    
bool isPrime(int n) {
    if(n == 2)
        return true;
        
    for (int i = 2; i <= sqrt(n); i++) 
			if (n % i == 0) 
				return false;
	return true;
}

int main()
{
    m[0] = false;
    m[1] = false;
    
    for(int i = 2; i <= N; i++) {
        m[i] = isPrime(i);
    }
        
    string s;
    
    while(cin >> s && s.compare("0")) {
        int len = s.length();
        int res = 0;
        for(int i = 0; i < len; i++) {
            for(int j = 1; j <= 6; j++) {
                
                int tmp;
                
                tmp = stoi(s.substr(i, j));

                if(tmp >= 100000)
                    break;
                    
                if(m[tmp])
                    res = max(res, tmp);
            }
        }
        
        printf("%d\n", res);
    }
    
    
    return 0;
}
