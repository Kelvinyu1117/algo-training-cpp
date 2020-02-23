#include <iostream>
#include <string>
#include <iomanip>
#include <sstream>


using namespace std;

void mFun() {
    string s;
    cout << fixed << setprecision(4);
    int cnt = 0;
    while(getline(cin, s)) {
        if(cnt > 0)
            cout << endl;
        long double sum = 0;
        stringstream ss;
        ss << s;
        long double a;
        while(ss >> a) {
            sum += a;
        }
       
	    
	    
	    cout << sum << endl;
	    cnt++;
    }
}

int main()
{
    mFun();

    return 0;
}
