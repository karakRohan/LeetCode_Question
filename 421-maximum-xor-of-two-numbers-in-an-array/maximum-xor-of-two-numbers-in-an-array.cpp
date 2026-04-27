class Node {
    public:
        Node* left;
        Node* right;
        Node(){
            this->left = this->right = NULL;
        }
};

class Solution {
public:
    // compares incoming value with existing inserted data in trie
    int maxXorPair(Node* head, int value) {
        int curr_xor = 0;
        Node* curr = head;

        for(int i = 31; i >= 0; i--) {
            int bit = (value >> i) & 1;

            if(bit == 0) {
                if(curr->right != NULL) {
                    curr = curr->right;
                    curr_xor += (1 << i);
                } else {
                    curr = curr->left;
                }
            } else {
                if(curr->left != NULL) {
                    curr = curr->left;
                    curr_xor += (1 << i);
                } else {
                    curr = curr->right;
                }
            }
        }
        return curr_xor;
    }

    void insert(Node* head, int value) {
        Node* curr = head;

        for(int i = 31; i >= 0; i--) {
            int bit = (value >> i) & 1;

            if(bit == 0) {
                if(curr->left == NULL) {
                    curr->left = new Node();
                }
                curr = curr->left;
            } else {
                if(curr->right == NULL) {
                    curr->right = new Node();
                }
                curr = curr->right;
            }
        }
    }
    int findMaximumXOR(vector<int>& nums) {
        Node* head = new Node();

        insert(head, nums[0]);

        int ans =0;

        for(int i = 1; i < nums.size(); i++) {
            int res = maxXorPair(head, nums[i]);
            //cout<<res<<"\n";
            ans = max(ans, res);
            insert(head, nums[i]);
        }

        return ans;
    }
};