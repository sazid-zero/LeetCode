class Solution {
    int m, n;
    bool dfs(vector<vector<char>>& board, const string& word, int i, int j, int idx) {
        if (idx == (int)word.size()) return true;
        if (i < 0 || j < 0 || i >= m || j >= n || board[i][j] != word[idx]) return false;
        char tmp = board[i][j];
        board[i][j] = '#';
        bool found = dfs(board, word, i + 1, j, idx + 1) ||
                     dfs(board, word, i - 1, j, idx + 1) ||
                     dfs(board, word, i, j + 1, idx + 1) ||
                     dfs(board, word, i, j - 1, idx + 1);
        board[i][j] = tmp;
        return found;
    }
public:
    bool exist(vector<vector<char>>& board, string word) {
        m = board.size();
        n = board[0].size();
        for (int i = 0; i < m; ++i) {
            for (int j = 0; j < n; ++j) {
                if (board[i][j] == word[0] && dfs(board, word, i, j, 0))
                    return true;
            }
        }
        return false;
    }
};