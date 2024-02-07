struct ListNode {
    int val;
    ListNode * next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int val_) : val(val_), next(nullptr) {}
    ListNode(int val_, ListNode * next_) : val(val_), next(next_) {}
};

class Solution {
public:
    ListNode * reverseList(ListNode* head) {
        
        ListNode * current = head;
        ListNode * next = nullptr;
        ListNode * prev = nullptr;

        while (current != nullptr) {
            next = current->next;
            current->next = prev;
            prev = current;
            current = next;
        }

        head = prev;

        return head;
    }
};
