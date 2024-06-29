class Solution {
public:
    bool isPerfectSquare(int num) {
    if (num <= 0) return false;
    if (num == 1) return true;

    int left = 1, right = num;
    while (left <= right) {
        int mid = left + (right - left) / 2;
        long long midSquared = (long long)mid * mid;
        if (midSquared == num) {
            return true;
        } else if (midSquared < num) {
            left = mid + 1;
        } else {
            right = mid - 1;
        }
    }
    return false;
    }
};