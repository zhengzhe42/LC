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

// make_heap
static bool heapComp(ListNode* a, ListNode* b) {
        return a->val > b->val;
}
ListNode* mergeKLists(vector<ListNode*>& lists) {   //make_heap
    ListNode head(0);
    ListNode *curNode = &head;
    vector<ListNode*> v;   
    for(int i =0; i<lists.size(); i++){
        if(lists[i]) v.push_back(lists[i]);
    }
    make_heap(v.begin(), v.end(), heapComp);        //vector -> heap data strcture

    while(v.size()>0){
        curNode->next=v.front();
        pop_heap(v.begin(), v.end(), heapComp);     //pop_heap
        v.pop_back(); 
        curNode = curNode->next;
        if(curNode->next) {
            v.push_back(curNode->next); 
            push_heap(v.begin(), v.end(), heapComp); //push_heap
        }
    }
    return head.next;
}


// Recursion
ListNode *mergeKLists(vector<ListNode *> &lists) {
    if(lists.empty()){
        return nullptr;
    }
    while(lists.size() > 1){
        lists.push_back(mergeTwoLists(lists[0], lists[1]));
        lists.erase(lists.begin());
        lists.erase(lists.begin());
    }
    return lists.front();
}
ListNode *mergeTwoLists(ListNode *l1, ListNode *l2) {
    if(l1 == nullptr){
        return l2;
    }
    if(l2 == nullptr){
        return l1;
    }
    if(l1->val <= l2->val){
        l1->next = mergeTwoLists(l1->next, l2);
        return l1;
    }
    else{
        l2->next = mergeTwoLists(l1, l2->next);
        return l2;
    }
}


ListNode* mergeKLists(vector<ListNode*>& lists) {
    int k = (int)lists.size();
    if(k==0) return NULL;
    if(k==1) return lists[0];
    return doMerge(lists, 0, (int)lists.size()-1);
}


ListNode* doMerge(vector<ListNode*>& lists, int left, int right) {
    if(left==right) return lists[left];
    else if(left+1==right) return merge2Lists(lists[left], lists[right]);
    ListNode* l1 = doMerge(lists, left, (left+right)/2);
    ListNode* l2 = doMerge(lists, (left+right)/2+1, right);
    return merge2Lists(l1, l2);
}


ListNode* merge2Lists(ListNode* l1, ListNode* l2) {
    if(l1==l2) return l1;
    if(!l1) return l2;
    if(!l2) return l1;
    if(l1->val>l2->val) return merge2Lists(l2, l1);
    ListNode* newl2 = new ListNode(0); newl2->next = l2;
    ListNode* p1 = l1;
    while (p1->next && newl2->next) {
        if (p1->next->val<newl2->next->val) {
            p1 = p1->next;
        } else {
            ListNode* temp = p1->next;
            p1->next = newl2->next;
            newl2->next = newl2->next->next;
            p1->next->next = temp;
            p1 = p1->next;
        }
    }
    if(!p1->next) p1->next = newl2->next;
    delete newl2;
    return l1;
}

