class Solution {
public:
    int maxArea(int h, int w, vector<int>& horizontalCuts, vector<int>& verticalCuts) {
    const int MOD = 1e9 + 7;

    sort(horizontalCuts.begin(), horizontalCuts.end());
    sort(verticalCuts.begin(), verticalCuts.end());

    int maxHGap = max(horizontalCuts[0], h - horizontalCuts.back());
    for (int i = 1; i < horizontalCuts.size(); ++i) {
        maxHGap = max(maxHGap, horizontalCuts[i] - horizontalCuts[i - 1]);
    }

    int maxVGap = max(verticalCuts[0], w - verticalCuts.back());
    for (int i = 1; i < verticalCuts.size(); ++i) {
        maxVGap = max(maxVGap, verticalCuts[i] - verticalCuts[i - 1]);
    }

    long long maxArea = (long long) maxHGap * maxVGap;
    return maxArea % MOD;

    }
};