#include <iostream>

using namespace std;

int main()
{
    unsigned long long x;
    cin >> x;
    unsigned long long amount = 100;
    
    
    bool done = false;
    int i = 0;
    while(!done) {
        unsigned long long interest = amount * 0.01;
        
        amount += interest;
        
        if(amount >= x)
            done = true;
            
        i++;
    }
    
    
    cout << i << endl;
    return 0;
}
