class Solution {
public:
    vector<int> maxSlidingWindow(vector<int>& arr, int k) {
        if (k == 1)
            return arr;
        int n = arr.size();
        int ngi[n]; // ngi = Next Grater Index
        stack<int> stack1;
        ngi[n - 1] = n;
        stack1.push(n - 1);
        for (int i = n - 1; i >= 0; i--) {
            // POP all the elements smaller than or equal to arr[i]
            while (stack1.size() > 0 && arr[stack1.top()] <= arr[i]) {
                stack1.pop();
            }

            // ANS [Mark the ANS is nge array]
            if (stack1.size() == 0)
                ngi[i] = n;
            else
                ngi[i] = stack1.top();

            // PUSH the arr[i] into the stack
            stack1.push(i);
        }
        vector<int> ans;
        int j = 0;
        for (int i = 0; i < n - k + 1; i++) {
            if (j < i)
                j = i;
            int mx = arr[j];    // Starting Of Window Se
            while (j < i + k) { // means if nge is inside window
                mx = arr[j];
                if (ngi[j] >= i + k)
                    break;
                j = ngi[j];
            }
            ans.push_back(mx);
        }
        return ans;
    }
};