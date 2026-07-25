class Solution {
public:
    int maxProduct(int n) {
        int max =0, smax =0, num =n;
        while (num>0) {
            int dig=num % 10;
            num =num / 10;
            if (dig >max) {
                smax =max;
                max = dig;
            } 
            else if (dig > smax) smax = dig;
        }
        return max * smax;
    }
};