class Solution {
public:
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        ListNode res(0), *p = &res;
        int carry = 0;
        while(l1 || l2 || carry){
            carry += (l1 ? l1->val : 0) + (l2 ? l2->val : 0);
            p -> next = new ListNode(carry % 10);
            carry = carry/10;
            p = p->next;
            l1 = l1 ? l1->next : l1;
            l2 = l2 ? l2->next : l2;
        }
        return res.next;
    }
};