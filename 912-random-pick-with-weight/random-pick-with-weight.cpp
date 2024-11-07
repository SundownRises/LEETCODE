class Solution {
public:
    vector<int> prefixSums;
    int totalWeight;
    Solution(vector<int>& w) {
        prefixSums.resize(w.size());
        prefixSums[0] = w[0];
        for (int i = 1; i < w.size(); ++i) {
            prefixSums[i] = prefixSums[i - 1] + w[i];
        }
        totalWeight = prefixSums.back();

    }
    
    int pickIndex() {
        int randomWeight = rand() % totalWeight + 1;
        // Binary search to find the right index
        int left = 0, right = prefixSums.size() - 1;
        while (left < right) {
            int mid = left + (right - left) / 2;
            if (prefixSums[mid] < randomWeight) {
                left = mid + 1;
            } else {
                right = mid;
            }
        }
        return left;
    }
};

/**
 * Your Solution object will be instantiated and called as such:
 * Solution* obj = new Solution(w);
 * int param_1 = obj->pickIndex();
 */