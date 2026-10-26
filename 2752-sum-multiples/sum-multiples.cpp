class Solution {
public:
    int sumOfMultiples(int n) {
        int ans=0;
        // Traverse from 1 to n
        for (int i=1;i<=n;i++) {
            // Check divisibility by 3, 5, or 7
            if (i%3==0 || i%5==0 || i%7==0) ans+=i;
        }
        return ans;
    }
};