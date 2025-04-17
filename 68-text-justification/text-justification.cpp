class Solution {
public:
    vector<string> fullJustify(vector<string>& words, int maxWidth) {
        vector<string> result;
        int i = 0, n = words.size();

        while (i < n) {
            int j = i, lineLength = 0;
            while (j < n && lineLength + words[j].size() + (j - i) <= maxWidth) {
                lineLength += words[j].size();
                ++j;
            }

            int spaceSlots = j - i - 1;
            string line;

            if (j == n || spaceSlots == 0) {
                for (int k = i; k < j; ++k) {
                    line += words[k];
                    if (k < j - 1) line += ' ';
                }
                line += string(maxWidth - line.size(), ' ');
            } else {
                int totalSpaces = maxWidth - lineLength;
                int spacePerSlot = totalSpaces / spaceSlots;
                int extraSpaces = totalSpaces % spaceSlots;

                for (int k = i; k < j; ++k) {
                    line += words[k];
                    if (k < j - 1) {
                        line += string(spacePerSlot + (extraSpaces-- > 0 ? 1 : 0), ' ');
                    }
                }
            }

            result.push_back(line);
            i = j;
        }

        return result;
    }
};