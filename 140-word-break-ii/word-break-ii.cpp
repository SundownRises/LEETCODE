class Solution {
public:
    unordered_map<string, vector<string> > memo;
    vector<string> solve(string s, unordered_set<string> &dict) {
        if (memo.find(s) != memo.end()) {
            return memo[s];
        }
        vector<string> result;
        if (dict.find(s) != dict.end()) {
            result.push_back(s);
        }
        int n = s.length();
        for (int i = 1; i < n; i++) {
            string left = s.substr(0, i);
            string right = s.substr(i);
            if (dict.find(left) != dict.end()) {
                vector<string> rightResult = solve(right, dict);
                for (int j = 0; j < rightResult.size(); j++) {
                    string sentence = left + " " + rightResult[j];
                    result.push_back(sentence);
                }
            }
        }
        memo[s] = result;
        return result;
    }
    vector<string> wordBreak(string s, vector<string>& wordDict) {
                unordered_set<string> dict;
        for (int i = 0; i < wordDict.size(); i++) {
            dict.insert(wordDict[i]);
        }
        return solve(s, dict);
    }
};