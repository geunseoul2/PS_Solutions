class Solution {
public:
    vector<int> productExceptSelf(vector<int>& nums) {
        //optimal solution using prefix and suffix, but not using extra array to store them.
        int n = nums.size();
        vector<int> res(n, 1);

        for (int i = 1; i < n; i++) {
            res[i] = res[i - 1] * nums[i - 1];
        }
        
        for (int i = 0; i < n; i++) {
            cout << res[i] << " ";
        }
        cout << endl;


        int postfix = 1;
        for (int i = n - 1; i >= 0; i--) {
            res[i] *= postfix;
            postfix *= nums[i];
        }

        for (int i = 0; i < n; i++) {
            cout << res[i] << " ";
        }
        cout << endl;
        return res;
    }
};