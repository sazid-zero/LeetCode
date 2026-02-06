class Solution {
public:
    bool canJump(vector<int>& nums) {
        int n = nums.size();
        bool flag = true;
        int steps = nums[0];
        for(int i = 1; i<n;i++){
           if(steps == 0){
            flag = false;
            break;
           }
           else if(nums[i] >= steps){
            steps = nums[i];
           }
           else
           steps--;
        }
        return flag;
    }
};