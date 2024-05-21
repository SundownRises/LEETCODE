class Solution {
public:
    bool rob(const vector<int>& nums, int k, int cap) {
    int n = nums.size();
    int count = 0;
    
    for (int i = 0; i < n; ) {
        if (nums[i] <= cap) {
            count++;
            i += 2; 
        } else {
            i++;
        }
        if (count >= k) return true;
    }
    
    return count >= k;
}
    int minCapability(vector<int>& nums, int k) {
    int left = *min_element(nums.begin(), nums.end());
    int right = *max_element(nums.begin(), nums.end());
    int result = right;

    while (left <= right) {
        int mid = left + (right - left) / 2;
        if (rob(nums, k, mid)) {
            result = mid;
            right = mid - 1;
        } else {
            left = mid + 1;
        }
    }

    return result;
}

        
    
};