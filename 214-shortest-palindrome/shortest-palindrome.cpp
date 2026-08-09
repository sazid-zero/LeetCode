class Solution {
public:
    string shortestPalindrome(string s) {
        string rev = s;
        reverse(rev.begin(), rev.end());
        string t = s + "#" + rev;
        int n = t.size();
        vector<int> pi(n, 0);
        for (int i = 1; i < n; ++i) {
            int j = pi[i - 1];
            while (j > 0 && t[i] != t[j]) j = pi[j - 1];
            if (t[i] == t[j]) ++j;
            pi[i] = j;
        }
        int len = pi[n - 1];
        string prefix = rev.substr(0, rev.size() - len);
        return prefix + s;
    }
};