struct compare{                                     // struct compare
    bool operator()(const ListNode* l, const ListNode* r){
        return l->val > r->val;
    }
};

class Solution {
public:
    ListNode* mergeKLists(vector<ListNode*>& lists) {   // priority_queue
        priority_queue<ListNode *, vector<ListNode *>, compare> q;
        for(auto l : lists) {
            if(l) q.push(l);
        }
        ListNode res(0);
        ListNode* p = &res;
        while(q.size()){
            p->next = q.top();
            q.pop();
            p = p->next;
            if(p->next) q.push(p->next);
        }
        return res.next;
    }
};


class Solution {
public:
    ListNode* mergeKLists(vector<ListNode*>& lists) {
        if(lists.empty()) return nullptr;
        while(lists.size()>1){
            lists.push_back(help(lists[0], lists[1]));
            lists.erase(lists.begin());                 // vector - lists.erase(lists.begin());
            lists.erase(lists.begin());
        }
        return lists.front();                           // lists.front()
    }
    ListNode* help(ListNode* a, ListNode* b){
        if(a==nullptr) return b;
        if(b==nullptr) return a;
        if(a->val <= b->val){
            a->next = help(a->next, b);
            return a;
        }
        else{
            b->next = help(a, b->next);
            return b;
        }
    }
};

