class Solution {
public:
    string simplifyPath(string path) {
        vector<string> st;
        string comp;
        path += '/';
        for (char c : path) {
            if (c == '/') {
                if (!comp.empty()) {
                    if (comp == "..") {
                        if (!st.empty()) st.pop_back();
                    } else if (comp != ".") {
                        st.push_back(comp);
                    }
                    comp.clear();
                }
            } else {
                comp += c;
            }
        }
        string res;
        for (const string& s : st) {
            res += '/' + s;
        }
        return res.empty() ? "/" : res;
    }
};