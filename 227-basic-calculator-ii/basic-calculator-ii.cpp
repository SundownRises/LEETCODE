class Solution {
public:
    int calculate(string s) {
    stack<int> stk;
    int currentNum = 0;
    char sign = '+';
    
    for (int i = 0; i < s.length(); i++) {
        char ch = s[i];
        
        if (isdigit(ch)) {
            currentNum = currentNum * 10 + (ch - '0');
        }
        
        if (!isdigit(ch) && ch != ' ' || i == s.length() - 1) {
            if (sign == '+') {
                stk.push(currentNum);
            } else if (sign == '-') {
                stk.push(-currentNum);
            } else if (sign == '*') {
                int top = stk.top();
                stk.pop();
                stk.push(top * currentNum);
            } else if (sign == '/') {
                int top = stk.top();
                stk.pop();
                stk.push(top / currentNum);
            }
            sign = ch;
            currentNum = 0;
        }
    }
    
    int result = 0;
    while (!stk.empty()) {
        result += stk.top();
        stk.pop();
    }
    
    return result;
    }
};