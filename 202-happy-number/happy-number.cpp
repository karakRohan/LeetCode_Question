class Solution {
public:
    int squareSum(int num){
        int sum = 0;
        while(num != 0){
            int digit = num % 10;
            sum += digit * digit;
            num = num / 10;
        }
        return sum;
    }
    bool isHappy(int n) {
        int fast = n, slow = n;
        while(true){
            fast = squareSum(squareSum(fast));
            slow = squareSum(slow);

            if(fast == 1) return true;
            if(fast == slow) return false;
        }
    }
};