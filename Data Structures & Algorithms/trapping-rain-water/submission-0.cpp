class Solution {
public:
    int trap(vector<int>& height) {
        stack<int> stk;
        vector<int> nge(height.size());
        int ans = 0;

        //find the nearest greater element (L->R)
        for(int i=height.size()-1;i>=0;i--) {
            while(!stk.empty() && height[stk.top()] < height[i]) stk.pop();

            if(stk.empty()) nge[i] = -1;
            else {
                nge[i] = stk.top();
            }

            stk.push(i);
        }  
        for(auto x : nge) cout << x;
        cout << endl;

        int i = 0;

        while(i < height.size()) {
            if(nge[i] > -1) {
                for(int j=0;j<nge[i]-i;j++) {
                    ans += (height[i] - height[j]);
                    cout << (height[i] - height[j]);
                }
                cout << endl;
                i = nge[i];
            }
            else {
                break;
            }
        }

        return ans;
    }
};
