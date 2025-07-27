class Solution {
public:
    int divide(int dividend, int divisor) {
        long long div = (long long)dividend/divisor;
        if(div > pow(2,31) -1)
        return pow(2,31) - 1;
        else if(div < pow(-2,31))
        return pow(-2,31);

        else
        return (int)div;
    }
};