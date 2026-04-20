class Solution {
public:
    int maxDistance(vector<int>& colors) 
    {
        int n=colors.size(),i=0,firstColor=colors[0]; //Three variables are initialized
        while (i<n && colors[i]==firstColor&&colors[i]==colors[n-1-i]) i++; //scan through the array
        return n-1-i; // Calculates the distance
    }
};