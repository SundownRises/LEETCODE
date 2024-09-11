class Solution {
public:
    vector<int> fairCandySwap(vector<int>& aliceSizes, vector<int>& bobSizes) {
    int sumAlice = 0, sumBob = 0;
    for (int candy : aliceSizes) {
        sumAlice += candy;
    }
    for (int candy : bobSizes) {
        sumBob += candy;
    }

    int diff = (sumAlice - sumBob) / 2;

    unordered_set<int> bobSet(bobSizes.begin(), bobSizes.end());

    for (int x : aliceSizes) {
        if (bobSet.count(x - diff)) {
            return {x, x - diff};
        }
    }
 
    return {};
}


    };
