class Solution {
public:
    int removeElement(vector<int>& nums, int val) {
        vector<int>vec;
        for(auto x : nums){
            if(x != val)
            vec.push_back(x);
        }
        for(int i = 0; i<vec.size(); i++)
        nums[i] = vec[i];
        return vec.size();
    }
};