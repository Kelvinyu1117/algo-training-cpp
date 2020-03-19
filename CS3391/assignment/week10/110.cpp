#include <iostream>
#include <iostream>
#include <string.h>
#include <queue>
#include <utility> 
#include <algorithm>

using namespace std;


int main()
{
    string s;
    
    string word = "";
    int maxlen = 0;
    while(getline(cin, s)) {
        int len = s.length();
        int i = 0;
        while(i < len) {
            int j = i;
            while(j < len && (isalpha(s[j]) || s[j] == '-')) {
                j++;
            }
            
            if(j - i > maxlen) {
                maxlen = j - i;
                word = s.substr(i, maxlen);
            }
            
            if(j > i)
                i = j;
            else
                i++;
        }
    }
    
    for(auto c: word) {
        cout << (char) tolower(c);
    }
    cout << endl;

    return 0;
}
