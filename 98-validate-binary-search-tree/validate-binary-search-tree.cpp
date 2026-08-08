class Solution {
public:
    bool isValidBST(TreeNode* root) {
        long long prev = LLONG_MIN;
        stack<TreeNode*> st;

        while (root || !st.empty()) {
            while (root) {
                st.push(root);
                root = root->left;
            }

            root = st.top();
            st.pop();

            if (root->val <= prev) return false;

            prev = root->val;
            root = root->right;
        }

        return true;
    }
};