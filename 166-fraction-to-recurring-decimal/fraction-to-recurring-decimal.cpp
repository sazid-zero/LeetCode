class Solution {
public:
    string fractionToDecimal(int numerator, int denominator) {
        if (numerator == 0) return "0";

        string ans;
        if ((numerator < 0) ^ (denominator < 0)) ans.push_back('-');

        long long n = llabs((long long)numerator);
        long long d = llabs((long long)denominator);

        long long integerPart = n / d;
        ans += to_string(integerPart);

        long long rem = n % d;
        if (rem == 0) return ans;

        ans.push_back('.');
        unordered_map<long long, int> seen;

        while (rem != 0) {
            if (seen.count(rem)) {
                int pos = seen[rem];
                ans.insert(ans.begin() + pos, '(');
                ans.push_back(')');
                break;
            }
            seen[rem] = ans.size();
            rem *= 10;
            ans.push_back('0' + (rem / d));
            rem %= d;
        }

        return ans;
    }
};