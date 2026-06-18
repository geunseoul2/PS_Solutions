class Solution {
public:
    int evalRPN(vector<string>& tokens) {
        stack<int> stk;

        for(auto c : tokens) {
            if(c == "+") {
                int second = stk.top();
                stk.pop();
                int ans = second + stk.top();
                stk.pop();
                stk.push(ans);
            } else if(c == "-") {
                int second = stk.top();
                stk.pop();
                int ans = stk.top() - second;
                stk.pop();
                stk.push(ans);
            } else if(c == "*") {
                int second = stk.top();
                stk.pop();
                int ans = second * stk.top();
                stk.pop();
                stk.push(ans);
            } else if(c == "/") {
                int second = stk.top();
                stk.pop();
                int ans = stk.top() / second;
                stk.pop();
                stk.push(ans);
            } else {
                stk.push(stoi(c));
            }
        }

        return stk.top();
    }
};
