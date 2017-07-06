// my solution
class Solution {
public:
    TreeNode* buildTree(vector<int>& inorder, vector<int>& postorder) {
        unordered_map<int,int> map;
        for(int i=0; i<inorder.size(); i++) map[inorder[i]] = i;
        int i = postorder.size()-1;
        return help(postorder, i, 0, inorder.size()-1, map);
        }
    TreeNode* help(vector<int>& postorder, int& i, int l, int r, unordered_map<int,int>& map){
        if(l>r || i<0) return nullptr;
        int t = postorder[i--];
        TreeNode* node = new TreeNode(t);
        node->right = help(postorder, i, map[t]+1, r, map);
        node->left = help(postorder, i, l, map[t]-1, map);
        return node;
    }
};

// recursion
TreeNode *buildTree(vector<int> &inorder, vector<int> &postorder) {
    return create(inorder, postorder, 0, inorder.size() - 1, 0, postorder.size() - 1);
}

TreeNode* create(vector<int> &inorder, vector<int> &postorder, int is, int ie, int ps, int pe){
    if(ps > pe){
        return nullptr;
    }
    TreeNode* node = new TreeNode(postorder[pe]);
    int pos;
    for(int i = is; i <= ie; i++){
        if(inorder[i] == node->val){
            pos = i;
            break;
        }
    }
    node->left = create(inorder, postorder, is, pos - 1, ps, ps + pos - is - 1);
    node->right = create(inorder, postorder, pos + 1, ie, pe - ie + pos, pe - 1);
    return node;
}

// iteration
class Solution {
public:
    TreeNode *buildTree(vector<int> &inorder, vector<int> &postorder) {
        if(inorder.size() == 0)return NULL;
        TreeNode *p;
        TreeNode *root;
        stack<TreeNode *> stn;
        
        root = new TreeNode(postorder.back()); 
        stn.push(root); 
        postorder.pop_back(); 
        
        while(true)
        {
            if(inorder.back() == stn.top()->val) 
            {
                p = stn.top();
                stn.pop(); 
                inorder.pop_back(); 
                if(inorder.size() == 0) break;
                if(stn.size() && inorder.back() == stn.top()->val)
                    continue;
                p->left = new TreeNode(postorder.back()); 
                postorder.pop_back();
                stn.push(p->left);
            }
            else 
            {
                p = new TreeNode(postorder.back());
                postorder.pop_back();
                stn.top()->right = p; 
                stn.push(p); 
            }
        }
        return root;
    }
};


