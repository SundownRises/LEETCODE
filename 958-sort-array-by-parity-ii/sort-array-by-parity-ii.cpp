class Solution {
public:
    vector<int> sortArrayByParityII(vector<int>& nums) {
    int n = nums.size();
    int evenIndex = 0;
    int oddIndex = 1;
    vector<int> result(n);

    for (int i = 0; i < n; ++i) {
        if (nums[i] % 2 == 0) {
            result[evenIndex] = nums[i];
            evenIndex += 2;
        } else {
            result[oddIndex] = nums[i];
            oddIndex += 2;
        }
    }
    return result;
}
    
};