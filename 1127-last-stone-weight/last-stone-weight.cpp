class Solution {
public:
    int lastStoneWeight(vector<int>& arr) {
        priority_queue<int> pq;
        for(int ele : arr){ // O(nlogn)
            pq.push(ele);
        }
        while(pq.size()>1){   // O(nlogn)
            int x = pq.top();
            pq.pop();
            int y = pq.top();
            pq.pop();
            if(x != y) pq.push(x-y);
        }
        if(pq.size()==1) return pq.top();
        else return 0;
    }
};