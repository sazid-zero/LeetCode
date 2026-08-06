class Solution {
public:
    vector<string> wordBreak(string s, vector<string>& wordDict) {
        unordered_set<string> dict(wordDict.begin(), wordDict.end());
        int n = s.size();
        vector<bool> dp(n + 1, false);
        dp[0] = true;

        for (int i = 1; i <= n; ++i) {
            for (int j = 0; j < i; ++j) {
                if (dp[j] && dict.count(s.substr(j, i - j))) {
                    dp[i] = true;
                    break;
                }
            }
        }

        vector<string> res;
        if (!dp[n]) return res;

        vector<string> path;
        backtrack(s, 0, dict, dp, path, res);
        return res;
    }

private:
    void backtrack(const string &s, int start, const unordered_set<string> &dict,
                   const vector<bool> &dp, vector<string> &path, vector<string> &res) {
        int n = s.size();
        if (start == n) {
            string sentence;
            for (int i = 0; i < (int)path.size(); ++i) {
                if (i) sentence += ' ';
                sentence += path[i];
            }
            res.push_back(sentence);
            return;
        }

        for (int end = start + 1; end <= n; ++end) {
            if (!dp[end]) continue;
            string word = s.substr(start, end - start);
            if (!dict.count(word)) continue;

            path.push_back(word);
            backtrack(s, end, dict, dp, path, res);
            path.pop_back();
        }
    }
};