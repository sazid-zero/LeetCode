class Solution {
public:
    bool isIsomorphic(string s, string t) {
        if (s.size() != t.size()) return false;
        vector<int> m1(256, -1), m2(256, -1);

        for (int i = 0; i < (int)s.size(); ++i) {
            unsigned char c1 = s[i];
            unsigned char c2 = t[i];

            if (m1[c1] == -1 && m2[c2] == -1) {
                m1[c1] = c2;
                m2[c2] = c1;
            } else {
                if (m1[c1] != c2 || m2[c2] != c1) return false;
            }
        }

        return true;
    }
};