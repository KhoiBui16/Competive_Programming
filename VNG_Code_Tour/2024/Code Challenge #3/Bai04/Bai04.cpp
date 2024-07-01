#include <iostream>
#include <vector>
#include <cmath>

using namespace std;

bool isPrime(long long N) {
    if (N <= 1) return false;
    if (N <= 3) return true;
    if (N % 2 == 0 || N % 3 == 0) return false;
    for (long long i = 5; i * i <= N; i += 6) {
        if (N % i == 0 || N % (i + 2) == 0)
            return false;
    }
    return true;
}

vector<long long> primeFactors(long long N) {
    vector<long long> factors;

    // Check for number of 2s
    while (N % 2 == 0) {
        factors.push_back(2);
        N /= 2;
    }

    // Check for odd factors
    for (long long i = 3; i * i <= N; i += 2) {
        while (N % i == 0) {
            factors.push_back(i);
            N /= i;
        }
    }

    // If N is a prime number greater than 2
    if (N > 2) {
        factors.push_back(N);
    }

    return factors;
}

int main() {
    long long S, K, N;
    cin >> S >> K >> N;

    vector<long long> factors;

    long long currentPrime = S;
    int count = 0;

    while (count < K) {
        if (isPrime(currentPrime)) {
            if (N % currentPrime == 0) {
                factors.push_back(currentPrime);
                N /= currentPrime;
                ++count;
            } else {
                ++currentPrime;
            }
        } else {
            ++currentPrime;
        }
    }

    if (N > 1) {
        vector<long long> remainingFactors = primeFactors(N);
        factors.insert(factors.end(), remainingFactors.begin(), remainingFactors.end());
    }

    for (int i = 0; i < factors.size(); ++i) {
        cout << factors[i];
        if (i < factors.size() - 1) {
            cout << " ";
        }
    }
    cout << "\n";

    return 0;
}
