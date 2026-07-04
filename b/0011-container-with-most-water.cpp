class Solution {
public:
    int maxArea(vector<int>& height) {
        int i = 0;
        int j = height.size() - 1;
        int max_area = 0;
        
        while (i < j) {
            int h = min(height[i], height[j]);
            int w = j - i;
            int ans = h * w;
            max_area = max(max_area, ans);
            
            if (height[i] < height[j]) {
                i += 1;  
            } else {
                j -= 1;  
            }
        }
        
        return max_area;
    }
};