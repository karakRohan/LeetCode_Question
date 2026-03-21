// Method :- 1 (Recursive Solution )
class Solution {
public:
    vector<int>dp;
    int f(vector<int> arr, int i) {// f = Profit
        if(i == arr.size()-1) return arr[i]; // single house
        if(i == arr.size()-2) return max(arr[i], arr[i+1]); // 2 houses
        return max(arr[i] + f(arr, i+2), 0 + f(arr, i+1));
    }

    int ftd(vector<int> arr, int i) {// f = Profit
        if(i == arr.size()-1) return arr[i]; // single house
        if(i == arr.size()-2) return max(arr[i], arr[i+1]); // 2 houses

        if(dp[i] != -1) return dp[i]; // ith state already computed

        // if dp[i] was 1 so lets compute ith state for the first
        return dp[i] = max(arr[i] + ftd(arr, i+2), 0 + ftd(arr, i+1));
    }

    int rob(vector<int>& nums) {
        dp.clear();
        dp.resize(105,-1);
        return ftd(nums, 0);
    }
};