class Solution {
public:
    bool isPalindrome(string &s, int p, int r){
    	for (int i = p, j = r; i <= j; ++i, --j){
    		if (s[i] != s[j]){
    			return false;
    		}
    	}
    	return true;
    }
    
    void palindromeSubStr(string &s, int p, int r, 
    					  vector<string> &vs, 
    					  vector<vector<string>> &vvs){
    	if (p > r){
    		vvs.push_back(vs);
    		return ;
    	}
    	for (int i = p; i <= r; ++i){
    		if (isPalindrome(s, p, i)){
    			vs.push_back(s.substr(p, i - p + 1));
    			palindromeSubStr(s, i + 1, r, vs, vvs);
    			vs.pop_back();
    		}
    	}
    
    }
    
    vector<vector<string>> partition(string s) {
    	vector<string> vs;
    	vector<vector<string>> vvs;
    	palindromeSubStr(s, 0, s.size() - 1, vs, vvs);
    	
    	return vvs;
    }

};