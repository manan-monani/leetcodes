class Solution {
public:
    bool isPalindrome(string s) {
        int r = s.length() - 1;

        for (int l = 0; l < r; ) {
            // FIX 1: Add '!' to skip when character is NOT alphanumeric
            if (!isalnum(s[l])) {
                l++;
                continue; 
            }
            
            // FIX 1: Add '!' here as well
            if (!isalnum(s[r])) {
                r--;
                continue; 
            }
            
            // FIX 2: Wrapped in brackets or kept clean if it returns early
            if (tolower(s[l]) != tolower(s[r])) {
                return false;
            }
            
            // Both pointers advance only when a successful match is confirmed
            l++;
            r--;
        }
        return true;   
    }
};