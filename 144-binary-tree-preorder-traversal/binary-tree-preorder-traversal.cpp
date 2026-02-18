class Solution {
public:
    void preorder(TreeNode* root, vector<int>& ans){
        if(root==NULL) return; // base case
        ans.push_back(root->val); //(Root)
        preorder(root->left, ans); // (left) 
        preorder(root->right, ans); //(Right)
    }
    vector<int> preorderTraversal(TreeNode* root) {
        vector<int> ans;
        preorder(root, ans);
        return ans;
    }
};