class Solution {
public:
    int maxProduct(vector<int>& nums) {
        long long curMax = nums[0];
        long long curMin = nums[0];
        long long ans = nums[0];

        for (int i = 1; i < nums.size(); i++) {
            long long num = nums[i];
            long long prevMax = curMax;
            long long prevMin = curMin;

            curMax = std::max({num, prevMax * num, prevMin * num});
            curMin = std::min({num, prevMax * num, prevMin * num});

            ans = std::max(ans, curMax);
        }

        return (int)ans;
    }
};