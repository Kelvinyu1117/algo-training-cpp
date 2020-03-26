#include <iostream>

using namespace std;

long long fastExp(long long a, long long b) {
  long long res = 1;
  while (b > 0) {
    if (b & 1) res = res * a;
    a = a * a;
    b >>= 1;
  }
  return res;
}

long long fastExpWithMod(long long a, long long b, long long c) {
  long long res = 1;
  while (b > 0) {
    if (b & 1) res = (res * a) % c;
    a = (a * a) %c;
    b >>= 1;
  }
  return res;
}

void m() {
    long long b, p, m;
    
    while(cin >> b >> p >> m) {
        cout << fastExpWithMod(b, p, m) << endl;
    }
}
int main()
{
    m();

    return 0;
}
