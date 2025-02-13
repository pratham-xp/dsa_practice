class Solution {
public:
    bool isValid(string s) {
        stack<char> brackets;
        if(s.length() == 1) return false;
        for(int i = 0; i < s.length(); i++){
            if(s[i] == '(' || s[i] == '[' || s[i] == '{'){
                brackets.push(s[i]);
                continue;
            }
            if((!brackets.empty() && ((brackets.top() == '(' && s[i] != ')') || (brackets.top() == '[' && s[i] != ']') || (brackets.top() == '{' && s[i] != '}'))) || brackets.empty())
            return false;
            brackets.pop();
        }
        if(!brackets.empty()) return false;
        return true;
    }
};
