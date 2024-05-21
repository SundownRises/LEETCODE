class Solution {
public:
    int reverse(int x) {
    
    string str = to_string(x);

    bool isNegative = (x < 0);
    int start = isNegative ? 1 : 0;

    ::reverse(str.begin() + start, str.end());

    long long reversedNum = stoll(str);

    if (reversedNum > INT32_MAX || reversedNum < INT32_MIN) {
        return 0;
    }

    return reversedNum;
}
        

};