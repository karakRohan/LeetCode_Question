//Method - 2
class Solution {
public:
    TreeNode* iop (TreeNode* root) {// iop = InOrder predecessor
        TreeNode* pred = root->left;
        while(pred -> right != NULL){
            pred = pred->right;
        }
        return pred;
    }
    TreeNode* ios (TreeNode* root) {// s = InOrder successor
        TreeNode* suc = root->right;
        while(suc -> left != NULL){
            suc = suc->left;
        }
        return suc;
    }
    TreeNode* deleteNode(TreeNode* root, int key) {
        if(root == NULL) return NULL;
        // leaf node
        if(root -> val == key) {
            // Case 1 : No Child
            if(root->left == NULL && root->right==NULL) return NULL;

            // Case 2 : 1 Child node
            if(root->left == NULL || root->right==NULL){
                if(root->left != NULL) return root->left;
                else return root->right;
            }

            // Case 3 : 2 Child Nodes
            if(root->left != NULL || root->right !=NULL){
                // Replacd the root with its inorder pred = predecessor or suc = successor
                // After Replacing delete the pred/suc
                TreeNode* suc = ios(root);
                root -> val = suc->val;
                root->right = deleteNode(root->right, suc->val);
            }
        }
        else if(root->val > key){ // go left
            root->left = deleteNode(root->left, key);
        }
        else{ // root -> val < key : go right
            root->right = deleteNode(root->right, key);
        }
        return root;
    }
};