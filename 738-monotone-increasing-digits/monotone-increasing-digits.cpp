class Solution {
public:
    int monotoneIncreasingDigits(int n) {
        string str = to_string(n); 
        int length = str.size();
        int mark = length; 
        
        for (int i = length - 1; i > 0; --i) {
            if (str[i - 1] > str[i]) {
                str[i - 1]--;
                mark = i;
            }
        }
        
        for (int i = mark; i < length; ++i) {
            str[i] = '9';
        }
        
        return stoi(str);
    
    }
};