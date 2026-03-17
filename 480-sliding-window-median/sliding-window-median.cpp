class Solution {
public:
    vector<double> medianSlidingWindow(vector<int>& nums, int k) {
        multiset<int> l, r; // l = left , r = right
        // multiset = sorted + duplicate allowed
        vector<double> ans;

        for (int i = 0; i < nums.size(); i++) {

            // insert
            if (l.empty() || nums[i] <= *l.rbegin()) l.insert(nums[i]);
            else r.insert(nums[i]);

            // balance
            if (l.size() > r.size() + 1) {
                r.insert(*l.rbegin());
                l.erase(prev(l.end()));
            } 
            else if (r.size() > l.size()) {
                l.insert(*r.begin());
                r.erase(r.begin());
            }

            // remove
            if (i >= k) {
                if (nums[i-k] <= *l.rbegin())
                    l.erase(l.find(nums[i-k]));
                else
                    r.erase(r.find(nums[i-k]));

                // rebalance
                if (l.size() > r.size() + 1) {
                    r.insert(*l.rbegin());
                    l.erase(prev(l.end()));
                } 
                else if (r.size() > l.size()) {
                    l.insert(*r.begin());
                    r.erase(r.begin());
                }
            }

            // median
            if (i >= k-1) {
                if (k % 2) ans.push_back(*l.rbegin());
                else ans.push_back(((double)*l.rbegin() + *r.begin()) / 2);
            }
        }
        return ans;
    }
};