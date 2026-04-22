class Solution {
public:
    bool wordBreak(string s, vector<string>& wordDict) {
        int n = s.size();
        unordered_set<string> st(wordDict.begin(), wordDict.end());
        vector<bool> dp(n + 1, false);
        dp[0] = true;
        int maxLen = 0;
        for (auto& w : wordDict) maxLen = max(maxLen, (int)w.size());
        for (int i = 1; i <= n; ++i) {
            for (int len = 1; len <= maxLen && len <= i; ++len) {
                if (!dp[i - len]) continue;
                if (st.count(s.substr(i - len, len))) {
                    dp[i] = true;
                    break;
                }
            }
        }
        return dp[n];
    }
};