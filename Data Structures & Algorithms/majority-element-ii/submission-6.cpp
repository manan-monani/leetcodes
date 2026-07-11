class Solution {
public:
    vector<int> majorityElement(vector<int>& nums) {
        // Step 1: Sort to group identical numbers together
        sort(nums.begin(), nums.end());
        
        vector<int> res;
        int n = nums.size();
        int threshold = n / 3;
        
        // Start counting the first element
        int count = 1; 

        for (int i = 1; i < n; i++) {
            if (nums[i] == nums[i - 1]) {
                // Same number as yesterday? Increment the streak.
                count++;
            } else {
                // New number spotted! First, check if the old streak won.
                if (count > threshold) {
                    res.push_back(nums[i - 1]);
                }
                // Reset the streak counter for the new number
                count = 1; 
            }
        }

        // Edge Case: Check the very last group after the loop finishes
        if (count > threshold) {
            res.push_back(nums[n - 1]);
        }

        return res;
    }
};