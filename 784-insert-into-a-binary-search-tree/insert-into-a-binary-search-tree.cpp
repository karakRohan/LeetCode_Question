//Method :- 2//
class Solution {
public:
    void insert(TreeNode* root, int val){
        if(root==NULL) root = new TreeNode(val);
        else if(root->val > val){ // go left
            if(root -> left == NULL) { // Attach it here
                root -> left =  new TreeNode(val);
            }
            else insert (root->left, val);
        }
        else{ // root - > val < val : go right
            if(root -> right == NULL) { // Attach it here
                root -> right =  new TreeNode(val);
            }
            else insert (root->right, val);
        }
    }
    TreeNode* insertIntoBST(TreeNode* root, int val) {
        insert(root, val);
        if(root==NULL) root = new TreeNode(val);
        return root;
    }
};