class Solution {
public:
    bool uniqueOccurrences(vector<int>& arr) {
    unordered_map<int, int> freqMap;
    unordered_set<int> occurrences;

    for (int num : arr) {
        freqMap[num]++;
    }

    for (const auto& entry : freqMap) {
        if (occurrences.find(entry.second) != occurrences.end()) {
            return false;
        }
        occurrences.insert(entry.second);
    }

    return true;

    }
};