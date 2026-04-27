class Solution {
public:
    int majorityElement(vector<int>& nums) {
        int candidate = 0;
        int count = 0;

        for (int x : nums) {
            if (count == 0) {
                candidate = x;
                count = 1;
            } else {
                count += (x == candidate) ? 1 : -1;
            }
        }

        return candidate;
    }
};