class Solution {
public:
    string frequencySort(string s) {
    unordered_map<char, int> freq;
    for (char c : s) {
        freq[c]++;
    }
    
    vector<pair<int, char>> freqVec;
    for (auto& it : freq) {
        freqVec.push_back({it.second, it.first});
    }

    sort(freqVec.rbegin(), freqVec.rend());

    string result;
    for (auto& it : freqVec) {
        result.append(it.first, it.second);
    }

    return result;

    }
};