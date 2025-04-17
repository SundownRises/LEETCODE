class Solution {
public:
    bool isNumber(string s) {
        int i = 0, n = s.size();
        bool hasNum = false, hasDot = false, hasExp = false;

        while (i < n && s[i] == ' ') ++i;
        if (i < n && (s[i] == '+' || s[i] == '-')) ++i;

        while (i < n) {
            if (isdigit(s[i])) {
                hasNum = true;
            } else if (s[i] == '.') {
                if (hasDot || hasExp) return false;
                hasDot = true;
            } else if (s[i] == 'e' || s[i] == 'E') {
                if (hasExp || !hasNum) return false;
                hasExp = true;
                hasNum = false;
                if (i + 1 < n && (s[i + 1] == '+' || s[i + 1] == '-')) ++i;
            } else if (s[i] == ' ') {
                while (i < n && s[i] == ' ') ++i;
                return i == n && hasNum;
            } else {
                return false;
            }
            ++i;
        }
        return hasNum;
    }
};