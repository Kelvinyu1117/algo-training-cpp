#include <iostream>
#include <iostream>
#include <string>
#include <map>

#include <queue>
#include <utility> 
#include <algorithm>

using namespace std;


int main()
{
    string s;
    
    int maxlen = 0;
    map<string, int> mp;
    
    while(getline(cin, s)) {
        
        int len = s.length();
        int i = 0;
        
        while(i < len) {
            string word = "";
            int j = i;
            while(j < len && isalpha(s[j])) {
                j++;
            }
            
            
            for(int k = i; k < j; k++)
                word += tolower(s[k]);
                
            if(word != "")
                mp[word]++;
                
            if(j > i)
                i = j;
            else
                i++;
        }
    }
    
    for(const auto& kv:mp) {
        cout << kv.first << endl;
    }
    
    return 0;
}
