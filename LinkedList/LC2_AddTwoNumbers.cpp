class Solution {
public:
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        ListNode res(0), *p = &res;                 //Initialize ListNode res(0)
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


class Solution {
public:
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        ListNode* head=NULL, p=NULL;
        int carry=0;
        while(l1 || l2){
            if(l1) carry += l1->val;
            if(l2) carry += l2->val;
            if(!head){
                head = new ListNode(carry%10);      //Initialize head = new ListNode(carry%10)
                p = head;
            }
            else{
                p->next = new ListNode(carry%10);
                p = p->next;
            }
            if(l1) l1 = l1->next;
            if(l2) l2 = l2->next;
            carry /= 10;
        }
        if(carry>0) p->next = new ListNode(carry);
        return head;
    }
};