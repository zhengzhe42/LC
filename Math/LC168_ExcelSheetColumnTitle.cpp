// my answer
class Solution {
public:
    string convertToTitle(int n) {
        string s = "";
        while(n>0){
			n--;
			s += 'A'+n%26;
			n /= 26;
		}
		reverse(s.begin(), s.end());
		return s;
    }
};


// simple answer
return n == 0 ? "" : convertToTitle(n / 26) + (char) (--n % 26 + 'A');

