//Tried different way to do
class Solution {
public:
    int minCut(string s) {
        int len = s.size();
        if(len<2) return 0;
        vector<vector<bool>> dp(len, vector<bool>(len, false));
        vector<int> cuts(len, 0);
        for(int i=0; i<len; i++){
        	cuts[i] = i;
        	for(int j=0; j<=i; j++){
        		if(s[i]==s[j] && (i-j<2 || dp[i-1][j+1])){
        			dp[i][j] = true;
        			if(j==0) cuts[i] = 0;
        			else cuts[i] = min(cuts[i], cuts[j-1]+1);
        		}
        	}
        }
        return cuts[len-1];
    }
};




// Java
public class Solution {
    public int minCut(String s) {
        if(s==null || s.length()==0) return 0;
        int len = s.length();
        boolean[][] dp = new boolean[len][len];					// make bool dp[len][len] and initialize all false
        int[] cut = new int[len];								// make cut array
        for(int j=0; j<len; j++){								// check 0...j minimum cuts
            char cj = s.charAt(j);								// get jth character
            cut[j] = j;											// initialize cut size as mix j
            for(int i=0; i<=j; i++){							// check 0...j char
                char ci = s.charAt(i);							// get ith char
                if(cj==ci && (j-i<=1 || dp[i+1][j-1])){			// jth char and ith char are same AND 
                    dp[i][j] = true;
                    if(i==0) cut[j] = 0;
                    else cut[j] = Math.min(cut[j], cut[i-1]+1);
                }
            }
        }
        return cut[len-1];
    }
}