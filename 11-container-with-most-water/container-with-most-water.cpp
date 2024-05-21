class Solution {
public:
    int maxArea(vector<int>& height) {
        int start = 0;
        int end = height.size() - 1;
        int area = 0;

        while (start < end) {
            int current_area = min(height[start], height[end]) * (end - start);
            area = max(area, current_area);

            if (height[start] < height[end]) {
                start++;
            } else {
                end--;
            }
        }

        return area;
    }
};