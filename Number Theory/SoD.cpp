// SoD - Sum of Divisors [sqrt]
vector<int> sod;

void sieve_sod(int n) {
    sod.assign(n + 1, 0);
    for (int i = 1; i <= n; ++i) {
        for (int j = i; j <= n; j += i) {
            sod[j] += i;
        }
    }
}

// SoD - Sieve
vector<int> sod;

void sieve_sod(int n) {
    sod.assign(n + 1, 0);
    for (int i = 1; i <= n; ++i) {
        for (int j = i; j <= n; j += i) {
            sod[j] += i;
        }
    }
}
