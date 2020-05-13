#include <iostream>

using namespace std;

int main()
{
    int a, b;
    int k;
    
    cin >> k;
    cin >> a >> b;
    
    bool res = false;
    
    for(int i = a; i <= b; i++) {
        res |= i % k == 0;
    }
    
    if(res)
        cout << "OK" << endl;
    else
        cout << "NG" << endl;

    return 0;
}
