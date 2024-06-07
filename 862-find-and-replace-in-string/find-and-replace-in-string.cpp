class Solution {
public:
    string findReplaceString(string s, vector<int>& indices, vector<string>& sources, vector<string>& targets) {
    vector<tuple<int, string, string>> replacements;
    for (int i = 0; i < indices.size(); ++i) {
        replacements.emplace_back(indices[i], sources[i], targets[i]);
    }
    
    sort(replacements.rbegin(), replacements.rend());
    
    for (auto& replacement : replacements) {
        int index = get<0>(replacement);
        string source = get<1>(replacement);
        string target = get<2>(replacement);
        
        if (s.substr(index, source.length()) == source) {
            s = s.substr(0, index) + target + s.substr(index + source.length());
        }
    }
    
    return s;

    }
};