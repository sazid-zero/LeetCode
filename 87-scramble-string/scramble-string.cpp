class Solution {
public:
    unordered_map<string, bool> memo;

    bool solve(const string& a, const string& b) {
        string key = a + "#" + b;
        if (memo.count(key)) return memo[key];
        if (a == b) return memo[key] = true;
        if (a.size() != b.size()) return memo[key] = false;

        int cnt[26] = {0};
        for (int i = 0; i < (int)a.size(); ++i) {
            cnt[a[i] - 'a']++;
            cnt[b[i] - 'a']--;
        }
        for (int i = 0; i < 26; ++i) {
            if (cnt[i] != 0) return memo[key] = false;
        }

        int n = a.size();
        for (int i = 1; i < n; ++i) {
            if (solve(a.substr(0, i), b.substr(0, i)) &&
                solve(a.substr(i), b.substr(i))) {
                return memo[key] = true;
            }
            if (solve(a.substr(0, i), b.substr(n - i)) &&
                solve(a.substr(i), b.substr(0, n - i))) {
                return memo[key] = true;
            }
        }

        return memo[key] = false;
    }

    bool isScramble(string s1, string s2) {
        memo.clear();
        return solve(s1, s2);
    }
};