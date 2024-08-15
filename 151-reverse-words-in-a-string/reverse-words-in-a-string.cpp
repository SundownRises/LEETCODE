class Solution {
public:
    string reverseWords(string s) {
        int left = 0, right = s.length() - 1;
        while (left <= right && s[left] == ' ') left++;
        while (right >= left && s[right] == ' ') right--;
        
        vector<string> words;
        string word;
        while (left <= right) {
            char c = s[left];
            if (c != ' ') {
                word += c;
            } else if (!word.empty()) {
                words.push_back(word);
                word.clear();
            }
            left++;
        }
        if (!word.empty()) {
            words.push_back(word);
        }

        reverse(words.begin(), words.end());

        stringstream result;
        for (int i = 0; i < words.size(); i++) {
            if (i > 0) result << " ";
            result << words[i];
        }

        return result.str();
    }


    
};