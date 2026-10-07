class Solution {
  public:
    Node *reverse(Node *head) {
        Node* curr = head;
        Node* back = NULL;
        while(curr != NULL){
            Node* fwd = curr->next;
            curr->next = back;
            curr->prev = fwd; // extra
            back = curr;
            curr = fwd;
        }
        return back;
    }
};
