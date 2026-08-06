class Solution {
public:
    vector<vector<string>> partition(string s) {
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

        vector<vector<string>> res;
        vector<string> cur;
        backtrack(s, 0, cur, res, isPal);
        return res;
    }

    void backtrack(const string &s, int start, vector<string> &cur, vector<vector<string>> &res, const vector<vector<bool>> &isPal) {
        if (start == (int)s.size()) {
            res.push_back(cur);
            return;
        }
        for (int end = start; end < (int)s.size(); ++end) {
            if (isPal[start][end]) {
                cur.push_back(s.substr(start, end - start + 1));
                backtrack(s, end + 1, cur, res, isPal);
                cur.pop_back();
            }
        }
    }
};