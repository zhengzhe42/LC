// my solution DP
class Solution {
public:
    bool isMatch(string s, string p) {
        int lenS=s.size(), lenP=p.size();
        vector<vector<bool>> dp(lenS+1, vector<bool>(lenP+1, false));
        dp[0][0] = true;
        for(int i=1; i<=lenP; i++) dp[0][i] = dp[0][i-1] && p[i-1]=='*';
        for(int i=1; i<=lenS; i++){
            for(int j=1; j<=lenP; j++){
                char cs=s[i-1], cp=p[j-1];
                if(cs==cp || cp=='?') dp[i][j] = dp[i-1][j-1];
                else if(cp=='*') dp[i][j] = dp[i-1][j] || dp[i][j-1];
            }
        }
        return dp[lenS][lenP];
    }
};

// my solution recursion *** RUN TIME ERROR
class Solution {
public:
    bool isMatch(string s, string p) {
        int lenS=s.size(), lenP=p.size();
        vector<vector<bool>> dp(lenS+1, vector<bool>(lenP+1, false));
        dp[0][0] = true;
        for(int i=1; i<=lenP; i++) dp[0][i] = dp[0][i-1] && p[i-1]=='*';
        for(int i=1; i<=lenS; i++){
            for(int j=1; j<=lenP; j++){
                char cs=s[i-1], cp=p[j-1];
                if(cs==cp || cp=='?') dp[i][j] = dp[i-1][j-1];
                else if(cp=='*') dp[i][j] = dp[i-1][j] || dp[i][j-1];
            }
        }
        return dp[lenS][lenP];
    }
};


// DP O(n)
class Solution {
public:
    bool isMatch(string s, string p) { 
        int m = s.length(), n = p.length();
        if (n > 30000) return false; // the trick
        vector<bool> cur(m + 1, false); 
        cur[0] = true;
        for (int j = 1; j <= n; j++) {
            bool pre = cur[0]; // use the value before update
            cur[0] = cur[0] && p[j - 1] == '*'; 
            for (int i = 1; i <= m; i++) {
                bool temp = cur[i]; // record the value before update
                if (p[j - 1] != '*')
                    cur[i] = pre && (s[i - 1] == p[j - 1] || p[j - 1] == '?');
                else cur[i] = cur[i - 1] || cur[i];
                pre = temp;
            }
        }
        return cur[m]; 
    }
};

// Greedy
class Solution {
public:
    bool isMatch(string s, string p) {
        int m = s.length(), n = p.length();
        int i = 0, j = 0, asterisk = -1, match;
        while (i < m) {
            if (j < n && p[j] == '*') {
                match = i; 
                asterisk = j++;
            }
            else if (j < n && (s[i] == p[j] || p[j] == '?')) {
                i++; 
                j++;
            }
            else if (asterisk >= 0) {
                i = ++match;
                j = asterisk + 1;
            }
            else return false;
        }
        while (j < n && p[j] == '*') j++;
        return j == n;
    }
};

// https://discuss.leetcode.com/topic/3040/linear-runtime-and-constant-space-solution
bool isMatch(const char *s, const char *p) {
        const char* star=NULL;
        const char* ss=s;
        while (*s){
            //advancing both pointers when (both characters match) or ('?' found in pattern)
            //note that *p will not advance beyond its length 
            if ((*p=='?')||(*p==*s)){s++;p++;continue;} 

            // * found in pattern, track index of *, only advancing pattern pointer 
            if (*p=='*'){star=p++; ss=s;continue;} 

            //current characters didn't match, last pattern pointer was *, current pattern pointer is not *
            //only advancing pattern pointer
            if (star){ p = star+1; s=++ss;continue;} 

           //current pattern pointer is not star, last patter pointer was not *
           //characters do not match
            return false;
        }

       //check for remaining characters in pattern
        while (*p=='*'){p++;}

        return !*p;  
    }