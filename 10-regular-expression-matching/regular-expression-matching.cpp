class Solution {
public:
    bool isMatch(string s, string p) {
        int n = s.length(), m = p.length();

    if (m == 0) return n == 0;

    // If next char is '*', try all possibilities
    if (m > 1 && p[1] == '*') {
        char prev = p[0];
        // Try 0 or more matches of p[0]
        for (int i = 0; i <= n; i++) {
            if (i > 0 && !(s[i - 1] == prev || prev == '.')) break;

            if (isMatch(s.substr(i), p.substr(2))) return true;
        }
        return false;
    } else if (n > 0 && (p[0] == s[0] || p[0] == '.')) {
        // Match current char and move to next
        return isMatch(s.substr(1), p.substr(1));
    } else {
        return false;
    }}
};