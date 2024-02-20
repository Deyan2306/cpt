// with the doubly linked list we have two nodes instead of one
struct DoublyLinkedNode {
    int val;
    DoublyLinkedNode * next, * prev;
    DoublyLinkedNode(int val_) : val(val_), next(nullptr), prev(nullptr) {}
};

// =================================================================================================
// Addition and Deletion are kindof more complicated, as you should take care of more stuff on the way.
// Nvtl, the iterating is the same - always O(n)

// Addition - Just relink the prev and next nodes, that's the easy part
// Deletion - Same shit, different day

// the prev field makes everything faster, as it gives us access to the element before, so we do not have to iterate the list twice

// Here is a custom implementation of my doubly linked list, jfp
// =================================================================================================

struct ListNode {
    int val;
    ListNode *next, *prev;
    ListNode() : val(0), next(nullptr), prev(nullptr) {}
    ListNode(int val_) : val(val_), next(nullptr), prev(nullptr) {}
    ListNode(int val_, ListNode * next_) : val(val_), next(next_), prev(nullptr) {}
    ListNode(int val_, ListNode * next_, ListNode * prev_) : val(val_), next(next_), prev(prev_) {}
};

// this code is a sin :d
class MyLinkedList {
private:
    ListNode * dummy = new ListNode();
    int cnt = 0; 

public:
    MyLinkedList() { }
    
    int get(int index) {
        if (index < 0 || index >= cnt) { return -1; }
        auto cur = dummy->next;
        while(index--) { cur = cur->next; }
        return cur->val;
    }
    
    void addAtHead(int val) {
        addAtIndex(0, val);
    }
    
    void addAtTail(int val) {
        addAtIndex(cnt, val);
    }
    
    void addAtIndex(int index, int val) {
        if (index > cnt) { return; }
        auto pre = dummy;
        while (index-- > 0) { pre = pre->next; }
        pre->next = new ListNode(val, pre->next);
        ++cnt;
    }
    
    void deleteAtIndex(int index) {
        if (index >= cnt) { return; }
        auto pre = dummy;
        while (index-- > 0) { pre = pre->next; }
        auto t = pre->next;
        pre->next = t->next;
        t->next = nullptr;
        --cnt;
    }
};
