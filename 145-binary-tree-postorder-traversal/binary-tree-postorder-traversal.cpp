class Solution {
public:
    void postorder(TreeNode* root, vector<int>& ans){
        if(root==NULL) return; // base case
        postorder(root->left, ans); // (left)
        postorder(root->right, ans); //(Right)
        ans.push_back(root->val); //(Root) 
    }
    vector<int> postorderTraversal(TreeNode* root) {
        vector<int> ans;
        postorder(root, ans);
        return ans;
    }
};