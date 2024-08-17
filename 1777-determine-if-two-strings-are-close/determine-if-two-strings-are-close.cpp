class Solution {
public:
    bool closeStrings(string word1, string word2) {
                if (word1.size() != word2.size()) {
            return false;
        }
        
        unordered_map<char, int> freq1, freq2;
        unordered_set<char> unique1, unique2;
        
        for (char c : word1) {
            freq1[c]++;
            unique1.insert(c);
        }
        
        for (char c : word2) {
            freq2[c]++;
            unique2.insert(c);
        }
        
        if (unique1 != unique2) {
            return false;
        }
        
        vector<int> freqVec1, freqVec2;
        for (auto& p : freq1) {
            freqVec1.push_back(p.second);
        }
        for (auto& p : freq2) {
            freqVec2.push_back(p.second);
        }
        
        sort(freqVec1.begin(), freqVec1.end());
        sort(freqVec2.begin(), freqVec2.end());
        
        return freqVec1 == freqVec2;
    
    }
};