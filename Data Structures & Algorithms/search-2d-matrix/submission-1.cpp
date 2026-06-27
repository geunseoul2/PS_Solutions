class Solution {
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        int top = 0, bottom = matrix.size()-1;

        int left = 0, right = matrix[0].size()-1;

        while(top <= bottom) {
            int mid = top + ((bottom-top)/2);
            cout << mid << endl;
            if(target < matrix[mid][0]) bottom = mid - 1;
            else if(target <= matrix[mid][right]) {
                while(left <= right) {
                    int m = left + ((right - left)/2);
                    if(matrix[mid][m] < target) left = m + 1;
                    else if(matrix[mid][m] > target) right = m - 1;
                    else return true;
                }

                return false;
            } else top = mid + 1;
        }

        return false;
    }
};
