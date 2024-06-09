class Solution {
public:
    bool isPalindrome(string s) {
    string normalized;
    for (char c : s) {
        if (isalnum(c)) {
            normalized += tolower(c);
        }
    }
    
    int left = 0, right = normalized.size() - 1;
    while (left < right) {
        if (normalized[left] != normalized[right]) {
            return false;
        }
        left++;
        right--;
    }
    
    return true;
    }
};