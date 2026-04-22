class Solution {
public:
    vector<string> restoreIpAddresses(string s) {
        vector<string> res;
        vector<string> parts;
        backtrack(s, 0, parts, res);
        return res;
    }

    void backtrack(const string& s, int idx,
                   vector<string>& parts, vector<string>& res) {
    
        if (parts.size() == 4) {
           
            if (idx == (int)s.size()) {
                res.push_back(parts[0] + "." + parts[1] + "." +
                              parts[2] + "." + parts[3]);
            }
            return;
        }

        int remainingParts = 4 - parts.size();
        int remainingChars = s.size() - idx;
        if (remainingChars < remainingParts ||
            remainingChars > remainingParts * 3) {
            return;
        }

        int num = 0;
        for (int len = 1; len <= 3 && idx + len <= (int)s.size(); ++len) {
            if (len > 1 && s[idx] == '0') break;

            num = num * 10 + (s[idx + len - 1] - '0');
            if (num > 255) break;

            parts.push_back(s.substr(idx, len));
            backtrack(s, idx + len, parts, res);
            parts.pop_back();
        }
    }
};