class Solution {
public:
    int guessNumber(int n) {
        int l = 1, h = n, mid;
        // l= left(Start Index), h = High (Last Index) , mid = Middle number
        while(l <= h) {
            mid = l + (h - l) / 2; // Find the Middle Number
            if(guess(mid) == 0)break;
            else if(guess(mid) == -1) h = mid - 1;
            else l = mid + 1;
        }
        return mid;
    }
};