// Sieve of Eratosthenes
int N = 1e5 + 10;
vector<bool> isPrime(N, true);
vector<int> primes;

void sieve() {
    isPrime[0] = isPrime[1] = false;
    for (int i = 4; i < N; i += 2)
        isPrime[i] = false;

    for (int i = 3; i < N; i += 2) {
        if (isPrime[i]) {
            for (int j = 2*i; j < N; j += i) {
                isPrime[j] = false;
            }
        }
    }

    primes.push_back(2);
    for (int i = 3; i < N; i += 2) {
        if (isPrime[i]) {
            primes.push_back(i);
        }
    }
}