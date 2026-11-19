class Solution {
public:
    int minimizeSum(vector<int>& arr) {
        int n=arr.size();
        sort(arr.begin(),arr.end());
        int x=arr[n-3]-arr[0];
        int y=arr[n-2]-arr[1];
        int z=arr[n-1]-arr[2];
        return min({x,y,z});
    }
};