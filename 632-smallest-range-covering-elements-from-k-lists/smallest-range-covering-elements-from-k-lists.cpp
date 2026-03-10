class Solution {
public:
    typedef pair<int, pair<int,int>> pip; // pair of int pair
    vector<int> smallestRange(vector<vector<int>>& arr) {
        priority_queue<pip, vector<pip>, greater<pip>> pq;
        // pq element -> {arr[row][column],{row, column}}
        int mx = INT_MIN;
        for(int i=0;i<arr.size();i++){ // k times (array ka size k )
            mx = max(mx,arr[i][0]);
            pq.push({arr[i][0],{i,0}}); // O(k logk)
        }
        int mn = pq.top().first;
        int start = mn, end = mx;
        while(true){
            int row = pq.top().second.first;
            int col = pq.top().second.second;
            pq.pop();
            if(col == arr[row].size()-1) break;
            pq.push({arr[row] [col+1], {row,col+1}}); // O(nk logk)
            mx = max(mx,arr[row][col+1]); // mx = Maximum
            mn = pq.top().first; // mn = Minimum
            if(mx-mn < end-start){
                end = mx;
                start = mn;
            }
        }
        return {start, end};
    }
};