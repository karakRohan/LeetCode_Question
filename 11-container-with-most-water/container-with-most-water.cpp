class Solution {
public:
    int maxArea(vector<int>& height) {
        int n = height.size(), maxArea = 0, i = 0, j = n-1;
        while(i<j) 
        {
            int length = j-i, width = min (height[i],height[j]), area = length*width;
            maxArea = max(maxArea,area);
            if(height[i]<=height[j]) i++;
            else j--;
        }
        return maxArea;
    }
};