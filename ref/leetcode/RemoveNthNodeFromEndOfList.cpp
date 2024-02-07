#include <iostream>

struct ListNode {
    int val;
    ListNode * next;
    ListNode(int x) : val(x),  next(NULL) {}
};

class Solution {
public:

    ListNode* removeNthFromEnd(ListNode* head, int n) {

        ListNode * discoveryPointer = head;
        ListNode * mainPointer = head;

        while (n--) {
            discoveryPointer = discoveryPointer->next;
        }

        if (discoveryPointer == nullptr)
            return head->next;

        while (discoveryPointer->next) {
            discoveryPointer = discoveryPointer->next;
            mainPointer = mainPointer->next;
        }

        mainPointer->next = mainPointer->next->next;

        return head;
        
    }

};
