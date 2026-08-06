class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        unordered_set<int> s(nums.begin(), nums.end());
        int best = 0;

        for (int x : s) {
            if (!s.count(x - 1)) {
                int y = x;
                int len = 1;
                while (s.count(y + 1)) {
                    y++;
                    len++;
                }
                best = max(best, len);
            }
        }

        return best;
    }
};