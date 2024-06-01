class Solution {
public:
    int lengthOfLIS(vector<int>& heights) {
    vector<int> lis;
    for (int height : heights) {
        auto it = lower_bound(lis.begin(), lis.end(), height);
        if (it == lis.end()) {
            lis.push_back(height);
        } else {
            *it = height;
        }
    }
    return lis.size();
}
    int maxEnvelopes(vector<vector<int>>& envelopes) {
    sort(envelopes.begin(), envelopes.end(), [](const vector<int>& a, const vector<int>& b) {
        if (a[0] == b[0]) {
            return a[1] > b[1];
        } else {
            return a[0] < b[0];
        }
    });
        vector<int> heights;
    for (const auto& envelope : envelopes) {
        heights.push_back(envelope[1]);
    }

    return lengthOfLIS(heights);
}

    
};