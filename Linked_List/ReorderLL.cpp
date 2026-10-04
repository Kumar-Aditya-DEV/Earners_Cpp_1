class Solution {
public:
    ListNode* reverse(ListNode* head) { // O(1) space
        ListNode* curr = head;
        ListNode* prev = NULL;
        while(curr != NULL){
            ListNode* fwd = curr->next;
            curr->next = prev;
            prev = curr;
            curr = fwd;
        }
        return prev;
    }
    void reorderList(ListNode* head) {
        // reach the left middle (even) & reverse the second half
        ListNode* slow = head;
        ListNode* fast = head;
        while(fast->next != NULL and fast->next->next != NULL){
            slow = slow->next;
            fast = fast->next->next;
        }
        ListNode* a = head;
        ListNode* b = slow->next;
        slow->next = NULL;
        b = reverse(b);
        // Merge a and b alternatively
        ListNode* dummy = new ListNode(-1);
        ListNode* temp = dummy;
        ListNode* temp1 = a;
        ListNode* temp2 = b;
        while(temp1){ // while(t1 != NULL)
            temp->next = temp1;
            temp = temp->next;
            temp1 = temp1->next;

            temp->next = temp2;
            temp = temp->next;
            if(temp2) temp2 = temp2->next;
        }
        head = dummy->next;
    }
};
