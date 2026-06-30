class Solution {
public:
    bool isValid(string s) {
        stack<char> char_stack;

        for(auto c : s) {
            if(c == '[' || c == '(' || c == '{') char_stack.push(c);
            else if(char_stack.size() == 0) return false;
            else if(c == ']' && char_stack.top() == '[') char_stack.pop();
            else if(c == ')' && char_stack.top() == '(') char_stack.pop();
            else if(c == '}' && char_stack.top() == '{') char_stack.pop();
        }
        if(char_stack.size() == 0) return true;
        return false;

        
    }
};
