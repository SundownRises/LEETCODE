class Solution {
public:
    int findNthDigit(int n) {
            long long length = 1, count = 9, start = 1;
    
    while (n > length * count) {
        n -= length * count;
        length++;
        count *= 10;
        start *= 10;
    }
    
    start += (n - 1) / length;
    string s = to_string(start);
    return s[(n - 1) % length] - '0';
}

int main() {
    int n1 = 3;
    cout << findNthDigit(n1) << endl;  

    int n2 = 11;
    cout << findNthDigit(n2) << endl;  

    return 0;
    }
};