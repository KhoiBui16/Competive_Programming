#include <bits/stdc++.h>
using namespace std;
vector<long long> Eratosthenes(long long n)
{
    vector<bool> isPrime(n + 1, true);
    vector<long long> primes;
    isPrime[0] = isPrime[1] = false;
    for (long long i = 2; i * i <= n; ++i)
        if (isPrime[i])
            for (long long j = i * i; j <= n; j += i)
                isPrime[j] = false;
    for (long long i = 2; i <= n; ++i)
        if (isPrime[i])
            primes.push_back(i);
    return primes;
}
vector<long long> findPrimeFactors(long long M)
{
    vector<long long> primes;
    vector<long long> primeList = Eratosthenes(sqrt(M) + 1);
    for (long long prime : primeList)
        if (M % prime == 0)
        {
            primes.push_back(prime);
            while (M % prime == 0)
                M /= prime;
        }
    if (M > 1)
        primes.push_back(M);
    return primes;
}
int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    long long M;
    cin >> M;
    vector<long long> primeFactors = findPrimeFactors(M);
    vector<char> message;
    for (long long prime : primeFactors)
        message.push_back('A' + (prime) % 26);
    sort(message.begin(), message.end());
    for (char c : message)
        cout << c;
    return 0;
}