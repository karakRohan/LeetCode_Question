class Solution {
public:
    bool threeFibonacciSum(int n) {
        int a=0,b=1,c=1;
        while(a+b+c<n){
            int n=b+c;
            a=b,b=c,c=n;
        }
        if(a+b+c==n) return true;
        return false;
    }
};