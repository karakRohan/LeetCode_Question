class Solution {
public:
    bool lemonadeChange(vector<int>& bills) {
        int five=0, ten=0; 
        for(int i=0; i<bills.size();i++){
            if(bills[i]==10){
                if(five==0) return false;
                else five--;
                ten++;
            }
            else if(bills[i]==20){
                if(ten>=1 && five>=1){
                    ten--;
                    five--;
                }
                else if( five>=3) five-=3;
                else return false;
            }
            else five++;
        }
        return true;
    }
};