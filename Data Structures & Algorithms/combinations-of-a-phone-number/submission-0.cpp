class Solution {
public:
    vector<string> iToc = {"", "", "abc", "def", "ghi", "jkl","mno", "qprs", "tuv", "wxyz"};
    vector<string> ans;

    vector<string> letterCombinations(string digits) {
        if (digits.empty()) return ans;
        backtrack(digits,"",0);

        return ans;
    }

    void backtrack(string& digits, string curr, int i) {
        if(curr.size() == digits.size()) {
            ans.push_back(curr);
            return;
        }
        string chars = iToc[digits[i] - '0'];

        for(auto c : chars) {
            curr.push_back(c);
            backtrack(digits, curr, i+1);
            curr.pop_back();
        }

        return;
    }

};
