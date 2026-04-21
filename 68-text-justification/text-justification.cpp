class Solution {
public:
    vector<string> fullJustify(vector<string>& words, int maxWidth) {
        vector<string> res;
        int n = words.size();
        int i = 0;

        while (i < n) {
            int lineLen = words[i].size();
            int j = i + 1;

           
            while (j < n && lineLen + 1 + (int)words[j].size() <= maxWidth) {
                lineLen += 1 + words[j].size();
                ++j;
            }

            int numWords = j - i;
            int totalChars = 0;
            for (int k = i; k < j; ++k) totalChars += words[k].size();

            string line;
           
            if (j == n || numWords == 1) {
                line = words[i];
                for (int k = i + 1; k < j; ++k) {
                    line.push_back(' ');
                    line += words[k];
                }
            
                line.append(maxWidth - (int)line.size(), ' ');
            } else {
                int spaces = maxWidth - totalChars;
                int gaps = numWords - 1;
                int spaceEach = spaces / gaps;
                int extra = spaces % gaps; 

                for (int k = i; k < j; ++k) {
                    line += words[k];
                    if (k == j - 1) break; 
                    int currSpaces = spaceEach + (extra > 0 ? 1 : 0);
                    extra = max(0, extra - 1);
                    line.append(currSpaces, ' ');
                }
            }

            res.push_back(line);
            i = j;
        }

        return res;
    }
};