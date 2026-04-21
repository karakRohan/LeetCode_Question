class Solution {
public:
    int minBitFlips(int start, int goal) {
        int ans=start^goal; // gives the bit that need to be flip (^ ata Hoccha XOR Oparation )
        int counter =0;

        while(ans){
           ans&=(ans-1); // removing last bit of ans and storing it in ans;
           counter++;
        }
        return counter;
    }
};