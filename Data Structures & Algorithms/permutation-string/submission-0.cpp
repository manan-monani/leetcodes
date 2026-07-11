class Solution {
public:
    bool checkInclusion(string s1, string s2) {
        int n1 = s1.length();
        int n2 = s2.length();
        
        // Base case: if s1 is longer than s2, s2 cannot contain its permutation
        if (n1 > n2) return false;
        
        // Frequency arrays for 'a' through 'z'
        vector<int> count1(26, 0);
        vector<int> count2(26, 0);
        
        // 1. Populate the target frequency (s1) and the first window of s2
        for (int i = 0; i < n1; i++) {
            count1[s1[i] - 'a']++;
            count2[s2[i] - 'a']++;
        }
        
        // If the first window matches, we are done
        if (count1 == count2) return true;
        
        // 2. Slide the window across s2
        // 'i' represents the character entering the window
        for (int i = n1; i < n2; i++) {
            // Add the new character to the right of the window
            count2[s2[i] - 'a']++;
            
            // Remove the old character from the left of the window
            count2[s2[i - n1] - 'a']--;
            
            // Check if the current window matches s1's frequencies
            if (count1 == count2) return true;
        }
        
        return false;
    }
};