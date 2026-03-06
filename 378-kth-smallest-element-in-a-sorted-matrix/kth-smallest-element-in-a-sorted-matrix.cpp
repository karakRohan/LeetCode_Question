class Solution {
public:
    int kthSmallest(vector<vector<int>>& matrix, int k) {
        // Hint -> T.C = O(k²*logk)
        // Min Heap create (smallest element always on top)
        priority_queue<int, vector<int>, greater<int>> pq;
        int n = matrix.size();
        // Push all matrix elements into the min heap
        for(int i = 0; i < n; i++){
            for(int j = 0; j < n; j++){
                pq.push(matrix[i][j]);   // insert element into heap
            }
        }
        // Remove the smallest element k-1 times
        while(k > 1){
            pq.pop();   // remove smallest element
            k--;
        }
        // Now top element is the kth smallest
        return pq.top();
    }
};