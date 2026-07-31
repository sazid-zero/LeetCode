class Solution {
public:
    string minWindow(string s, string t) {
        if (t.empty()) return "";
        vector<int> need(128, 0);
        for (char c : t) need[c]++;
        int required = 0;
        for (int i = 0; i < 128; ++i)
            if (need[i] > 0) required++;
        int formed = 0;
        vector<int> window(128, 0);
        int l = 0, r = 0;
        int ansLen = INT_MAX, ansStart = 0;
        while (r < (int)s.size()) {
            char c = s[r];
            window[c]++;
            if (need[c] > 0 && window[c] == need[c]) formed++;
            while (l <= r && formed == required) {
                if (r - l + 1 < ansLen) {
                    ansLen = r - l + 1;
                    ansStart = l;
                }
                char cl = s[l];
                window[cl]--;
                if (need[cl] > 0 && window[cl] < need[cl]) formed--;
                l++;
            }
            r++;
        }
        return ansLen == INT_MAX ? "" : s.substr(ansStart, ansLen);
    }
};