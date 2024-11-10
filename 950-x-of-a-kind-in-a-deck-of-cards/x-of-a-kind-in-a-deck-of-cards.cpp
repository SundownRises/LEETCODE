class Solution {
public:
int gcd(int a, int b) {
    return b == 0 ? a : gcd(b, a % b);
}

bool hasGroupsSizeX(vector<int>& deck) {
    unordered_map<int, int> freqMap;
    
    for (int card : deck) {
        freqMap[card]++;
    }
    
    int groupSize = 0;
    for (const auto& entry : freqMap) {
        groupSize = gcd(groupSize, entry.second);
        if (groupSize == 1) return false;  
    }
    
    return groupSize > 1;
    }
};