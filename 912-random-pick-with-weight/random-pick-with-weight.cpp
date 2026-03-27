#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    vector<int> prefix; // prefix sum array

    Solution(vector<int>& w) {
        int sum = 0;
        for(int x : w) {
            sum += x;
            prefix.push_back(sum); // prefix sum store
        }
    }
    
    int pickIndex() {
        int total = prefix.back();
        
        int r = rand() % total + 1; // random number (1 to total)
        
        // find first index where prefix >= r
        int index = lower_bound(prefix.begin(), prefix.end(), r) - prefix.begin();
        
        return index;
    }
};