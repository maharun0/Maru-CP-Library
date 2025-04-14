// NoD - Number of Divisors [sqrt]
int NoD(int n) {
     int cnt = 0;
     for (int i = 1; i * i <= n; ++i) {
         if (n % i == 0) {
             ++cnt;
             if (n / i != i) {
                  ++cnt;
             }
         }
     }
     return cnt;
}

// NoD - Sieve
vector<int> nod;

void sieve_nod(int n) {
    nod.assign(n + 1, 0);
    for (int i = 1; i <= n; ++i) {
        for (int j = i; j <= n; j += i) {
            ++nod[j];
        }
    }
}