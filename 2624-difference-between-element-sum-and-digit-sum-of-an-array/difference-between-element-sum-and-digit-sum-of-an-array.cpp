class Solution {
public:
    int differenceOfSum(vector<int>& nums) {
        int elementSum = 0,digitSum = 0;
        for(int i : nums){
            elementSum += i;
            while( 0 < i){
                digitSum += i%10;
                i /= 10;
            }
        }
        return abs(elementSum - digitSum);
    }
};