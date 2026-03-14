class Solution {
public:
    int numRescueBoats(vector<int>& people, int limit) {
        sort(people.begin(), people.end());
        int i = 0, j = people.size()-1;
        int bt = 0; // bt = Boat
        while(i <= j){
            if(people[i] + people[j] <= limit){
                bt ++; // allocate a boat to the pair
                i++;
                j--;
            }
            else{
                bt++; // allocate a boat to the Heaviest
                j--;
            }
        }
        return bt;
    }
};