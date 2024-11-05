class Solution {
public:
bool isSelfDividing(int number) {
    int original = number;
    while (number > 0) {
        int digit = number % 10;
        if (digit == 0 || original % digit != 0) {
            return false;
        }
        number /= 10;
    }
    return true;
}
    vector<int> selfDividingNumbers(int left, int right) {
    vector<int> result;
    for (int num = left; num <= right; ++num) {
        if (isSelfDividing(num)) {
            result.push_back(num);
        }
    }
    return result;
    }
};