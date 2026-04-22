class Solution {
public:
    string simplifyPath(string path) {
        vector<string> st;
        string curr;

        for (int i = 0; i <= (int)path.size(); ++i) {
            if (i == (int)path.size() || path[i] == '/') {
                if (!curr.empty()) {
                    if (curr == ".") {
                       
                    } else if (curr == "..") {
                        if (!st.empty()) st.pop_back();
                    } else {
                        st.push_back(curr); 
                    }
                    curr.clear();
                }
            } else {
                curr.push_back(path[i]);
            }
        }

        if (st.empty()) return "/";

        string res;
        for (auto &dir : st) {
            res.push_back('/');
            res += dir;
        }
        return res;
    }
};