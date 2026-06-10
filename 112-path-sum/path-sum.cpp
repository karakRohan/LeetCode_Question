class Solution {
public:
    bool hasPathSum(TreeNode* root, int targetSum) 
    {
        if(root==NULL) return false;
        if(root->left==NULL&&root->right==NULL)return root->val==targetSum;
        int l = hasPathSum(root->left,targetSum-root->val);
        int r = hasPathSum(root->right,targetSum-root->val);
        return l||r;
    }
};