class Solution {
public:
    TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {
        unordered_map<int, int> inMap;
        for (int i = 0; i < inorder.size(); i++) {
            inMap[inorder[i]] = i;
        }
        
        int preIndex = 0;
        return build(preorder, inMap, 0, inorder.size() - 1, preIndex);
    }
    
    TreeNode* build(vector<int>& preorder, unordered_map<int, int>& inMap, int inStart, int inEnd, int& preIndex) {
        if (inStart > inEnd) return nullptr;
        
        int rootVal = preorder[preIndex++];
        TreeNode* root = new TreeNode(rootVal);
        
        int inIndex = inMap[rootVal];
        
        root->left = build(preorder, inMap, inStart, inIndex - 1, preIndex);
        root->right = build(preorder, inMap, inIndex + 1, inEnd, preIndex);
        
        return root;
    }
};