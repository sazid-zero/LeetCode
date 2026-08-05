class Solution {
public:
    TreeNode* buildTree(vector<int>& inorder, vector<int>& postorder) {
        unordered_map<int, int> inMap;
        for (int i = 0; i < inorder.size(); i++) {
            inMap[inorder[i]] = i;
        }
        
        int postIndex = postorder.size() - 1;
        return build(inorder, postorder, inMap, 0, inorder.size() - 1, postIndex);
    }
    
    TreeNode* build(vector<int>& inorder, vector<int>& postorder, unordered_map<int, int>& inMap, int inStart, int inEnd, int& postIndex) {
        if (inStart > inEnd) return nullptr;
        
        int rootVal = postorder[postIndex--];
        TreeNode* root = new TreeNode(rootVal);
        
        int inIndex = inMap[rootVal];
        
        root->right = build(inorder, postorder, inMap, inIndex + 1, inEnd, postIndex);
        root->left = build(inorder, postorder, inMap, inStart, inIndex - 1, postIndex);
        
        return root;
    }
};