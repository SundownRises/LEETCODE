class Solution {
public:
    int findLHS(vector<int>& nums) {
        unordered_map<int, int> count;
        for (int num : nums) {
            count[num]++;
        }
        
        int maxLen = 0;
        for (auto it = count.begin(); it != count.end(); ++it) {
            if (count.find(it->first + 1) != count.end()) {
                maxLen = max(maxLen, it->second + count[it->first + 1]);
            }
        }
        
        return maxLen;
    }
};
