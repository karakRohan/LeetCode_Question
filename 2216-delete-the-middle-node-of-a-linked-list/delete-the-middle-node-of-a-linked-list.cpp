class Solution {
public:
    ListNode* deleteMiddle(ListNode* head) {
        // If only one node, delete it
        if (head == NULL || head->next == NULL) return NULL;
        ListNode* slow = head;
        ListNode* fast = head;
        ListNode* prev = NULL;
        // Find middle node
        while (fast != NULL && fast->next != NULL) {
            prev = slow;
            slow = slow->next;
            fast = fast->next->next;
        }
        // Delete middle node
        prev->next = slow->next;
        return head;
    }
};
