//  this is question must be solve using the two pointer app. it is specially for that only 

class Solution {
public:
    bool isPalindrome(string s) {
        int r = s.length() - 1;

        // Initialize 'l' in the loop, check boundary, omit the standard auto-increment
        for (int l = 0; l < r; ) {
            
            if (!isalnum(s[l])) {
                l++;
                continue; // Restart loop to re-evaluate the condition
            }
            
            if (!isalnum(s[r])) {
                r--;
                continue; // Restart loop to re-evaluate the condition
            }
            
            if (tolower(s[l]) != tolower(s[r])) {
                return false;
            }
            
            l++;
            r--;
        }
        
        return true;
    }
};