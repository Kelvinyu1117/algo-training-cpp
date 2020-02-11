#include <iostream>

using namespace std;


bool isBalacne(int &weight) {
    int WL, DL, WR, DR;
    cin >> WL >> DL >> WR >> DR;
    
    bool left = true;
    bool right = true;
    if(WL == 0)
        left = isBalacne(WL);

    if(WR == 0)
        right = isBalacne(WR);
    
    weight += WL + WR;
    
    return (WL * DL == WR * DR) && left && right;
}

int main()
{
    int n;
    while(cin >> n) {
        while(n--) {
            int weight = 0;
            bool res = isBalacne(weight);
            if(res)
                cout << "YES" << endl;
            else
                cout << "NO" << endl;
            
            if(n)
                cout << endl;
        }
    }    

    return 0;
}
