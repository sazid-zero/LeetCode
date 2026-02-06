class Solution {
public:
    int majorityElement(vector<int>& nums) {
        map<int , int> m;
        int maxElement = nums[0];
        int maxCount = 0;

        for (int x : nums) {
             m[x]++;
            if (m[x] > maxCount) {
             maxCount = m[x];
             maxElement = x;
    }
}
    return maxElement;
    }
};