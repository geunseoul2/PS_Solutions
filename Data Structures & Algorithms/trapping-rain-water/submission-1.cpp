class Solution {
public:
    //use two pointer?
    int trap(vector<int>& height) {
        int left = 0;
        int right = height.size()-1;
        int ans = 0;

        while(left < right) {
            if(height[left] < height[right]) {
                for(int i=left; i<right; i++) {
                    if(height[left]-height[i] > 0) {
                        ans += height[left]-height[i];
                        height[i] += height[left]-height[i];
                    }
                }

                left++;
            } else if(height[left] >= height[right]) {
                for(int i=left; i<right; i++) {
                    if(height[right]-height[i] > 0) {
                        ans += height[right]-height[i];
                        height[i] += height[right]-height[i];
                    }
                }

                right--;
            }
        }

        return ans;
    }
};
