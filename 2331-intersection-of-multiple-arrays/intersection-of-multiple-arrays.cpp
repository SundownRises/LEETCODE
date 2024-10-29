class Solution {
public:
    vector<int> intersection(vector<vector<int>>& nums) {
            int n = nums.size();
    unordered_map<int, int> freqMap;

    for (const auto& array : nums) {
        for (int num : array) {
            freqMap[num]++;
        }
    }

    vector<int> result;
    for (const auto& [num, count] : freqMap) {
        if (count == n) {
            result.push_back(num);
        }
    }

    sort(result.begin(), result.end());
    return result;
    }
};