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