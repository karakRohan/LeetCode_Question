class Solution {
public:
    int largestAltitude(vector<int>& gain) {
        int curr = 0, maxi = 0;
        for (int g : gain) {
            curr += g;
            maxi = max(maxi, curr);
        }
        return maxi;
    }
};