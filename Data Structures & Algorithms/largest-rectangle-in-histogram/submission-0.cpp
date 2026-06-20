class Solution {
public:
    int largestRectangleArea(vector<int>& heights) {
        //find next smaller element from L->R to R->L

        vector<int> NSE_L(heights.size());
        vector<int> NSE_R(heights.size());
        stack<int> stackR;
        stack<int> stackL;
        
        //Right Side
        for(int i=heights.size()-1;i>=0;i--) {
            while(!stackR.empty() && heights[stackR.top()] >= heights[i]) stackR.pop();

            if(stackR.empty()) NSE_R[i] = heights.size();
            else NSE_R[i] = stackR.top();

            stackR.push(i);
        }

        //Left Side
        for(int i=0;i<heights.size();i++) {
            while(!stackL.empty() && heights[stackL.top()] >= heights[i]) stackL.pop();

            if(stackL.empty()) NSE_L[i] = -1;
            else NSE_L[i] = stackL.top();

            stackL.push(i);
        }
        int ans = 0;
        for(int k = 0; k<heights.size(); k++) {
            int width = NSE_R[k] - NSE_L[k] - 1;
            int area = width * heights[k]; // 실제 면적
            
            if (ans < area) {
                ans = area;
            }
        }

        return ans;
    }
};
