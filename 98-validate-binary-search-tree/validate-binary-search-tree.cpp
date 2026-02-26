// Method - 2
class Solution {
public:
    TreeNode* prev = NULL;
    bool flag = true;
    void inorder(TreeNode* root){
        if(root==NULL) return; // base case
        inorder(root->left); // (left)
        if(prev != NULL){
            if(root->val <= prev->val){
                flag = false;
                return;
            }
        }
        prev = root;
        inorder(root->right); //(Right)
    }
    
    bool isValidBST(TreeNode* root) {
        inorder(root);
        return flag;
    }
};