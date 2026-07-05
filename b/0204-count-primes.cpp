class Solution {
public:
    int countPrimes(int n) {
        if (n <= 2) return 0;
        vector<char> isPrime(n, 1); 
        isPrime[0] = isPrime[1] = 0;
        int primeCount = n - 2; 
        for (long long i = 2; i * i < n; i++) {
            if (isPrime[i]) {
                for (long long j = i * i; j < n; j += i) {
                    if (isPrime[j]) {
                        isPrime[j] = 0;
                        primeCount--; 
                    }
                }
            }
        }

        return primeCount; 
    }
};