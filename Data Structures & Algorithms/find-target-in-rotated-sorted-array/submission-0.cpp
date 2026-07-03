class Solution {
public:
    int search(vector<int>& nums, int target) {
        int l = 0, r = nums.size()-1;

        while(l < r) {
            int m = l + ((r-l)/2);

            if(nums[m] > nums[r]) { //partition is lm/r
                l = m + 1;  
            } else if(nums[m] < nums[r]) { //partition is l/mr
                r = m;
            } else { //not partitioned
                break;
            }
        }
        //l is the cut

        //do binary search in 2 segments

        int leftL = 0, leftR = 0;
        if(l != 0) leftR = l - 1;
        r = nums.size()-1;
        //leftL = 0, leftR = l - 1 / l = rightL r = rightR
        // cout << leftL << " " << leftR << " " << l << " " << r << endl;
        
        //do binary search on each segment

        while(leftL <= leftR) {
            int m = leftL + ((leftR - leftL)/2);

            if(nums[m] > target) leftR = m-1;
            else if(nums[m] < target) leftL = m+1;
            else return m;
        }
        while(l <= r) {
            int m = l + ((r-l)/2);
            
            if(nums[m] > target) r = m-1;
            else if(nums[m]<target) l = m+1;
            else return m;
        }

        return -1;
        
    }
};
