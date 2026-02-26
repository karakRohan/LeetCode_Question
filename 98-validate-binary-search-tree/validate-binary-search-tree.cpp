// Method - 2
class Solution {
public:
    void inorder(TreeNode* root, TreeNode* &prev, bool &flag){
        if(root==NULL) return; // base case
        inorder(root->left, prev, flag); // (left)
        if(prev != NULL){
            if(root->val <= prev->val){
                flag = false;
                return;
            }
        }
        prev = root;
        inorder(root->right, prev, flag); //(Right)
    }
    
    bool isValidBST(TreeNode* root) {
        TreeNode* prev = NULL;
        bool flag = true;
        inorder(root, prev, flag);
        return flag;
    }
};