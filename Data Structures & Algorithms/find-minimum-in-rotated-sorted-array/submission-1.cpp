class Solution {
public:
    int findMin(vector<int> &nums) {
        int l = 0, r = nums.size()-1;

        while(l < r) {
            int m = l + ((r-l)/2);

            if(nums[m] > nums[r]) { //partition is lm/r
                l = m + 1;  
            } else if(nums[m] < nums[r]) { //partition is l/mr
                r = m;
            } else { //not partitioned
                return nums[l];
            }
        }

        return nums[l];
    }
};
