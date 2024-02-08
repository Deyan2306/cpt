struct ListNode {
    int val;
    ListNode * next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode * next_) : val(x), next(next_) {} 
};


// Time complexity:     O(N)
// Space complexity:    O(1)
class Solution {
public:
    ListNode * removeElements(ListNode* head, int val) {
        ListNode dummy(0, head);
        ListNode * prev = &dummy;

        for ( ; head ; head = head->next ) {
            if (head->val != val) {
                prev->next = head;
                prev = prev->next;
            }
        }

        prev->next = nullptr;
        return dummy.next;
    }
};
