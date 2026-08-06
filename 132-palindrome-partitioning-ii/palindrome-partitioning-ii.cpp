class Solution {
public:
    int minCut(string s) {
        int n = s.size();
        vector<vector<bool>> isPal(n, vector<bool>(n, false));
        for (int i = 0; i < n; ++i) {
            isPal[i][i] = true;
        }
        for (int len = 2; len <= n; ++len) {
            for (int i = 0; i + len - 1 < n; ++i) {
                int j = i + len - 1;
                if (len == 2) isPal[i][j] = (s[i] == s[j]);
                else isPal[i][j] = (s[i] == s[j]) && isPal[i + 1][j - 1];
            }
        }

        vector<int> dp(n);
        for (int i = 0; i < n; ++i) {
            int best = i;
            for (int j = 0; j <= i; ++j) {
                if (isPal[j][i]) {
                    int cuts = (j == 0) ? 0 : dp[j - 1] + 1;
                    best = min(best, cuts);
                }
            }
            dp[i] = best;
        }

        return dp[n - 1];
    }
};