class Solution {
public:
    int ladderLength(string beginWord, string endWord, vector<string>& wordList) {
        unordered_set<string> dict(wordList.begin(), wordList.end());
        if (!dict.count(endWord)) return 0;

        queue<string> q;
        q.push(beginWord);
        dict.erase(beginWord);

        int level = 1;
        int n = beginWord.size();

        while (!q.empty()) {
            int sz = q.size();
            while (sz--) {
                string cur = q.front(); q.pop();
                if (cur == endWord) return level;

                for (int i = 0; i < n; ++i) {
                    char orig = cur[i];
                    for (char c = 'a'; c <= 'z'; ++c) {
                        if (c == orig) continue;
                        cur[i] = c;
                        if (!dict.count(cur)) continue;
                        dict.erase(cur);
                        q.push(cur);
                    }
                    cur[i] = orig;
                }
            }
            ++level;
        }

        return 0;
    }
};