//Method :- 3 (Morris Traversal Code) Best Method
class Solution {
public:
    void flatten(TreeNode* root) {
        // Base case Banai age
        if(root==NULL) return;
        TreeNode* curr = root;
        while(curr != NULL){
            if(curr -> left != NULL){
                // save the right
                TreeNode* r = curr -> right;
                curr -> right = curr->left;
                // finding pred(Predecessor)
                TreeNode* pred = curr -> left;
                while(pred->right != NULL) pred = pred -> right;
                // Linking korbo aber
                pred -> right = r;
                curr = curr->left;
            }
            else curr = curr = curr -> right;
        }
        TreeNode* temp = root;
        while(temp->right != NULL){
            temp -> left = NULL;
            temp = temp -> right;
        }
    }
};