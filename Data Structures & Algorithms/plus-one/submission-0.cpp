class Solution {
public:
    vector<int> plusOne(vector<int>& digits) {
        if(digits.size() == 0) return {};
        reverse(digits.begin(), digits.end());
        int over = 0;
        digits[0]++;

        for(int i=0;i<digits.size();i++) {
            if(over) digits[i]++;
            if(digits[i] > 9){
                if(i == digits.size()-1) digits.push_back(0);
                over = 1;
                digits[i] = digits[i] % 10;
            } else {
                over = 0;
            }
        }

        reverse(digits.begin(), digits.end());
        return digits;
    }
};
