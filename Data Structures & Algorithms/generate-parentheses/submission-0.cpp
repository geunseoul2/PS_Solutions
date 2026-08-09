class Solution {
public:
    vector<string> ans;

    vector<string> generateParenthesis(int n) {
        string curr;
        backtrack(curr,n,0,0);

        return ans;
    }

    void backtrack(string& curr, int n, int open, int close) {
        if(curr.size() == 2 * n) {
            if(open == close) ans.push_back(curr);
            return;
        }

        if(open < n) {
            curr.push_back('(');
            backtrack(curr,n,open+1,close);
            curr.pop_back();
        }
        if(close < open) {
            curr.push_back(')');
            backtrack(curr,n,open,close+1);
            curr.pop_back();
        }

        return;
    }
};

