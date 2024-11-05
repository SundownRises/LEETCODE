class Solution {
public:
bool isPrime(int num) {
    if (num < 2) return false;
    for (int i = 2; i * i <= num; ++i) {
        if (num % i == 0) return false;
    }
    return true;
}
    int countPrimeSetBits(int left, int right) {
            int count = 0;
    for (int i = left; i <= right; ++i) {
        int setBits = bitset<32>(i).count();
        if (isPrime(setBits)) {
            ++count;
        }
    }
    return count;
    }
};