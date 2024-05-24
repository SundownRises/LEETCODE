class Solution {
public:
    void moveZeroes(vector<int>& nums) {

    int last_non_zero_found_at = 0;

    for (int i = 0; i < nums.size(); ++i) {
        if (nums[i] != 0) {
            nums[last_non_zero_found_at++] = nums[i];
        }
    }

    for (int i = last_non_zero_found_at; i < nums.size(); ++i) {
        nums[i] = 0;
    }
}


    
};