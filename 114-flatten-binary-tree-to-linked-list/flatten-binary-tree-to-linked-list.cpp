class Solution {
public:
    void flatten(TreeNode* root) {
        TreeNode* current = root;

        while (current) {
            if (current->left) {
                TreeNode* predecessor = current->left;

                while (predecessor->right)
                    predecessor = predecessor->right;

                predecessor->right = current->right;
                current->right = current->left;
                current->left = nullptr;
            }

            current = current->right;
        }
    }
};