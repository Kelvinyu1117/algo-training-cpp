#include <iostream>
#include <algorithm>
using namespace std;

#define N 100000000
int arr[(N >> 6) + 1];
#define isPrime(n) (arr[n >> 6] & (1 << ((n >> 1) & 31)))
#define setPrime(n) (arr[n >> 6] |= (1 << ((n >> 1) & 31)))

/* optimization
    1. use bitset
    2. consider only odd number
*/
void sieve()
{
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
}

bool is_p(long n)
{
    if ((n % 2) == 0 || n < 2)
        return false;
    return !isPrime(n);
}

int main()
{
    sieve();
    int n;

    while (cin >> n)
    {
        if (n <= 3)
        {
            printf("%ld is not the sum of two primes!\n", n);
        }
        else if (n & 1)
        { // odd
            if (is_p(n - 2))
            {
                printf("%ld is the sum of %ld and %ld.\n", n, 2, n - 2);
            }
            else
            {
                printf("%ld is not the sum of two primes!\n", n);
            }
        }
        else
        {
            bool done = false;
            int i;
            if ((n / 2) % 2 == 0)
                i = n / 2 - 1;
            else
                i = n / 2;

            for (; i > 0 && !done; i -= 2)
            {
                if (is_p(i) && is_p(n - i) && n - i != i)
                {
                    printf("%ld is the sum of %ld and %ld.\n", n, i, n - i);
                    done = true;
                }
            }
            if (!done)
            {
                printf("%ld is not the sum of two primes!\n", n);
            }
        }
    }

    return 0;
}
