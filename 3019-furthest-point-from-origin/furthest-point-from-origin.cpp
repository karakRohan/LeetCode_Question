class Solution {
public:
    int furthestDistanceFromOrigin(string moves) {
        int left = 0, right = 0, extra = 0;
        for(char move : moves){ // string ar protita character k ek ek kore loop korchi
            if(move == 'L') left++;
            else if(move == 'R') right++;
            else extra++; //na kichu hole extra count baracchi
        }
        return abs(left - right) + extra;
    }
};