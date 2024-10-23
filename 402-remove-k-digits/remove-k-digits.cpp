class Solution {
public:
    string removeKdigits(string num, int k) {
            string result;
    
    for (char digit : num) {
        while (!result.empty() && result.back() > digit && k > 0) {
            result.pop_back(); 
            k--; 
        }
        result.push_back(digit); 
    }
    
    while (k > 0 && !result.empty()) {
        result.pop_back();
        k--;
    }
    
    int start = 0;
    while (start < result.size() && result[start] == '0') {
        start++;
    }
    
    if (start == result.size()) {
        return "0";
    }
    
    return result.substr(start);
    }
};