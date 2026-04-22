class Solution {
public:
    vector<vector<int>> ans;
    vector<int> path;

    void dfs(int start, int n, int k) {
        if ((int)path.size() == k) {
            ans.push_back(path);
            return;
        }
        for (int i = start; i <= n - (k - (int)path.size()) + 1; ++i) {
            path.push_back(i);
            dfs(i + 1, n, k);
            path.pop_back();
        }
    }

    vector<vector<int>> combine(int n, int k) {
        dfs(1, n, k);
        return ans;
    }
};