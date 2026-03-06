// Method :- 2 (Using Priority Queue [Heap] & solution in MinHeap)
class Solution {
public:
    int findKthLargest(vector<int>& arr, int k) {
        priority_queue<int, vector<int>, greater<int>> pq; // MinHeap
        for(int i=0; i<arr.size(); i++){
            pq.push(arr[i]);
            if(pq.size() > k) pq.pop();
        }
        return pq.top();
    }
};