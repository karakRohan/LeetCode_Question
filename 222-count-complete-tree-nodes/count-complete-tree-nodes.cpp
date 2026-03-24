class Solution {
public:
    int countNodes(TreeNode* root) {
        if (!root) return 0;

        int lh = 0, rh = 0;
        TreeNode *l = root, *r = root;

        // left height
        while (l) {
            lh++;
            l = l->left;
        }

        // right height
        while (r) {
            rh++;
            r = r->right;
        }

        // if perfect tree
        if (lh == rh) return (1 << lh) - 1;

        // otherwise recurse
        return 1 + countNodes(root->left) + countNodes(root->right);
    }
};