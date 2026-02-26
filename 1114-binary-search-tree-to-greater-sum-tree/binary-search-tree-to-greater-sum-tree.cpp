class Solution {
public:
    int sum = 0;
    void reverseinorder(TreeNode* root){
        // right root left
        if(root==NULL) return;
        reverseinorder(root->right);
        root -> val += sum;
        sum = root -> val;
        reverseinorder(root->left);
    }
    TreeNode* bstToGst(TreeNode* root) {
        reverseinorder(root);
        return root; 
    }
};