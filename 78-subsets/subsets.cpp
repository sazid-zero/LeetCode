class Solution {
public:
    vector<vector<int>> subsets(vector<int>& nums) {
        vector<vector<int>> ans;
        vector<int> path;
        dfs(0, nums, path, ans);
        return ans;
    }

    void dfs(int index, const vector<int>& nums,
             vector<int>& path, vector<vector<int>>& ans) {
        ans.push_back(path);

        for (int i = index; i < (int)nums.size(); ++i) {
            path.push_back(nums[i]);
            dfs(i + 1, nums, path, ans);
            path.pop_back();
        }
    }
};