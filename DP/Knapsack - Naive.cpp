// Naive KnapSack
ll S, n;
vector<ll> s, v;
vector<vector<ll>> dp;

ll KnapSack(ll S){
    ll n = s.size();
    dp.assign(n+1, vector<ll> (S+1, 0));
    for (int i = 1; i <= n; i++){
        for (int cap = 1; cap <= S; cap++){
            
            ll naNiye = dp[i-1][cap], niye = 0;
            if (s[i] <= cap) niye = v[i] + dp[i-1][cap - s[i]];

            dp[i][cap] = max(naNiye, niye);
        }
    }

    return dp[n][S];
}