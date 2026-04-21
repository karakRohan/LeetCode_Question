class Solution {
public:
    int minBitFlips(int start, int goal) {
        int ans=start^goal, counter =0; // gives the bit that need to be flip (^ ata Hoccha XOR Oparation )
        while(ans){
           ans&=(ans-1); // removing last bit of ans and storing it in ans,(rightmost 1)
           counter++;
        }
        return counter;
    }
};