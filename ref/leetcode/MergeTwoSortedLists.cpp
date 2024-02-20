struct ListNode {
    int val;
    ListNode * next;
    ListNode() : val(0), next(nullptr) { }
    ListNode(int val_) : val(val_), next(nullptr) { }
    ListNode(int val_, ListNode * next_) : val(val_), next(next_) { }
};

class Solution {
public:
    ListNode * mergeTwoLists(ListNode* list1, ListNode* list2) {

        // cover edge cases
        if (!list1 || !list2)
            return list1 ? list1 : list2;
    
        ListNode *head, *temp;

        // choose the smaller head
        if (list1->val < list2->val) {
            temp = head = new ListNode(list1->val);
            list1 = list1->next;
        } else {
            temp = head = new ListNode(list2->val);
            list2 = list2->next;
        }

        // iterate to the end of the lists
        while (list1 != nullptr && list2 != nullptr) {
            if (list1->val < list2->val) {
                temp->next = new ListNode(list1->val);
                list1 = list1->next;
            } else {
                temp->next = new ListNode(list2->val);
                list2 = list2->next;
            }
            temp = temp->next;
        }

        // add the remainings
        while (list1 != nullptr) {
            temp->next = new ListNode(list1->val);
            list1 = list1->next;
            temp = temp->next;
        }
        while (list2 != nullptr) {
            temp->next = new ListNode(list2->val);
            list2 = list2->next;
            temp = temp->next;
        }
        return head;
    }
}; 
// dae brat, vze che mina
