class Solution {
public:
    bool detectCapitalUse(string word) {
    bool allUpper = true;
    bool allLower = true;
    bool firstUpperRestLower = isupper(word[0]);

    for (int i = 0; i < word.length(); ++i) {
        if (!isupper(word[i])) allUpper = false;
        if (!islower(word[i])) allLower = false;
        if (i > 0 && isupper(word[i])) firstUpperRestLower = false;
    }

    return allUpper || allLower || firstUpperRestLower; 
    }
};