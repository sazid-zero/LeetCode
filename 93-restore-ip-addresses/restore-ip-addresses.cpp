class Solution {
public:
    vector<string> res;

    void backtrack(const string& s, int idx, int parts, string cur) {
        int n = s.size();
        if (parts == 4) {
            if (idx == n) res.push_back(cur);
            return;
        }

        int remaining = n - idx;
        int minNeeded = (4 - parts);
        int maxAllowed = 3 * (4 - parts);
        if (remaining < minNeeded || remaining > maxAllowed) return;

        int num = 0;
        for (int len = 1; len <= 3 && idx + len <= n; ++len) {
            if (len > 1 && s[idx] == '0') break;
            num = num * 10 + (s[idx + len - 1] - '0');
            if (num > 255) break;

            string next = cur.empty() ? to_string(num) : cur + "." + to_string(num);
            backtrack(s, idx + len, parts + 1, next);
        }
    }

    vector<string> restoreIpAddresses(string s) {
        res.clear();
        if (s.size() > 12) return res;
        backtrack(s, 0, 0, "");
        return res;
    }
};