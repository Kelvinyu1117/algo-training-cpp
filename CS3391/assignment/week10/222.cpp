#include <iostream>
#include <string>
#include <iomanip>
#include <cstdlib>


using namespace std;

void mFun() {
    string s;
    while(getline(cin, s)) {
        long double sum = 0;
        int n = s.length();
        int i = 0;
        while(i < n) {
            int j = i;
            bool f = false;
            while(j < n && !isspace(s[j])) {
                j++;
                f = true;
            }
            if(f) {
                sum += (long double) atof(s.substr(i, j).c_str());
                i = j;
            }else
                i++;
        }
        cout << fixed << setprecision(4) << sum << endl;
        cout << endl;
    }
}

int main()
{
    mFun();

    return 0;
}
