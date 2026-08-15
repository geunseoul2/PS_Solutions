class Solution {
public:
    vector<vector<string>> ans;
    vector<vector<string>> partition(string s) {
        vector<string> curr;
        backtrack(s,curr,0);

        return ans;
    }

    void backtrack(string s, vector<string> curr, int idx) { 
        if(s.size() == idx) ans.push_back(curr);

        for(int i=idx; i<s.size(); i++) { 
            string sub = s.substr(idx, i-idx+1); 
            if(isPalindrome(sub)) {
                curr.push_back(sub);
                backtrack(s,curr,i+1);
                curr.pop_back();
            }
        }
    }

    bool isPalindrome(string s) {
        int left = 0;
        int right = s.size()-1;

        while(right >= left) {
            if(s[left] != s[right]) return false;
            left++;
            right--;
        }

        return true;
    }
};
