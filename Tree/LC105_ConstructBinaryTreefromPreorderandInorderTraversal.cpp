// my solution
class Solution {
public:
    TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {
        unordered_map<int, int> map;
        for(int i=0; i<inorder.size(); i++) map[inorder[i]] = i;
        int i=0;
        return help(preorder, i, 0, inorder.size()-1, map);
        }
    TreeNode* help(vector<int>& preorder, int& i, int l, int r, unordered_map<int, int>& map){
        if(l>r || i>=preorder.size()) return nullptr;
        int t = preorder[i++];
        TreeNode* root = new TreeNode(t);
        root->left = help(preorder, i, l, map[t]-1, map);
        root->right = help(preorder, i, map[t]+1, r, map);
        return root;
    }
};

// recursion
TreeNode *buildTree(vector<int> &preorder, vector<int> &inorder) {
    return create(preorder, inorder, 0, preorder.size() - 1, 0, inorder.size() - 1);
}

TreeNode* create(vector<int>& preorder, vector<int>& inorder, int ps, int pe, int is, int ie){
    if(ps > pe){
        return nullptr;
    }
    TreeNode* node = new TreeNode(preorder[ps]);
    int pos;
    for(int i = is; i <= ie; i++){
        if(inorder[i] == node->val){
            pos = i;
            break;
        }
    }
    node->left = create(preorder, inorder, ps + 1, ps + pos - is, is, pos - 1);		// pay attention
    node->right = create(preorder, inorder, pe - ie + pos + 1, pe, pos + 1, ie);	// pay attention
    return node;
}

// iteration
class Solution {
public:
    TreeNode *buildTree(vector<int> &preorder, vector<int> &inorder) {
        
        if(preorder.size()==0)
            return NULL;
        
        stack<int> s;
        stack<TreeNode *> st;
        TreeNode *t,*r,*root;
        int i,j,f;
        
        f=i=j=0;
        s.push(preorder[i]);
        
        root = new TreeNode(preorder[i]);
        st.push(root);
        t = root;
        i++;
        
        while(i<preorder.size()){
            if(!st.empty() && st.top()->val==inorder[j]){
                t = st.top();
                st.pop();
                s.pop();
                f = 1;
                j++;
            }
            else{
                if(f==0){
                    s.push(preorder[i]);
                    t -> left = new TreeNode(preorder[i]);
                    t = t -> left;
                    st.push(t);
                    i++;
                }
                else{
                    f = 0;
                    s.push(preorder[i]);
                    t -> right = new TreeNode(preorder[i]);
                    t = t -> right;
                    st.push(t);
                    i++;
                }
            }
        }
        
        return root;
    }
};