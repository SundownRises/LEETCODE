class Solution {
public:
    int maxOperations(vector<int>& nums, int k) {
                unordered_map<int, int> numCounts;
        int operations = 0;
        
        for (int num : nums) {
            int complement = k - num;
            if (numCounts[complement] > 0) {
                operations++;
                numCounts[complement]--;
            } else {
                numCounts[num]++;
            }
        }
        
        return operations;
    }
};