
// my solution
class Solution {
public:
    ListNode* swapPairs(ListNode* head) {
        if(head==NULL || head->next==NULL) return head;
        ListNode *next = swapPairs(head->next->next);
        ListNode *newHead = head->next;
        newHead->next = head;
        head->next = next;
        return newHead;
    }
};

// using Pointer instead of recursion
class Solution {
public:
    ListNode* swapPairs(ListNode* head) {
        ListNode **pp = &head, *a, *b;
        while ((a = *pp) && (b = a->next)) {
            a->next = b->next;
            b->next = a;
            *pp = b;
            pp = &(a->next);
        }
        return head;
    }
};

// same as my solution but simpler
class Solution {
public:
    ListNode* swapPairs(ListNode* head) {
        if(head == NULL)
            return NULL;
        if(head->next == NULL)
            return head;
        
        ListNode* next = head->next;
        head->next = swapPairs(next->next);
        next->next = head;
        
        return next;
    }
};


// iteratively
ListNode *swapPairs(ListNode *head) {
    ListNode *dummy = new ListNode(0), *node;
    node = dummy;
    dummy->next = head;
    while (head && head->next) {
        ListNode *nxt = head->next;
        head->next = nxt->next;
        nxt->next = head;
        node->next = nxt;
        node = head;
        head = node->next;
    }
    return dummy->next;
}

