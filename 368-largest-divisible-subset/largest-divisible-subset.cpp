class Solution {
public:
    vector<int> largestDivisibleSubset(vector<int>& nums) {
    sort(nums.begin(), nums.end());

    int n = nums.size();
    vector<int> dp(n, 1);       
    vector<int> prev(n, -1);   
    int maxSize = 0;            
    int maxIndex = -1;          

    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < i; ++j) {
            if (nums[i] % nums[j] == 0 && dp[j] + 1 > dp[i]) {
                dp[i] = dp[j] + 1;
                prev[i] = j;
            }
        }
        if (dp[i] > maxSize) {
            maxSize = dp[i];
            maxIndex = i;
        }
    }

    vector<int> result;
    for (int i = maxIndex; i >= 0; i = prev[i]) {
        result.push_back(nums[i]);
        if (prev[i] == i) break; 
    }

    reverse(result.begin(), result.end());
    return result;
    }
};