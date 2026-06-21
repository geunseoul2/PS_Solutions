class Solution {
public:
    bool isPalindrome(string s) {
        transform(s.begin(), s.end(), s.begin(), ::tolower);
        
        int left = 0;
        int right = s.size() - 1;

        while (left < right) {
            
            while (left < right && 
                  !(s.at(left) >= 97 && s.at(left) <= 122) && 
                  !(s.at(left) >= 48 && s.at(left) <= 57)) {
                left++;
            }
            while (left < right && 
                  !(s.at(right) >= 97 && s.at(right) <= 122) && 
                  !(s.at(right) >= 48 && s.at(right) <= 57)) {
                right--;
            }
            
            if (s.at(left) != s.at(right)) {
                return false;
            }
            left++;
            right--;
        }
        
        return true;
    }
};