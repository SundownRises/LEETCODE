class Solution {
public:
    int rob(vector<int>& nums) {
        int n = nums.size();

        int maxi = 0;
        int rob = nums[0];

        for (int i = 1; i < n; i++) {
            int curr = max(nums[i] + maxi, rob);
            maxi = rob;
            rob = curr;
        }

        return rob;
    }
};
