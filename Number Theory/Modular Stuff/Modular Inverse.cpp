const ll m = (ll)1e9+7;

ll binpow(ll a, ll b) { // log b
    a %= m;
    ll res = 1;
    while (b > 0) {
        if (b & 1)
            res = res * a % m;
        a = a * a % m;
        b >>= 1;
    }
    return res;
}


ll mod_inv(ll a) { return binpow(a, m-2); } // 1 / a
vector<ll> invOf = {0, mod_inv(1), mod_inv(2)};