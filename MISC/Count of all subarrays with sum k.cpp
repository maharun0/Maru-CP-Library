ll countSubarraySumK(vector<ll>& v, ll& target) {
    int n = v.size();
    map<ll, ll> m = { {0, 1} };

    ll count = 0, sum = 0;
    for (int i = 0; i < n; i++) {
        sum += v[i];
        count += m[sum - target];

        m[sum]++;
    }

    return count;
}