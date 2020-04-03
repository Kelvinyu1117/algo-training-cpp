#include <iostream>
#include <string>
#include <math.h>
#include <vector>
#include <algorithm>
using namespace std;

#define N 1000050
int arr[(N >> 6) + 1];
bool ppp[N];
#define isPrime(n) (arr[n >> 6] & (1 << ((n >> 1) & 31)))
#define setPrime(n) (arr[n >> 6] |= (1 << ((n >> 1) & 31)))

/* optimization
    1. use bitset
    2. consider only odd number
*/


void swap(int &a, int &b) {
    int tmp = a;
    a = b;
    b = tmp;
}


int numDigit(int num)
{ 
    int cnt = 0; 
    while (num > 0) { 
        cnt++; 
        num /= 10; 
    } 
    return cnt; 
}


bool is_p(long n)
{
    if ((n % 2) == 0 || n < 2)
        return false;
    return !isPrime(n);
}

void rotate(int num, vector<int> &nums) 
{ 
    int digits = numDigit(num); 
    int powTen = pow(10, digits - 1); 
    
    nums.push_back(num);
    
    for (int i = 0; i < digits - 1; i++) { 
  
        int firstDigit = num / powTen; 
  
        // Formula to calculate left shift 
        // from previous number 
        int left 
            = ((num * 10) + firstDigit) 
              - (firstDigit * powTen * 10); 
        
        nums.push_back(left);
        // Update the original number 
        num = left; 
    } 
}

void sieve()
{
    fill(ppp, ppp+N, false);
    for (int i = 3; i * i <= N; i += 2)
    {
        if (!isPrime(i))
        {
            for (int j = i * i; j <= N; j += 2 * i)
            {
                setPrime(j);
            }
        }
    }
    
    
    for(int i = 3; i <= N; i++) {
        if(is_p(i)) {
            vector<int> tmp;
            rotate(i, tmp);
            
            bool yes = true;
            
            for(int i = 0; i < tmp.size() && yes; i++)
                yes = yes & is_p(tmp[i]);
        
            if(yes)
                ppp[i] = true;
            else
                ppp[i] = false;
        }
    }
}





void m() {
    sieve();
    int s, e;
    while(cin >> s >> e) {
        if(s == -1) return;
        
        if(e < s)
            swap(s, e);
        
        int cnt = 0;
        for(int i = s; i <= e; i++) {
            if(ppp[i])
                cnt++;
        }
        if(!cnt)
            cout << "No Circular Primes." << endl;
        else if(cnt == 1)
            cout <<"1 Circular Prime." << endl; 
        else
            cout << cnt << " Circular Primes." << endl;
    }
}


int main()
{
     m();

    return 0;
}
