class Solution {
public:
    vector<int> findSubstring(string s, vector<string>& words) {
        vector<int> v;
        if (words.empty() || s.empty()) return v;

        int len = words[0].size();
        int cnt = words.size();
        int total = len * cnt;

        unordered_map<string, int> freq;
        for (string &w : words) freq[w]++;

        for (int i = 0; i < len; i++) {
            int left = i, count = 0;
            unordered_map<string, int> win;
            for (int right = i; right + len <= s.length(); right +=len) {
                string word = s.substr(right,len);
                if (freq.find(word) != freq.end()) {
                    win[word]++;
                    count++;

                    while (win[word] > freq[word]) {
                        string leftWord = s.substr(left, len);
                        win[leftWord]--;
                        left += len;
                        count--;
                    }

                    if (count == cnt)
                        v.push_back(left);
                } else {
                    win.clear();
                    count = 0;
                    left = right + len;
                }
            }
        }
        return v;
    }
};
