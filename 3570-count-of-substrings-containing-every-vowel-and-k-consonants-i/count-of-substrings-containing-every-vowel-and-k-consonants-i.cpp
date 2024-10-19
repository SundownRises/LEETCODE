class Solution {
public:
bool isVowel(char c) {
    return c == 'a' || c == 'e' || c == 'i' || c == 'o' || c == 'u';
}

    int countOfSubstrings(string word, int k) {
        
    int n = word.length();
    int result = 0;
    
    for (int start = 0; start <= n - 5; ++start) {
        unordered_set<char> vowels;
        int consonants = 0;
        
        for (int end = start; end < n; ++end) {
            if (isVowel(word[end])) {
                vowels.insert(word[end]);
            } else {
                consonants++;
            }
            
            if (vowels.size() == 5 && consonants == k) {
                result++;
            }
            
            if (consonants > k) break;
        }
    }
    
    return result;
    }
};