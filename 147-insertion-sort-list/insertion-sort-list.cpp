class Solution {
public:
    ListNode* insertionSortList(ListNode* head) {
        vector<int>v;
        while(head!=NULL){
         v.push_back(head->val);
         head=head->next;
        }
        sort(v.begin(),v.end());
        ListNode* temp=new ListNode(0);
        ListNode* temp1=NULL;
        for(int i=v.size()-1;i>=0;i--){
            temp=new ListNode(v[i]);
            temp->next=temp1;
            temp1=temp;
        }
        return temp1;
    }
};