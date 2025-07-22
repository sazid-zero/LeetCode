class Solution {
public:
    string convert(string s, int numRows) {
        if (numRows == 1 || s.length() <= numRows) return s;

        string x = "";
        for (int row = 0; row < numRows; row++) {
            int i = row;
            int first = (numRows - row - 1) * 2;
            int second = row * 2;
            bool firstdone = true;

            while(i < s.length()) {
                x += s[i];

                if(first == 0) 
                i += second;
                else if(second == 0) 
                i += first;
                else 
                i += firstdone ? first : second;

                firstdone = !firstdone;
            }
        }

        return x;
    }
};
