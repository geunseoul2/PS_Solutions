class Solution {
public:
    vector<vector<int>> ans;

    vector<vector<int>> combinationSum2(vector<int>& nums, int target) {
        vector<int> curr;
        sort(nums.begin(),nums.end());
        backtrack(nums,target,curr,0);
        return ans;
    }

    void backtrack(vector<int>& nums, int target, vector<int>& curr, int i) {
        if(target == 0) {
            ans.push_back(curr);
            return;
        }
        if(target < 0 || i >= nums.size()) return;

        curr.push_back(nums[i]);
        backtrack(nums,target-nums[i],curr,i+1);
        curr.pop_back();
        while(i < nums.size() - 1 && nums[i] == nums[i+1]) i++;
        backtrack(nums,target,curr,i+1);
    }
};
