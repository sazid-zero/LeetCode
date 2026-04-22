class Solution {
public:
    int singleNumber(vector<int>& nums) {
        int ans = 0;
        for (int bit = 0; bit < 32; ++bit) {
            int cnt = 0;
            for (int x : nums) {
                if ((x >> bit) & 1) cnt++;
            }
            if (cnt % 3) ans |= (1 << bit);
        }
        return ans;
    }
};