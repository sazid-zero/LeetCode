class Solution {
public:
    int threeSumClosest(vector<int>& nums, int target) {
        sort(nums.begin(),nums.end());
        int sum = 0;
        int dif = INT_MAX;
        int n = nums.size();
        
        for(int i = 0; i<n; i++){
            int left = i+1;
            int right = n-1;

            while(left<right){
                int sm = nums[i]+nums[left]+nums[right];
                int rm = abs(target-sm);

                if(rm == 0)
                return sm;

                if(rm < dif){
                dif = rm;
                sum = sm;
                }

                if(sm>target)
                right--;
                else
                left++;

            }
        }
        return sum;

        
    }
};