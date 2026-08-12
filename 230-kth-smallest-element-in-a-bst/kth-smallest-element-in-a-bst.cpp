class Solution {
public:
    void solve(TreeNode* root, vector<int> &arr){
        if(!root){
            return;
        }
        solve(root->left, arr);
        arr.push_back(root->val);
        solve(root->right, arr);
    }
    
    int kthSmallest(TreeNode* root, int k) {
        vector<int> arr;
        solve(root,arr);
        return arr[k-1];
    }
};