// my answer
class Solution {
public:
    int titleToNumber(string s) {
        int res=0, carry=1;
        for(int i=0; i<s.size(); i++){
        	char t = s[i];
        	res = res*26+t-'A'+1;
        	carry *= 26;
        }
        return res;
    }
};


// simple answer
int result = 0;
for (int i = 0; i < s.size(); result = result * 26 + (s.at(i) - 'A' + 1), i++);
return result;

