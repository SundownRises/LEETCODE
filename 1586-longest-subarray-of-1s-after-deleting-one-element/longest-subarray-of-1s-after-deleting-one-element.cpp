class Solution {
public:
    int longestSubarray(vector<int>& nums) {
        int left = 0, right = 0, zeroCount = 0, maxLen = 0;

        for (right = 0; right < nums.size(); ++right) {
            if (nums[right] == 0) {
                zeroCount++;
            }

            while (zeroCount > 1) {
                if (nums[left] == 0) {
                    zeroCount--;
                }
                left++;
            }

            maxLen = max(maxLen, right - left);
        }

        return maxLen;
    }
};