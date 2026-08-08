class Solution {
public:
    int numTrees(int n) {
        vector<unsigned long long> dp(n + 1);
        dp[0] = dp[1] = 1;

        for (int nodes = 2; nodes <= n; nodes++) {
            for (int left = 0; left < nodes; left++) {
                dp[nodes] += dp[left] * dp[nodes - 1 - left];
            }
        }

        return dp[n];
    }
};