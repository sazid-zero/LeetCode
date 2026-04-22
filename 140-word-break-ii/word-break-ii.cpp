class Solution {
public:
    vector<string> wordBreak(string s, vector<string>& wordDict) {
        unordered_set<string> dict(wordDict.begin(), wordDict.end());
        unordered_map<int, vector<string>> memo;
        return dfs(0, s, dict, memo);
    }

    vector<string> dfs(int start, string& s, unordered_set<string>& dict,
                       unordered_map<int, vector<string>>& memo) {
        if (memo.count(start)) return memo[start];
        vector<string> res;
        if (start == s.size()) {
            res.push_back("");
            return memo[start] = res;
        }
        for (int end = start + 1; end <= s.size(); ++end) {
            string word = s.substr(start, end - start);
            if (!dict.count(word)) continue;
            vector<string> sub = dfs(end, s, dict, memo);
            for (string& tail : sub) {
                if (tail.empty()) res.push_back(word);
                else res.push_back(word + " " + tail);
            }
        }
        return memo[start] = res;
    }
};