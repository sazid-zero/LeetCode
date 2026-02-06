class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
        vector<int>v;
        unordered_map<int,int>mp;
        for(auto x: nums){
            mp[x]++;
            if(mp[x] < 3)
            v.push_back(x);
        }
        for(int i = 0; i<v.size(); i++){
            nums[i] = v[i];
        }
        return v.size();
    }
};