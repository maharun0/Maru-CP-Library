// LCS - Longest Common Subsequence
vector<vector<int>> dp;
int LCS(string s, string p){
    int n = s.size() + 1, m = p.size() + 1;

    dp.assign(n, vector<int> (m, 0)); // dp[n][m]

    for (int i = 1; i < n; i++){
        for (int j = 1; j < m; j++){

            int i0 = i-1, j0 = j-1; // 0 based index

            if (s[i0] == p[j0]){
                dp[i][j] = dp[i-1][j-1] + 1; 
            } else {
                dp[i][j] = max(dp[i-1][j], dp[i][j-1]);
            }
        }
    }

    return dp[n-1][m-1];
}