class Solution {
public:
    int largestSumAfterKNegations(vector<int>& nums, int k) {
    sort(nums.begin(), nums.end());
    
    for (int i = 0; i < nums.size() && k > 0; ++i) {
        if (nums[i] < 0) {
            nums[i] = -nums[i];
            --k;
        }
    }
    
    if (k % 2 == 1) {
        int minElement = *min_element(nums.begin(), nums.end());
        for (int i = 0; i < nums.size(); ++i) {
            if (nums[i] == minElement) {
                nums[i] = -nums[i];
                break;
            }
        }
    }
    
    int sum = 0;
    for (int num : nums) {
        sum += num;
    }
    
    return sum;

    }
};