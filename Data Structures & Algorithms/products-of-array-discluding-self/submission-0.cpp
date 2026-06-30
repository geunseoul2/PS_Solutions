class Solution {
public:
    vector<int> productExceptSelf(vector<int>& nums) {
        //simple solution is O(n^2)

        //use prefix, suffix product array
        vector<int> prefix,suffix, ans;
        prefix.push_back(nums[0]);
        suffix.push_back(nums[nums.size()-1]);

        for(int i=1;i<nums.size();i++) {
            prefix.push_back(prefix[i-1] * nums[i]);
            suffix.push_back(suffix[i-1] * nums[nums.size()-1-i]);
        }

        ans.push_back(suffix[nums.size()-1]);
        for(int j=1;j<nums.size()-1;j++) {
            cout << prefix[j-1] << " " << suffix[nums.size()-2-j] << endl;
            ans.push_back(prefix[j-1] * suffix[nums.size()-2-j]);
        }
        ans.push_back(prefix[nums.size()-2]);

        for(int j=0;j<nums.size();j++) {
            cout << prefix[j] << " : " << suffix[j] << endl;
        }
        return ans;

    }
};
