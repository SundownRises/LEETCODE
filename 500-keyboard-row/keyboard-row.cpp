class Solution {
public:
    vector<string> findWords(vector<string>& words) {
            string row1 = "qwertyuiop";
    string row2 = "asdfghjkl";
    string row3 = "zxcvbnm";

    unordered_map<char, int> charToRow;
    for (char c : row1) charToRow[c] = 1;
    for (char c : row2) charToRow[c] = 2;
    for (char c : row3) charToRow[c] = 3;

    vector<string> result;

    for (string word : words) {
        int row = charToRow[tolower(word[0])];
        bool isValid = true;

        for (char c : word) {
            if (charToRow[tolower(c)] != row) {
                isValid = false;
                break;
            }
        }

        if (isValid) {
            result.push_back(word);
        }
    }

    return result;
    }
};