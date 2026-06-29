class Solution {
public:
    int minEatingSpeed(vector<int>& piles, int h) {
        
        int max = *max_element(piles.begin(),piles.end());
        int min = 1;
        int res = max;

        while(min <= max) {
            int mid = min + ((max-min)/2);
            int hour = 0;
            for(auto x: piles) hour += ceil((double)x/mid);
            if(hour <= h) {
                res = mid;
                max = mid - 1;
            } else min = mid + 1;
            
        }

        return res;

    }
};