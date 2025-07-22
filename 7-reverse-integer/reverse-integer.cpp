class Solution {
public:
    int reverse(int x) {
        long long val = x;
        bool isNegative = val < 0;
        val = isNegative ? -val : val;

        string s = to_string(val);
        ::reverse(s.begin(), s.end());

        long long reversed = stoll(s);
        if (isNegative)
            reversed *= -1;

        if (reversed < INT_MIN || reversed > INT_MAX)
            return 0;
        return static_cast<int>(reversed);
    }
};
