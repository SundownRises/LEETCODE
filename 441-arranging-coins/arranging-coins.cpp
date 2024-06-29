class Solution {
public:
    int arrangeCoins(int n) {
    if (n == 0) return 0;
    
    long left = 0, right = n;
    while (left <= right) {
        long mid = left + (right - left) / 2;
        long current = mid * (mid + 1) / 2;
        if (current == n) return mid;
        if (current < n) {
            left = mid + 1;
        } else {
            right = mid - 1;
        }
    }
    return right;
    }
};