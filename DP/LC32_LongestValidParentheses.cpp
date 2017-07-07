// my solution Vector
class Solution {
public:
    int longestValidParentheses(string s) {
        vector<int> stack;
        int res = 0;
        for(int i=0; i<s.size(); i++){
            char c = s[i];
            if(stack.size()==0 || c=='(') stack.push_back(i);
            else{
                if(s[stack[stack.size()-1]]==')') stack.push_back(i);
                else{
                    stack.pop_back();
                    res = max(res, stack.empty() ? i+1 : i-stack[stack.size()-1]);
                }
            }
        }
        return res;
    }
};

// my solution Stack
class Solution {
public:
    int longestValidParentheses(string s) {
        int res = 0;
        stack<pair<char,int>> stack;
        for(int i=0; i<s.size(); i++){
            char c = s[i];
            pair<char,int> p (c,i);
            if(c=='(') stack.push(p);
            else{
                if(stack.empty()) stack.push(p);
                else{
                    if(stack.top().first=='('){
                        stack.pop();
                        res = max(res, stack.empty()?i+1 : i-stack.top().second);
                    }
                    else stack.push(p);
                }
            }
        }
        return res;
    }
};

// DP
int longestValidParentheses(string s) {
    if(s.length() <= 1) return 0;
    int curMax = 0;
    vector<int> longest(s.size(),0);
    for(int i=1; i < s.length(); i++){
        if(s[i] == ')'){
            if(s[i-1] == '('){
                longest[i] = (i-2) >= 0 ? (longest[i-2] + 2) : 2;
                curMax = max(longest[i],curMax);
            }
            else{ // if s[i-1] == ')', combine the previous length.
                if(i-longest[i-1]-1 >= 0 && s[i-longest[i-1]-1] == '('){
                    longest[i] = longest[i-1] + 2 + ((i-longest[i-1]-2 >= 0)?longest[i-longest[i-1]-2]:0);
                    curMax = max(longest[i],curMax);
                }
            }
        }
        //else if s[i] == '(', skip it, because longest[i] must be 0
    }
    return curMax;
}

// more concise
int longestValidParentheses(string s) {
        if(s.length() <= 1) return 0;
        int curMax = 0;
        vector<int> longest(s.size(),0);
        for(int i=1; i < s.length(); i++){
            if(s[i] == ')' && i-longest[i-1]-1 >= 0 && s[i-longest[i-1]-1] == '('){
                    longest[i] = longest[i-1] + 2 + ((i-longest[i-1]-2 >= 0)?longest[i-longest[i-1]-2]:0);
                    curMax = max(longest[i],curMax);
            }
        }
        return curMax;
    }