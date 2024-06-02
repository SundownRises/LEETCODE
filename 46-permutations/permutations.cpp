class Solution {
public:
    void backtrack(int first, vector<int>& nums, vector<vector<int>>& result) {
        if (first == nums.size()) {
            result.push_back(nums);
            return;
        }
        for (int i = first; i < nums.size(); ++i) {
            swap(nums[first], nums[i]); 
            backtrack(first + 1, nums, result); 
            swap(nums[first], nums[i]);
        }
    }
    vector<vector<int>> permute(vector<int>& nums) {
        vector<vector<int>> result;
        backtrack(0, nums, result);
        return result;
    }
};
    
