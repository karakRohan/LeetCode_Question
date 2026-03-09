class Solution {
public:
    int maxSum = INT_MIN;
    int dfs(TreeNode* root){
        if(root == NULL)
        return 0;

        int left = max(0, dfs(root->left));
        int right = max(0, dfs(root->right));

        int currentPath = left + right + root -> val;
        maxSum = max(maxSum, currentPath);
        return root ->val + max(left, right);
    }
    int maxPathSum(TreeNode* root) {
        dfs(root);
        return maxSum;
    }
};