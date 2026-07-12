// Solution in Sorting
class Solution {
public:
    vector<int> arrayRankTransform(vector<int>& arr) {
        vector<int> temp = arr;
        sort(temp.begin(), temp.end());
        unordered_map<int, int> rank;
        int currRank = 1;
        for(int x : temp) {
            if (rank.find(x) == rank.end()) rank[x] = currRank++;
        }
        for(int &x : arr)x = rank[x];
        return arr;
    }
};