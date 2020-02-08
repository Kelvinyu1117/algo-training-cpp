# Prime Number

## Sieve of Eratosthenes
### Time Complexity: O(nlog(logn))
```cpp
bool prime[N];
void SoE() {
    std::fill_n(prime, N, true);
    for(int i = 2; i * i <= N; i++) {
        if(prime[i]) {
            for(int j = i * i; j <= N; j += i)
                prime[j] = 0;
        }
    }
}
```