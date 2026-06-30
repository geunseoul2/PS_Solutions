class Solution {
public:
    int minEatingSpeed(vector<int>& piles, int h) {
        
        int max = *max_element(piles.begin(),piles.end());
        int min = 1;
        int mid = min + ((max-min)/2);

        while(min <= max) {
            
            int hour = 0;
            for(auto x: piles) hour += ceil((double)x/mid);
            if(h < hour) min = mid + 1;
            else if(h > hour) max = mid - 1;
            else return mid;
            mid = min + ((max-min)/2);
        }

        return mid;

    }
};
