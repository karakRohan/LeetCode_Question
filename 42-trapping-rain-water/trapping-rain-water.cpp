class Solution {
public:
    int trap(vector<int>& height) {
        int n = height.size();
        if (n == 0)
            return 0;
        // Step - 1 Previous Greatest Element Array
        int prev[n];
        // int next[n];
        prev[0] = -1;
        int max = height[0];
        for (int i = 1; i < n; i++) {
            prev[i] = max;
            if (max < height[i])
                max = height[i];
        }

        // Step - 2 Next Greatest Element Array
        int next[n];
        next[n - 1] = +1;
        max = height[n - 1];
        for (int i = n - 2; i >= 0; i--) {
            next[i] = max;
            if (max < height[i])
                max = height[i];
        }

        // Step - 3 Minimum Array
        int mini[n];
        for (int i = 0; i < n; i++) {
            mini[i] = min(prev[i], next[i]);
        }

        // step - 4 Calculating Water
        int water = 0;
        for (int i = 1; i < n - 1; i++) {
            if (height[i] < mini[i]) {
                water += (mini[i] - height[i]);
            }
        }
        return water;
    }
};