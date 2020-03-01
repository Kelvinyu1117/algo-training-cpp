#include <iostream>
#include <string>
#include <algorithm>

#define rep(x, s, n) for(int x = s; x < n; x++)

using namespace std;


string solve(string s) {
    
   int ins[26] = {0};
   int len = s.length();
   
   string r(s);
   
   sort(r.begin(), r.end());
   reverse(r.begin(), r.end());
   
   string ans;
 

   
   int j = 0;
   
   rep(i, 0, len) {
       // find current char index in s;
       int index = 0;
       rep(k, 0, s.length()) {
           if(s[k] == r[i]) {
                index = k;
                if(k + 1 >= s.length())
                    s = s.substr(0, k) + "X";
                else if(k == 0)
                    s = "X" + s.substr(k + 1);
                else
                    s = s.substr(0, k) + "X" + s.substr(k + 1);
                
                break;
           }
       }
       
       if(index >= j) {
           ans += r[i];
           j = max(j, index);
       }
   }
   
   return ans;
}


void mFun() {
    int n;
    cin >> n;
    while(n--) {
        string s;
        cin >> s;
        
        cout << solve(s) << endl;
    }
}

int main()
{
    mFun();
    return 0;
}