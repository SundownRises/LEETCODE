class Solution {
public:
    bool isPowerOfThree(int n) {
        if (n <= 0) return false;
        double logResult = log10(n) / log10(3);
        return (logResult - floor(logResult)) < 1e-10;
    }
};