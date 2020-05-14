#include <iostream>
#include <cmath>
#include <cstdio>
using namespace std;

#define ll long long


ll g, b, u, k, s;

ll gcd(ll a, ll b)
{
    ll c;
    if (a < b)
    {
        c = a;    a = b;
        b = c;
    }
    while (b)
    {
        c = b;
        b = a % b;
        a = c;
    }
    return a;
}

ll ex_gcd(ll a, ll b, ll &x, ll &y)
{
    ll ans, t;
    if (b == 0)
    {
        x = 1;    y = 0;
        return a;
    }
    else
    {
        ans = ex_gcd(b, a % b, x, y);
        t = x;    x = y;
        y = t - (a / b) * y;
    }
    return ans;
}

void mFun()
{
    ll x, y, m, n, l;
    while (cin >> x >> y >> m >> n >> l)
    {
        g = n - m; u = x - y;
		ll ta, tb;
		ll r = ex_gcd(g, l, ta, tb);
		if ((x - y) % r != 0) 
			cout << "Impossible" << endl;
		else {
			g /= r;  u = (x - y)/ r; l /= r;
			ex_gcd(g, l, s, k);
			s *=u;
			k *=u;
			s = s - s / l * l;
			if (s < 0) {
				if (l <= 0)
					s -= l;
				else
					s += l;
			}
			cout << s << endl;;
		}
    }
}


int main() {
    mFun();
}