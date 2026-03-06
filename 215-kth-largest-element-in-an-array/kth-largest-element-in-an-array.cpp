// Method - 2 Using Quick Select Algo
class Solution {
public:
    int findKthLargest(vector<int>& nums, int k) {
        priority_queue<int, vector<int>, greater<int>> pq;

        pq.push(nums[0]);
        int i = 1;

        while (pq.size() < k) {
            pq.push(nums[i]);
            i++;
        }

        while (i < nums.size()) {
            int t = pq.top();
            if (nums[i] > t) {
                pq.pop();
                pq.push(nums[i]);
            }
            i++;
        }

        return pq.top();
    }
};