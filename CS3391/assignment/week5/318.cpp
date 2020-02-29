#include <iostream>
#include <string>
#include <algorithm>

#define rep(x, s, n) for(int x = s; x < n; x++)
using namespace std;

int f[100005] = {0};


void kmp_build(string s, int n) { // standard !!!
    
    int j = 0;
    
    f[0] = 0;
    
    rep(i, 1, n) {
        
        while(j > 0 and s[i] != s[j])
            j = f[j - 1];
        
        if(s[i] == s[j]) 
            j++;
        
        f[i] = j;
    }
    
}


int kmp_search(string s, string r) { // search for the far-est postion of r can matach s 
    int m, n = s.length(); 
    
    int j = 0;
    rep(i, 0, n) {
       while(j > 0 and s[i] != r[j])
            j = f[j - 1];
        
        if(s[i] == r[j])
            j++;
    }
    
    return j;
}


void mFun() {
    string s;
    
    while(cin >> s) {
        int len = s.length();
        string r(s);
        reverse(r.begin(), r.end());
        
        kmp_build(r, len);
        
        int res = kmp_search(s, r);
        
        cout << s;
        for(int i = res; i < len; i++)
            cout << r[i];
            
        cout << endl;
    }
}



int main()
{
    
    
    mFun();
    return 0;
}