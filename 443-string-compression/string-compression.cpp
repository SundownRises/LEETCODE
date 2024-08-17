class Solution {
public:
    int compress(vector<char>& chars) {
        int write_index = 0;
        int i = 0; 
        while (i < chars.size()) {
            char current_char = chars[i];
            int count = 0;
            
            while (i < chars.size() && chars[i] == current_char) {
                i++;
                count++;
            }
            
            chars[write_index++] = current_char;
            
            if (count > 1) {
                string count_str = to_string(count);
                for (char c : count_str) {
                    chars[write_index++] = c;
                }
            }
        }
        
        return write_index;
    }
};