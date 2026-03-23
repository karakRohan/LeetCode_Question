class Solution {
public:
    int widthOfBinaryTree(TreeNode* root) {
        if (root == NULL) return 0;

        queue<pair<TreeNode*, long long>> q;
        q.push({root, 0});

        int maxWidth = 0;

        while (!q.empty()) {
            int n = q.size();

            long long firstIndex = q.front().second;
            long long first, last;

            for (int i = 0; i < n; i++) {
                auto current = q.front();
                q.pop();

                TreeNode* node = current.first;
                long long index = current.second - firstIndex; // normalize

                if (i == 0) first = index;
                if (i == n - 1) last = index;

                if (node->left) {
                    q.push({node->left, index * 2});
                }

                if (node->right) {
                    q.push({node->right, index * 2 + 1});
                }
            }

            int width = last - first + 1;
            maxWidth = max(maxWidth, width);
        }

        return maxWidth;
    }
};