class Solution {
public:
    vector<vector<int>> subsetsWithDup(vector<int>& nums) {
        sort(nums.begin(), nums.end()); // step 1

        vector<vector<int>> ans;
        ans.push_back({}); // empty subset

        int start = 0, end = 0;

        for (int i = 0; i < nums.size(); i++) {
            start = 0;

            // if duplicate, start from last added subsets
            if (i > 0 && nums[i] == nums[i-1]) {
                start = end + 1;
            }

            end = ans.size() - 1;

            int size = ans.size();
            for (int j = start; j < size; j++) {
                vector<int> temp = ans[j];
                temp.push_back(nums[i]);
                ans.push_back(temp);
            }
        }

        return ans;
    }
};