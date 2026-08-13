class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
        unordered_map<int, int> freq;

        for (int num : nums) {
            freq[num]++;
        }

        vector<pair<int, int>> freqList(freq.begin(), freq.end());

        sort(freqList.begin(), freqList.end(), [](pair<int,int>& a, pair<int,int>& b) {
            return a.second < b.second;
        });

        vector<int> result;
        for (int i = freqList.size() - 1; i >= (int)freqList.size() - k; i--) {
            result.push_back(freqList[i].first);
        }

        return result;
    }
};
