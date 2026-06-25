class Solution {
public:
    int maxArea(vector<int>& heights) {
        int ans = 0;

        for(int i=0;i<heights.size();i++) {
            for(int j=i+1;j<heights.size();j++) {
                int water = min(heights[i],heights[j]) * (j-i);

                if(ans < water) ans = water;
            }
        }

        return ans;
    }
};
