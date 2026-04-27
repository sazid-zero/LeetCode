class Solution {
public:
    string convertToTitle(int columnNumber) {
        string res;
        while (columnNumber > 0) {
            columnNumber--;
            int rem = columnNumber % 26;
            char c = 'A' + rem;
            res = c + res;
            columnNumber /= 26;
        }
        return res;
    }
};