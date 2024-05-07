#include <iostream>
#include <stack>
// may the force be with you
using namespace std;

struct ListNode {
    int val;
    ListNode * next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int val_) : val(val_), next(nullptr) {}
    ListNode(int val_, ListNode * next_) : val(val_), next(next_) {}
};

class Solution {

    public:
        ListNode * doubleIt(ListNode * head) {

            if (head->next == nullptr) { 
                head->val *= 2; 
                return head; 
            }

            typedef ListNode* NODEPTR;
            stack<NODEPTR> stack;

            int carry = 0;
            
            NODEPTR tail = head;
            

            while(tail->next != nullptr) {
                NODEPTR curr = tail;   
                stack.push(curr);
                tail = tail->next;
            }
            stack.push(tail);

            NODEPTR curr;
            while (!stack.empty()) {
                curr = stack.top();
                int doubled = curr->val * 2 + carry;
                
                carry = doubled / 10;
                doubled = doubled % 10;
                curr->val = doubled;

                stack.pop();
            }

            if (carry != 0) {
                ListNode ne;
                ne.val = carry;
                ne.next = head;
                return &ne;
            }

            return curr;
        }
};


// given the `head` of a non-empty linked list
// no leading zeros
// not negative

// we should iterate it backwards

int main(void) {
    // brr
    return 0;
}
