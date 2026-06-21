class Solution {
public:
    int maxIceCream(vector<int>& costs, int coins) {
        sort(costs.begin(), costs.end());
        for(size_t i = 0; i < costs.size(); ++i) // size_t = unsigned integer type
            if((coins -= costs[i]) < 0)
                return i;
        return costs.size();
    }
};