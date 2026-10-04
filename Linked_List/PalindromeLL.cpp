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
    bool isPalindrome(ListNode* head) {
        // reach the left middle (even)
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
        ListNode* t1 = a;
        ListNode* t2 = b;
        bool flag = true;
        while(t2 != NULL){
            if(t1->val != t2->val){
                flag = false;
                break;
            } 
            t1 = t1->next;
            t2 = t2->next;
        }
        slow->next = reverse(b); // to maintain the original LL
        return flag;
    }
};
