class Solution {
public:
    string countAndSay(int n) {
        string s = "1";
        for (int i = 2; i <= n; ++i) {
            string t;
            int len = s.size();
            for (int j = 0; j < len; ) {
                char ch = s[j];
                int cnt = 0;
                while (j < len && s[j] == ch) {
                    ++cnt;
                    ++j;
                }
                t += to_string(cnt);
                t += ch;
            }
            s = t;
        }
        return s;
    }
};