class Solution {
public:
    vector<vector<int>> subsetsWithDup(vector<int>& nums) {
        sort(nums.begin(), nums.end());
        vector<vector<int>> ans;
        vector<int> path;
        backtrack(0, nums, path, ans);
        return ans;
    }

    void backtrack(int start, const vector<int>& nums,
                   vector<int>& path, vector<vector<int>>& ans) {
        ans.push_back(path);

        for (int i = start; i < (int)nums.size(); ++i) {
            if (i > start && nums[i] == nums[i - 1]) continue;

            path.push_back(nums[i]);
            backtrack(i + 1, nums, path, ans);
            path.pop_back();
        }
    }
};