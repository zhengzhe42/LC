// Important way to solve
class Solution {
public:
    ListNode* removeNthFromEnd(ListNode* head, int n) {
        ListNode** t=&head; ListNode* p = head;
        while(n>1&&p!=NULL){
            p = p->next;
            n--;
        }
        while(p->next!=NULL){
            p = p->next;
            t = &((*t)->next);
        }
        *t = (*t)->next;
        return head;
    }
};


ListNode *removeNthFromEnd(ListNode *head, int n) 
{
    if (!head)
        return nullptr;							//nullptr

    ListNode new_head(-1);
    new_head.next = head;

    ListNode *slow = &new_head, *fast = &new_head;

    for (int i = 0; i < n; i++)
        fast = fast->next;

    while (fast->next) 
    {
        fast = fast->next;
        slow = slow->next;
    }

    ListNode *to_de_deleted = slow->next;
    slow->next = slow->next->next;
    
    delete to_be_deleted;						//interesting delete function

    return new_head.next;
}

class Solution {
public:
    ListNode* removeNthFromEnd(ListNode* head, int n) {
        ListNode* dummy = new ListNode(0);
        dummy->next = head;
        ListNode* end=dummy, *begin=dummy;
        while(n>0){
        	if(!end) return head;
        	end = end->next;
        	n--;
        }
        while(end->next){
        	end = end->next;
        	begin = begin->next;
        }
        begin->next = begin->next->next;
        return dummy->next;
    }
};

