class Solution {
public:
    void preorder(TreeNode* root, vector<int>& ans){
        if(root==NULL) return; // base case
        preorder(root->left, ans); // (left)
        ans.push_back(root->val); //(Root) 
        preorder(root->right, ans); //(Right)
    }
    vector<int> inorderTraversal(TreeNode* root) {
        vector<int> ans;
        preorder(root, ans);
        return ans;
    }
};