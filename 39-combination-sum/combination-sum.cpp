class Solution {
public:
    vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
        vector<vector<int>> ans;
        vector<int> path;
        dfs(0, target, candidates, path, ans);
        return ans;
    }

    void dfs(int idx, int target,
             vector<int>& candidates,
             vector<int>& path,
             vector<vector<int>>& ans) {

        if (target == 0) {
            ans.push_back(path);
            return;
        }
        if (idx == (int)candidates.size() || target < 0) {
            return;
        }
        path.push_back(candidates[idx]);
        dfs(idx, target - candidates[idx], candidates, path, ans);
        path.pop_back();
        dfs(idx + 1, target, candidates, path, ans);
    }
};