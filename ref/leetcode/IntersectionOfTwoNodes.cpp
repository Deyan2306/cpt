#include <iostream>

struct ListNode {
    int val;
    ListNode * next;
    ListNode(int x) : val(x),  next(NULL) {}
};

class Solution {
public:

    ListNode * getIntersectionNode(ListNode * headA, ListNode * headB) {

        ListNode * first = headA;
        ListNode * second = headB;

        while (first != second) {
            first = !first ? headB : first->next;
            second = !second ? headA : second->next;
        }
        
        return first;
    }
};
