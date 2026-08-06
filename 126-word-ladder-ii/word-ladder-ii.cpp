class Solution {
public:
    vector<vector<string>> findLadders(string beginWord, string endWord, vector<string>& wordList) {
        unordered_set<string> dict(wordList.begin(), wordList.end());
        vector<vector<string>> res;
        if (!dict.count(endWord)) return res;

        unordered_map<string, vector<string>> parents;
        unordered_set<string> visited;
        queue<string> q;

        q.push(beginWord);
        visited.insert(beginWord);
        dict.erase(beginWord);

        bool found = false;
        int n = beginWord.size();

        while (!q.empty() && !found) {
            int sz = q.size();
            unordered_set<string> thisLevelNodes;

            while (sz--) {
                string cur = q.front(); q.pop();
                for (int i = 0; i < n; ++i) {
                    char orig = cur[i];
                    for (char c = 'a'; c <= 'z'; ++c) {
                        if (c == orig) continue;
                        cur[i] = c;
                        if (!dict.count(cur)) continue;

                        parents[cur].push_back(origWith(cur, orig, i));

                        if (!thisLevelNodes.count(cur)) {
                            thisLevelNodes.insert(cur);
                            q.push(cur);
                        }
                        if (cur == endWord) found = true;
                    }
                    cur[i] = orig;
                }
            }

            for (auto &w : thisLevelNodes) {
                dict.erase(w);
            }
        }

        if (!found) return res;

        vector<string> path = {endWord};
        backtrack(endWord, beginWord, parents, path, res);
        return res;
    }

private:
    string origWith(const string &s, char orig, int idx) {
        string t = s;
        t[idx] = orig;
        return t;
    }

    void backtrack(const string &cur, const string &target,
                   unordered_map<string, vector<string>> &parents,
                   vector<string> &path, vector<vector<string>> &res) {
        if (cur == target) {
            vector<string> rev = path;
            reverse(rev.begin(), rev.end());
            res.push_back(rev);
            return;
        }
        auto it = parents.find(cur);
        if (it == parents.end()) return;
        for (const auto &p : it->second) {
            path.push_back(p);
            backtrack(p, target, parents, path, res);
            path.pop_back();
        }
    }
};