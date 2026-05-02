class Solution {
public:
    int helperFunction(int num){
        int gFlag = 0; // Eta check korche number ta valid rotated number kina
        while(num > 0){
            int l = num % 10;
            num /= 10;
            if(3 == l || 4 == l || 7 == l) return 0;
            else if(2 == l || 5 == l || 6 == l || 9 == l) gFlag = 1;
        }
        if(gFlag) return 1;
        else return 0;
    }
    int rotatedDigits(int n) {
        int ans = 0;
        while(n >= 1){
            if(helperFunction(n)) ans++;
            n--;
        }
        return ans;
    }
};