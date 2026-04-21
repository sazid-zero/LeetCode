class Solution {
public:
    vector<vector<int>> combinationSum2(vector<int>& candidates, int target) {
        sort(candidates.begin(), candidates.end());
        vector<vector<int>> ans;
        vector<int> path;
        dfs(0, target, candidates, path, ans);
        return ans;
    }

    void dfs(int start, int target,
             const vector<int>& candidates,
             vector<int>& path,
             vector<vector<int>>& ans) {

        if (target == 0) {
            ans.push_back(path);
            return;
        }

        for (int i = start; i < (int)candidates.size(); ++i) {
            if (i > start && candidates[i] == candidates[i - 1])
                continue;

            int val = candidates[i];
            if (val > target) break; 

            path.push_back(val);
            dfs(i + 1, target - val, candidates, path, ans);
            path.pop_back();
        }
    }
};